// https://leetcode.com/problems/integer-to-roman/description/

class Solution {
public:
    string intToRoman(int num) {
        int bases[] = { 1000, 100, 10, 1 };
        string ones = "MCXI";
        string fives = "_DLV";
        int baseCount = 4;
        string ret;
        
        int count = num / bases[0];
        num -= count * bases[0];
        for (int j = 1; j <= count; j++) {
            ret.push_back(ones[0]);
        }
        
        for (int i = 1; i < baseCount; i++) {
            int count = num / bases[i];
            num -= count * bases[i];
            
            if (count == 9) {
                ret.push_back(ones[i]);
                ret.push_back(ones[i - 1]);
            } else if (count >= 5) {
                ret.push_back(fives[i]);
                for (int j = 6; j <= count; j++) {
                    ret.push_back(ones[i]);
                }
            } else if (count == 4) {
                ret.push_back(ones[i]);
                ret.push_back(fives[i]);
            } else {
                for (int j = 1; j <= count; j++) {
                    ret.push_back(ones[i]);
                }
            }
        }
        return ret;
    }
};
