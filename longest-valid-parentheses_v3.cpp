// https://leetcode.com/problems/longest-valid-parentheses/#/description

#include "common.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int n = s.length();

        // DP: After each loop, longest[i] is the length of the LVP of s that ends at i.
        int* longest = new int[n];

        longest[0] = 0;
        int maxLen = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                longest[i] = 0;
            } else if (s[i - 1] == '(') {
                longest[i] = 2 + (i < 2 ? 0 : longest[i - 2]);
            } else { // s[i - 1] == ')'
                int j = i - 1 - longest[i - 1];
                if (j < 0 || s[j] == ')') {
                    longest[i] = 0;
                } else {
                    longest[i] = 2 + longest[i - 1] + (j < 1 ? 0 : longest[j - 1]);
                }
            }

            if (longest[i] > maxLen) {
                maxLen = longest[i];
            }
        }

        delete[] longest;
        return maxLen;
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

