#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height <= 0) return 0;
        
        int width = matrix[0].size();
        if (width <= 0) return 0;
        
        vector<vector<int>> m;
        int maxSquare = 0;
        for (int i = 0; i < height; i++) {
            vector<int> row = vector<int>(width);
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '0') {
                    row[j] = 0;
                } else {
                    row[j] = 1;
                    maxSquare = 1;
                }
            }
            m.push_back(row);
        }
        
        if (maxSquare == 0) {
            return 0;
        }
        
        for (int s = 2; s <= MIN(width, height); s++) {
            for (int i = 0; i < height - s + 1; i++) {
                for (int j = 0; j < width - s + 1; j++) {
                    if (m[i][j] < s - 1 || m[i + 1][j] < s - 1 || m[i][j + 1] < s - 1 || m[i + 1][j + 1] < s - 1) {  
                        continue;
                    }

                    m[i][j] = s;
                    maxSquare = s;
                }
            }
            
            if (maxSquare < s) {
                break;
            }
        }
        
        return maxSquare * maxSquare;
    }
};
