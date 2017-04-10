// https://leetcode.com/problems/regular-expression-matching/#/description

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        vector<string> pElems = vector<string>();
        splitPatternToElems(p, pElems);

        stack<int> matchLengths; // stack to store the length of the previously done match.
        int charI = 0; // current index of the given string s.
        int elemI = 0; // current index of the element in pattern string p.
        bool shouldPop = false; // whether matchLengths should pop.
        int matchLength = 0; // current match length.
        while (!shouldPop || !matchLengths.empty()) {
            if (!shouldPop && charI >= s.length() && elemI >= pElems.size()) {
                return true;
            }

            if (shouldPop) {
                int top = matchLengths.top();
                matchLengths.pop();
                elemI--;
                charI -= top;

                if (pElems[elemI].length() == 1) {
                    continue; // shouldPop is still true.
                }

                shouldPop = false;
                matchLength = top + 1;
            } else if (pElems[elemI].length() == 1) {
                matchLength = 1;
            }

            if (localMatch(s, charI, matchLength, pElems, elemI)) {
                matchLengths.push(matchLength);
                elemI++;
                charI += matchLength;
                matchLength = 0;
            } else if (pElems[elemI].length() == 1 || charI + matchLength >= s.length()) {
                shouldPop = true;
            } else {
                ++matchLength;
            }
        }

        return false;
    }

private:
    void splitPatternToElems(const string &p, vector<string> &pElems) {
        for (int i = 0; i < p.length(); /* Empty */) {
            if (i + 1 < p.length() && p[i + 1] == '*') {
                pElems.push_back(p.substr(i, 2));
                i += 2;
            } else {
                pElems.push_back(p.substr(i, 1));
                i += 1;
            }
        }
    }

    bool localMatch(const string& s, int charI, int len, const vector<string> &pElems, int elemI) {
        if (charI >= s.length()) {
            return elemI >= pElems.size() || (pElems[elemI].length() == 2 && len == 0);
        }

        if (elemI >= pElems.size()) {
            return charI >= s.length();
        }

        if (pElems[elemI].length() == 1) {
            return len == 1 && (pElems[elemI][0] == '.' || pElems[elemI][0] == s[charI]);
        }

        if (charI + len > s.length()) {
            return false;
        }

        if (pElems[elemI].length() == 2 && pElems[elemI][0] == '.') {
            return true;
        }

        for (int i = charI; i < charI + len; i++) {
            if (pElems[elemI][0] != s[i]) {
                return false;
            }
        }

        return true;
    }
};
