#include "common.hpp"

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // Iterative dynamic programming. Time: O(m^2 n), Space: O(m).
        vector<int> dp = vector<int>();
        for (int i = 0; i < m; i++) {
            dp.push_back(0);
        }
        dp.push_back(1);

        for (int j = n - 1; j >= 0; j--) {
            if (j == 0 || p[j] != '*') {
                for (int i = 0; i < m; i++) {
                    dp[i] = (p[j] == '.' || p[j] == s[i]) && dp[i + 1];
                }
                dp[m] = 0;
                continue;
            }

            --j;
            for (int i = 0; i < m + 1; i++) {
                for (int matchLen = 0; matchLen <= m - i; matchLen++) {
                    if (matchLen != 0 && p[j] != '.' && p[j] != s[i + matchLen - 1]) {
                        dp[i] = 0;
                        break;
                    }

                    if (dp[i + matchLen]) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};

TEST_CASE("Regular expression matching v3", "[ALL]") {
    Solution solution = Solution();
    REQUIRE(solution.isMatch("a", "ab*a") == false);
    REQUIRE(solution.isMatch("aa", "a") == false);
    REQUIRE(solution.isMatch("a", ".*..a*") == false);
    REQUIRE(solution.isMatch("aaac", "a*a*a*b") == false);
    REQUIRE(solution.isMatch("aaac", "a*b*a*c") == true);
}
