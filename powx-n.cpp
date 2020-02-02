// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0 || x == 1.0) return x;
        if (n == 0) return 1;
        bool negative = n < 0;
        bool minInt = n == INT_MIN;
        if (negative) n = (minInt ? -(n + 1) : -n);
        double res = myPowInternal(x, n);
        if (negative) {
            res = 1.0 / res;
            if (minInt) res /= x;
        }
        return res;
    }

private:
    inline double myPowInternal(double x, int n) {
        if (n == 1) return x;
        double multiplier = n % 2 ? x : 1;
        double sqrt = myPowInternal(x, n / 2);
        return sqrt * sqrt * multiplier;
    }
};
