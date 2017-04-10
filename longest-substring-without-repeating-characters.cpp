// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        bool *unrepeated = new bool[n - 1];

        int max_len = 1;
        for (int beg = 0; beg < n - 1; beg++) {
            unrepeated[beg] = s[beg] != s[beg + 1];
            if (unrepeated[beg]) max_len = 2;
        }

        if (max_len == 1) return 1;

        for (int len = 3; len <= n; len++) {
            bool increased = false;
            for (int beg = 0; beg <= n - len; beg++) {
                unrepeated[beg] = unrepeated[beg] && unrepeated[beg + 1] && s[beg] != s[beg + len - 1];
                if (unrepeated[beg] && len > max_len && !increased) {
                    max_len = len;
                    increased = true;
                }
            }

            if (!increased) return max_len;
        }

        delete[] unrepeated;
        return max_len;
    }
};
