// https://leetcode.com/problems/redundant-connection-ii/description/

// In a rooted tree, the root has no incoming edge, and every other vertex has exactly one incoming edge.
// With one extra edge added, the resulting directed graph G = (V, E) has the property that |V| = |E| = n.
// There are hence 3 possible cases: 
// - G has a self-loop, which can be detected easily.
// - Every vertex has a parent. Thus there must be a loop containing the root vertex of the underlying tree.
//   In this case, as long as the loop is known, any edge in the loop can be removed so that the remaining
//   edges forms a rooted tree.
// - Only one vertex has no parent (which is the only possible root). Thus there must be one vertex v which
//   has 2 parents x, y.
//   * If x, y can be both tracked upwards to the root, either of edges (x, v) and (y, v) can be removed
//     for the rest to form a rooted tree.
//   * If only one of x, y can be tracked upwords to the root. Say it's x. Then (y, v) should be removed to
//     removed a existing loop.
// The following solution runs in O(n) time.

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int vertNum = edges.size();
        
        // Element at index i will record the first inward edge of vertex i + 1, if any.
        auto inwardEdgeIndices = vector<int>(vertNum, -1);
        
        // How many vertices have a parent.
        int vertNumHavingParent = 0;
        
        // The vertex that has two parents, if any.
        int vertHaving2Parents = 0;
        
        // The second inward edge of 'vertHaving2Parents', if any.
        int secondInwardEdgeIndex = -1;
        
        // The vertex that makes a self loop, if any.
        int selfLoopVert = 0;
        
        processInput(edges, inwardEdgeIndices,
                    vertNumHavingParent, vertHaving2Parents, secondInwardEdgeIndex, selfLoopVert);
        
        vector<int> ret;
        if (selfLoopVert > 0) {
            ret = makeEdge(selfLoopVert, selfLoopVert);
        } else if (vertNumHavingParent == vertNum) {
            ret = tackleLoopContainingRoot(edges, inwardEdgeIndices);
        } else {
            ret = tackleVertHaving2Parents(edges, inwardEdgeIndices, vertHaving2Parents, secondInwardEdgeIndex);
        }
        
        return ret;
    }

private:
    void processInput(const vector<vector<int>>& edges, vector<int>& inwardEdgeIndices,
                     int& vertNumHavingParent, int& vertHaving2Parents, int& secondInwardEdgeIndex, int &selfLoopVert) {
        for (int i = 0; i < edges.size(); i++) {
            int src = edges[i][0];
            int dst = edges[i][1];
            if (src == dst) {
                selfLoopVert = dst;
                break;
            }
            
            if (inwardEdgeIndices[dst - 1] < 0) {
                vertNumHavingParent++;
                inwardEdgeIndices[dst - 1] = i;
            } else {
                vertHaving2Parents = dst;
                secondInwardEdgeIndex = i;
            }
        }
    }
    
    vector<int> tackleVertHaving2Parents(const vector<vector<int>>& edges, const vector<int>& inwardEdgeIndices,
                                        int vertHaving2Parents, int secondInwardEdgeIndex) {
        int root = 0;
        for (int i = 0; i < edges.size(); i++) {
            if (inwardEdgeIndices[i] < 0) {
                root = i + 1;
                break;
            }
        }
        
        int currentVert = getParentVert(vertHaving2Parents, edges, inwardEdgeIndices);
        while (currentVert != vertHaving2Parents && currentVert != root) {
            currentVert = getParentVert(currentVert, edges, inwardEdgeIndices);
        }
        
        int src = currentVert == root
            ? edges[secondInwardEdgeIndex][0]
            : getParentVert(vertHaving2Parents, edges, inwardEdgeIndices);
        return makeEdge(src, vertHaving2Parents);
    }
    
    vector<int> tackleLoopContainingRoot(const vector<vector<int>>& edges, const vector<int>& inwardEdgeIndices) {
        auto visitFlags = vector<bool>(edges.size());
        int currentVert = edges[0][1];
        while (true) {
            if (visitFlags[currentVert - 1]) {
                break;
            }
            visitFlags[currentVert - 1] = true;
            currentVert = getParentVert(currentVert, edges, inwardEdgeIndices);
        }

        int startVert = currentVert;
        int maxEdgeIndex = -1;
        do {
            if (inwardEdgeIndices[currentVert - 1] > maxEdgeIndex) {
                maxEdgeIndex = inwardEdgeIndices[currentVert - 1];
            }
            currentVert = getParentVert(currentVert, edges, inwardEdgeIndices);
        } while (currentVert != startVert);
        return makeEdge(edges[maxEdgeIndex][0], edges[maxEdgeIndex][1]);
    }
    
    inline int getParentVert(int vert, const vector<vector<int>>& edges, const vector<int>& inwardEdgeIndices) {
        return edges[inwardEdgeIndices[vert - 1]][0];
    }
    
    inline vector<int> makeEdge(int src, int dst) {
        auto ret = vector<int>(2);
        ret[0] = src;
        ret[1] = dst;
        return ret;
    }
};
