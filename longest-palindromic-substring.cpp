// https://leetcode.com/problems/longest-palindromic-substring/#/description

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        int n = s.length(); // n >= 2

        bool* isPalindromeCache = new bool[n * (n - 1) / 2];

        int beg = 0, maxLen = 1;
        for (int i = n - 2; i != -1; i--) {
            for (int len = 2; len != n - i + 1; len++) {
                int index = (((n + n - i - 1) * i) >> 1) + len - 2;
                isPalindromeCache[index] = s[i] == s[i + len - 1];
                if (len > 3) {
                    isPalindromeCache[index] &= isPalindromeCache[index + n - i - 3];
                }

                if (isPalindromeCache[index] && len > maxLen) {
                    beg = i;
                    maxLen = len;
                }
            }
        }

        delete[] isPalindromeCache;

        return s.substr(beg, maxLen);
    }
};
