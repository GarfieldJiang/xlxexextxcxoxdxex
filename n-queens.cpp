https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if (n < 0) {
            return ret;
        }
        if (n == 0) {
            ret.push_back(vector<string>());
            return ret;
        }
        
        vector<int> queenXs(n, -1);
        int row = 0;
        while (true) {
            //int lastCol = queenXs[row];
            int col = queenXs[row] = getNextCol(n, row, queenXs[row], queenXs);
            //cout << "row: " << row << ", col: " << col << ", lastCol: " << lastCol << endl;
            if (row == 0 && col == n) {
                break;
            }
            
            if (col == n) {
                queenXs[row--] = -1;
                continue;
            }
            
            if (row == n - 1) {
                auto newBoard = vector<string>(n, ""); 
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < queenXs[i]; j++) {
                        newBoard[i].push_back('.');
                    }
                    newBoard[i].push_back('Q');
                    for (int j = queenXs[i] + 1; j < n; j++) {
                        newBoard[i].push_back('.');
                    }
                }
                ret.push_back(newBoard);
            } else {
                row++;
            }
        }
        
        return ret;
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
