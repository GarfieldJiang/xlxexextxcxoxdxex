// https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            x = -x;
            negative = true;
        }
        
        char digits[10] = {0};
        int digitCount = 0;
        for (int i = 0; i <= 9 && x != 0; i++, digitCount++) {
            digits[i] = x % 10;
            x /= 10;
        }
        
        if (digitCount == 10 && digits[0] > 2) {
            return 0;
        }
        
        int y = 0;
        int power = 1;
        for (int i = digitCount - 1; i >= 0; i--) {
            int val = digits[i] * power;
            if (val < 0) {
                y = 0;
                break;
            }
            y += (1 - 2 * (int)negative) * val;
            power *= 10;
        }
        if (negative && y >= 0 || !negative && y < 0) {
            return 0;
        }
        return y;
    }
};
