// https://leetcode.com/problems/longest-valid-parentheses/#/description

#include "common.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int n = s.length();
        int maxValidLen = 0;
        for (int i = 0; i < n; /* EMPTY */) {
            int len = 0;
            int deltaLen;
            while ((deltaLen = calcMatchLength(s, n, i)) > 0)
            {
                len += deltaLen;
                i += deltaLen;
            }

            if (maxValidLen < len) {
                maxValidLen = len;
            }

            if (len == 0) {
                i++;
            }
        }

        return maxValidLen;
    }

private:
    inline int calcMatchLength(const string &s, int n, int i) {
        if (s[i] == ')') {
            return 0;
        }

        // s[i] == '('
        int level = 1;
        for (int j = i + 1; j < n; j++) {
            level = s[j] == ')' ? level - 1 : level + 1;
            if (level == 0) {
                return j - i + 1;
            }
        }

        return 0;
    }
};

TEST_CASE("Longest Valid Parentheses", "[ALL]") {
    Solution solution = Solution();
    REQUIRE(solution.longestValidParentheses(")(") == 0);
    REQUIRE(solution.longestValidParentheses(")(((((()))))()") == 12);
    REQUIRE(solution.longestValidParentheses(")(((((()())()()))()(()))(") == 22);
    REQUIRE(solution.longestValidParentheses("") == 0);
    REQUIRE(solution.longestValidParentheses("(") == 0);
    REQUIRE(solution.longestValidParentheses(")") == 0);
    REQUIRE(solution.longestValidParentheses("()") == 2);
    REQUIRE(solution.longestValidParentheses(")(") == 0);
    REQUIRE(solution.longestValidParentheses("((") == 0);
    REQUIRE(solution.longestValidParentheses("))") == 0);
    REQUIRE(solution.longestValidParentheses("(()") == 2);
    REQUIRE(solution.longestValidParentheses("())") == 2);
    REQUIRE(solution.longestValidParentheses("(((") == 0);
    REQUIRE(solution.longestValidParentheses(")))") == 0);
    REQUIRE(solution.longestValidParentheses(")()") == 2);
    REQUIRE(solution.longestValidParentheses("()(") == 2);
    REQUIRE(solution.longestValidParentheses(")((") == 0);
    REQUIRE(solution.longestValidParentheses("))(") == 0);
    REQUIRE(solution.longestValidParentheses("(())") == 4);
    REQUIRE(solution.longestValidParentheses("()()") == 4);
    REQUIRE(solution.longestValidParentheses("((((((()))))))") == 14);
    REQUIRE(solution.longestValidParentheses(")(((((()))))))") == 12);
}

