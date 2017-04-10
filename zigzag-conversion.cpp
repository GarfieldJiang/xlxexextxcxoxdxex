// https://leetcode.com/problems/zigzag-conversion/#/description

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty()) return "";
        if (numRows == 1) return s;
        int len = s.length();
        int numPerGroup = 2 * numRows - 2;
        int numGroups = len / numPerGroup + (len % numPerGroup ? 1 : 0);
        string ret = "";
        for (int i = 0; i < numGroups; ++i) {
            int index = numPerGroup * i;
            //if (index < len) {
            ret += s[index];
            //}
        }

        for (int j = 1; j < numRows - 1; ++j) {
            for (int i = 0; i < numGroups; ++i) {
                int index1 = numPerGroup * i + j;
                int index2 = numPerGroup * i + numPerGroup - j;
                if (index1 < len) ret += s[index1];
                if (index2 < len) ret += s[index2];
            }
        }

        for (int i = 0; i < numGroups; ++i) {
            int index = numPerGroup * i + numRows - 1;
            if (index < len) {
                ret += s[index];
            }
        }

        return ret;
    }
};
