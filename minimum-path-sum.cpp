// https://leetcode.com/problems/minimum-path-sum/description/

// Obvious DP using a rolling array.

#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        vector<int> dp(width);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 && j == 0) dp[0] = grid[0][0];
                else if (i == 0) dp[j] = dp[j - 1] + grid[0][j];
                else if (j == 0) dp[0] += grid[i][0];
                else dp[j] = MIN(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp[width - 1];
    }
};
