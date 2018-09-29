// https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) { return 0; }
        sort(nums.begin(), nums.end());
        bool anySum = false;
        int closestSum = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int a = nums[i];
            if (i > 0 && a == nums[i - 1]) { continue; }
            int lo = i + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                int b = nums[lo];
                int c = nums[hi];
                int sum = a + b + c;
                if (sum == target) { return sum; }
                if (!anySum || abs(sum - target) < abs(closestSum - target)) {
                    anySum = true;
                    closestSum = sum;
                }
                if (b == c) { break; }
                if (sum > target) { while (nums[hi] == c) { hi--; } }
                if (sum < target) { while (nums[lo] == b) { lo++; } }
            }
        }
        return closestSum;
    }
};
