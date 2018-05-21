// https://leetcode.com/problems/unique-paths-ii/description/

// Obvious DP, with modification to the input so that no additional memory is allocated.
// If obstacleGrid[i][j] = 1, then it indicates there is an obstacle at the position (i, j).
// Otherwise (obstacleGrid[i][j] <= 0), its opposite number indicates how many paths there are from (0, 0) to (i, j).

#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        if (obstacleGrid[0][0] > 0) {
            return 0;
        }
        obstacleGrid[0][0] = -1;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] > 0) continue;
                
                if (i == 0) obstacleGrid[i][j] = MIN(0, obstacleGrid[i][j - 1]);
                else if (j == 0) obstacleGrid[i][j] = MIN(0, obstacleGrid[i - 1][j]);
                else obstacleGrid[i][j] = MIN(0, obstacleGrid[i - 1][j]) + MIN(0, obstacleGrid[i][j - 1]);
            }
        }
        
        int last = obstacleGrid[height - 1][width - 1];
        return -MIN(0, last);
    }
};
