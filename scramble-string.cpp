// https://leetcode.com/problems/scramble-string/description/

// Very slow whereas accepted DP method. Substructure: s1[i .. i+l-1], s2[j .. j+l-1] are scrambled of each other,
// if and only if there is some l1 in [1, l-1] so that one of the following two holds:
// a) s1[i .. i+l1-1], s2[i .. j+l1-1] are scrambled, and s1[i+l1 .. i+l-1], s2[j+l1 .. j+l-1] are scrambled;
// b) s1[i .. i+l1-1], s2[j+l1 .. j+l-1] are scrambled, and s1[i+l1 .. i+l-1], s2[j .. j+l1-1] are scrambled.

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length() || n == 0) return false;
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l <= n; i++) {
                for (int j = 0; j + l <= n; j++) {
                    for (int l1 = 1; l1 < l && !dp[i][j][l]; l1++) {
                        dp[i][j][l] = dp[i][j][l] || (dp[i][j][l1] && dp[i + l1][j + l1][l - l1]);
                        dp[i][j][l] = dp[i][j][l] || (dp[i][j + l - l1][l1] && dp[i + l1][j][l - l1]);
                    }
                }
            }
        }
        
        return dp[0][0][n];
    }
};
