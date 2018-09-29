// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648) {
            return 0;
        }
        bool negative = false;
        if (x < 0) {
            x = -x;
            negative = true;
        }
        
        int y = 0;
        int firstDigit = x % 10;
        for (int i = 0; i <= 9 && x != 0; i++) {
            int digit = x % 10;
            if (i == 9 && firstDigit > 2) {
                return 0;
            }
            y = y * 10 + (1 - 2 * negative) * digit;
            x /= 10;
        }
        
        if (negative && y >= 0 || !negative && y < 0) {
            return 0;
        }
        return y;
    }
};
