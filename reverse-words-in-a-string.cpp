// https://leetcode.com/problems/reverse-words-in-a-string/description/

// O(n) space since a new string is allocated. O(n) time.
class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        string t;
        t.reserve(n);
        int wordEnd = -1;
        bool firstWord = true;
        for (int i = n - 1; i >= 0; i--) {
            if (wordEnd < 0 && !isspace(s[i])) {
                wordEnd = i;
            }
            
            if (wordEnd < 0) {
                continue;
            }
            
            if (i == 0 || isspace(s[i - 1])) {
                if (!firstWord) {
                    t.push_back(' ');
                }
                firstWord = false;
                for (int j = i; j <= wordEnd; j++) {
                    t.push_back(s[j]);
                }
                wordEnd = -1;
            }
        }
        s = t;
    }
};
