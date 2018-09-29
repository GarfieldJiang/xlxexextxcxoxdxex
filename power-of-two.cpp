// https://leetcode.com/problems/power-of-two/description/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) { return false; }
        int lo = 0;
        int hi = 30;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (n == (1 << mid)) { return true; }
            if (n > (1 << mid)) { lo = mid + 1; }
            else { hi = mid - 1; }
        }
        return false;
    }
};
