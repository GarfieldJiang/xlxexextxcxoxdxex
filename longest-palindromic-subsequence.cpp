// https://leetcode.com/problems/longest-palindromic-subsequence/description/

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if (n <= 0) { return 0; }
        auto dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) { dp[i][i] = 1; }
        for (int d = 1; d < n; d++) {
            for (int i = 0; i < n - d; i++) {
                int j = i + d;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = MAX(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
