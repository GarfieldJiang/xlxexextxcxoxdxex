// https://leetcode.com/problems/wildcard-matching/description/

// Slow but accepted DP method. O(m * n * n) time.

#define SWAP(a, b) { auto tmp = a; a = b; b = tmp; }

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        
        // dp[i][j] means whether p[0..i] (length i + 1) and s[0..j] (length j + 1) matches.
        auto dp = vector<bool>(n + 1, false);
        dp[0] = true;
        
        auto dp2 = vector<bool>(n + 1, false);
        
        for (int i = 1; i <= m; i++) {
            dp2[0] = dp[0] && p[i - 1] == '*';
            for (int j = 1; j <= n; j++) {
                switch (p[i - 1]) {
                    case '*':
                        dp2[j] = false;
                        for (int k = 0; k <= j; k++) { dp2[j] = dp2[j] || dp[k]; }
                        break;
                    case '?':
                        dp2[j] = dp[j - 1];
                        break;
                    default: // a-z
                        dp2[j] = dp[j - 1] && p[i - 1] == s[j - 1];
                        break;
                }
            }
            SWAP(dp, dp2);
        }
        
        return dp[n];
    }
};
