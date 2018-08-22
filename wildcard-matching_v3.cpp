// https://leetcode.com/problems/wildcard-matching/description/
// DP method optimized more. O(m * n) time.

#define SWAP(a, b) { auto tmp = a; a = b; b = tmp; }

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        
        auto dp = vector<bool>(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= m; i++) {
            bool last = dp[0];
            bool orCached = dp[0];
            dp[0] = dp[0] && p[i - 1] == '*';
            for (int j = 1; j <= n; j++) {
                bool newLast = dp[j];
                orCached = orCached || newLast;
                switch (p[i - 1]) {
                    case '*':
                        dp[j] = orCached;
                        break;
                    case '?':
                        dp[j] = last;
                        break;
                    default: // a-z
                        dp[j] = last && p[i - 1] == s[j - 1];
                        break;
                }
                last = newLast;
            }
        }
        
        return dp[n];
    }
};
