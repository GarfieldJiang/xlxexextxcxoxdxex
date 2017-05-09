// https://leetcode.com/problems/longest-valid-parentheses/#/description

#include "common.hpp"

class Solution {
public:
    int longestValidParentheses(string s) {
        // cout << "----- s='" << s << "' -----" << endl;
        if (s.length() == 0) {
            return 0;
        }

        int n = s.length();
        vector<int> pairs = vector<int>(n, -1);

        int firstLeftParenthesis = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                firstLeftParenthesis = i;
                break;
            }
        }

        int leftmost = n;
        stack<int> matchStack = stack<int>();
        for (int i = firstLeftParenthesis; i < n; i++)
        {
            if (s[i] == '(') {
                matchStack.push(i);
            } else if (!matchStack.empty()) {
                int j = matchStack.top();
                matchStack.pop();
                pairs[j] = i;
                if (j < leftmost) {
                    leftmost = j;
                }
            }
        }

        int maxLen = 0;
        for (int i = leftmost, len = 0; i < n; /* EMPTY */) {
            if (pairs[i] < 0) {
                len = 0;
                i++;
                continue;
            }

            len += pairs[i] - i + 1;
            i = pairs[i] + 1;
            if (len > maxLen) {
                maxLen = len;
            }
        }

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

