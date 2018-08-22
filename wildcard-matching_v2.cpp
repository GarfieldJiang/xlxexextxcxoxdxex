// https://leetcode.com/problems/wildcard-matching/description/

// DP method optimized. O(m * n) time, but still a bit slow.

#define SWAP(a, b) { auto tmp = a; a = b; b = tmp; }

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        
        auto dp = vector<bool>(n + 1, false);
        dp[0] = true;
        auto orCached = vector<bool>(n + 1, true); // Cumulative OR result of dp.
        auto dp2 = vector<bool>(n + 1, false);
        
        for (int i = 1; i <= m; i++) {
            dp2[0] = dp[0] && p[i - 1] == '*';
            orCached[0] = dp2[0];
            for (int j = 1; j <= n; j++) {
                switch (p[i - 1]) {
                    case '*':
                        dp2[j] = orCached[j];
                        break;
                    case '?':
                        dp2[j] = dp[j - 1];
                        break;
                    default: // a-z
                        dp2[j] = dp[j - 1] && p[i - 1] == s[j - 1];
                        break;
                }
                orCached[j] = orCached[j - 1] || dp2[j];
            }
            
            SWAP(dp, dp2);
        }
        
        return dp[n];
    }
};
