// https://leetcode.com/problems/n-queens-ii/description/

class Solution {
public:
    int totalNQueens(int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        
        vector<int> queenXs(n, -1);
        int solutionCount = 0;
        int row = 0;
        while (true) {
            int col = queenXs[row] = getNextCol(n, row, queenXs[row], queenXs);
            if (row == 0 && col == n) {
                break;
            }
            
            if (col == n) {
                queenXs[row--] = -1;
                continue;
            }
            
            if (row == n - 1) {
                solutionCount++;
            } else {
                row++;
            }
        }
        
        return solutionCount;
    }
    
private:
    int getNextCol(int n, int row, int col, vector<int>& queenXs) {
        for (int j = col + 1; j < n; j++) {
            bool fail = false;
            for (int i = 0; i < row; i++) {
                if (queenXs[i] == j || (queenXs[i] - j == i - row) || (queenXs[i] - j == row - i)) {
                    fail = true;
                    break;
                }
            }
            
            if (!fail) {
                return j;
            }
        }
        
        return n;
    }
};
