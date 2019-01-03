// https://leetcode.com/problems/binary-tree-cameras

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef unordered_map<TreeNode*, int> DP_MAP;

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        DP_MAP dpHasCamera, dpCoveredByParent, dpNone;
        return min(calcHasCamera(root, dpHasCamera, dpCoveredByParent, dpNone),
                   calcNone(root, dpHasCamera, dpCoveredByParent, dpNone));
    }

private:
    int calcHasCamera(TreeNode* root, DP_MAP& dpHasCamera, DP_MAP& dpCoveredByParent, DP_MAP& dpNone) {
        auto it = dpHasCamera.find(root);
        if (it != dpHasCamera.end()) {
            return it->second;
        }

        int left = 0, right = 0;
        if (root->left) {
            left = INT_MAX;
            left = min(left, calcHasCamera(root->left, dpHasCamera, dpCoveredByParent, dpNone));
            left = min(left, calcCoveredByParent(root->left, dpHasCamera, dpCoveredByParent, dpNone));
            //left = min(left, calcNone(root->left, dpHasCamera, dpCoveredByParent, dpNone));
        }

        if (root->right) {
            right = INT_MAX;
            right = min(right, calcHasCamera(root->right, dpHasCamera, dpCoveredByParent, dpNone));
            right = min(right, calcCoveredByParent(root->right, dpHasCamera, dpCoveredByParent, dpNone));
            //right = min(right, calcNone(root->right, dpHasCamera, dpCoveredByParent, dpNone));
        }

        int ret = (left == INT_MAX || right == INT_MAX) ? INT_MAX : (left + right + 1);
        //printf("dpHasCamera[%d] = %d\n", root->val, ret);
        dpHasCamera[root] = ret;
        return ret;
    }

    int calcCoveredByParent(TreeNode* root, DP_MAP& dpHasCamera, DP_MAP& dpCoveredByParent, DP_MAP& dpNone) {
        auto it = dpCoveredByParent.find(root);
        if (it != dpCoveredByParent.end()) {
            return it->second;
        }

        int left = 0, right = 0;
        if (root->left) {
            left = INT_MAX;
            left = min(left, calcHasCamera(root->left, dpHasCamera, dpCoveredByParent, dpNone));
            left = min(left, calcNone(root->left, dpHasCamera, dpCoveredByParent, dpNone));
        }

        if (root->right) {
            right = INT_MAX;
            right = min(right, calcHasCamera(root->right, dpHasCamera, dpCoveredByParent, dpNone));
            right = min(right, calcNone(root->right, dpHasCamera, dpCoveredByParent, dpNone));
        }

        int ret = (left == INT_MAX || right == INT_MAX) ? INT_MAX : (left + right);
        //printf("dpCoveredByParent[%d] = %d\n", root->val, ret);
        dpCoveredByParent[root] = ret;
        return ret;
    }

    int calcNone(TreeNode* root, DP_MAP& dpHasCamera, DP_MAP& dpCoveredByParent, DP_MAP& dpNone) {
        auto it = dpNone.find(root);
        if (it != dpNone.end()) {
            return it->second;
        }

        int left = INT_MAX, leftHasCamera = INT_MAX, right = INT_MAX, rightHasCamera = INT_MAX;
        if (root->left) {
            leftHasCamera = calcHasCamera(root->left, dpHasCamera, dpCoveredByParent, dpNone);
            left = min(left, leftHasCamera);
            left = min(left, calcNone(root->left, dpHasCamera, dpCoveredByParent, dpNone));
        } else {
            left = 0;
        }

        if (root->right) {
            rightHasCamera = calcHasCamera(root->right, dpHasCamera, dpCoveredByParent, dpNone);
            right = min(right, rightHasCamera);
            right = min(right, calcNone(root->right, dpHasCamera, dpCoveredByParent, dpNone));
        } else {
            right = 0;
        }


        int cand1 = (leftHasCamera == INT_MAX || right == INT_MAX) ? INT_MAX : (leftHasCamera + right);
        int cand2 = (left == INT_MAX || rightHasCamera == INT_MAX) ? INT_MAX : (left + rightHasCamera);
        int ret = min(cand1, cand2);
        //printf("dpNone[%d] = %d\n", root->val, ret);
        dpNone[root] = ret;
        return ret;
    }
};
