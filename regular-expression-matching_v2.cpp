#include "common.hpp"

class Solution {
public:
    bool isMatch(string s, string p) {
        // cout << "s = " << s << ", p = " << p << endl;
        int m = s.length();
        int n = p.length();
        vector<vector<int> > dp = vector<vector<int> >();
        for (int i = 0; i < m + 1; i++) {
            dp.push_back(vector<int>());
            for (int j = 0; j < n + 1; j++) {
                dp[i].push_back(-1);
            }
        }

        return isMatch(s, p, m, n, 0, 0, dp);
    }

    // dynamic programming - memoized recursion. Time: O(m^2 n), Space: O(mn).
    bool isMatch(const string& s, const string& p, int m, int n, int i, int j, vector<vector<int> >& dp) {
        // cout << "Begin isMatch i = " << i << ", j = " << j << endl;
        if (dp[i][j] >= 0) {
            return dp[i][j];
        }

        if (j >= n) {
            return dp[i][j] = i >= m;
        }

        if (j + 1 < n && p[j + 1] == '*') {
            for (int matchLen = 0; matchLen <= m - i; matchLen++) {
                if (matchLen != 0 && p[j] != '.' && p[j] != s[i + matchLen - 1]) {
                    return dp[i][j] = 0;
                }

                if (isMatch(s, p, m, n, i + matchLen, j + 2, dp)) {
                    return dp[i][j] = 1;
                }
            }

            return dp[i][j] = 0;
        }

        if (i >= m || (p[j] != '.' && p[j] != s[i])) {
            return dp[i][j] = 0;
        }

        return dp[i][j] = isMatch(s, p, m, n, i + 1, j + 1, dp);
    }
};

TEST_CASE("Regular expression matching v2", "[ALL]") {
    Solution solution = Solution();
    REQUIRE(solution.isMatch("a", "ab*a") == false);
    REQUIRE(solution.isMatch("aa", "a") == false);
    REQUIRE(solution.isMatch("a", ".*..a*") == false);
    REQUIRE(solution.isMatch("aaac", "a*a*a*b") == false);
    REQUIRE(solution.isMatch("aaac", "a*b*a*c") == true);
}
