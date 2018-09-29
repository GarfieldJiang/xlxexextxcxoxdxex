// https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }
        int digitCount = 1, power = 1, digit = x % 10;
        for (int i = 1, y = x / 10; i <= 9 && y; i++, digitCount++, y /= 10, power *= 10) {}
        int y = x;
        for (int i = 0; i < digitCount / 2; i++, x /= 10, power /= 10) {
            if (x % 10 != (y / power) % 10) { return false; }
        }
        return true;
    }
};
