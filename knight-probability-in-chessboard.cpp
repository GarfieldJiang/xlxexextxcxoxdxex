https://leetcode.com/problems/knight-probability-in-chessboard/description/

struct Direction
{
    int r;
    int c;
};

Direction Directions[] = {
    { 1, 2 },
    { 1, -2 },
    { -1, 2 },
    { -1, -2 },
    { 2, 1 },
    { 2, -1 },
    { -2, 1 },
    { -2, -1 }
};

const int DirectionCount = 8;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp = vector<vector<vector<double>>>(N, vector<vector<double>>(N, vector<double>()));
        return calc(N, K, K, r, c, dp);
    }
    
private:
    double calc(int N, int K, int stepCount, int r, int c, vector<vector<vector<double>>>& dp) {
        if (stepCount == 0) {
            return 1.0;
        }
        
        if (dp[r][c].size() > 0 && dp[r][c][stepCount - 1] >= 0.0) {
            return dp[r][c][stepCount - 1];
        }
        
        if (dp[r][c].size() == 0) {
            dp[r][c].resize(K, -1.0);
        }
        
        double newProb = 0.0;
        for (int i = 0; i < DirectionCount; i++) {
            auto dir = Directions[i];
            int newR = r + dir.r;
            int newC = c + dir.c;
            
            if (isWithinBoard(N, newR, newC)) {
                newProb += calc(N, K, stepCount - 1, newR, newC, dp);
            }
        }
        
        dp[r][c][stepCount - 1] = newProb / 8.0;
        return dp[r][c][stepCount - 1];
    }
    
    inline bool isWithinBoard(int N, int r, int c) {
        return r >= 0 && r < N && c >= 0 && c < N;
    }
};
