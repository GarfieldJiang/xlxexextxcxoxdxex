// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1 || nums[0] < nums[n - 1]) {
            return nums[0];
        }
        return findMinInternal(nums, 0, n - 1);
    }

private:
    int findMinInternal(vector<int>& nums, int lo, int hi) {
        if (lo == hi) { return nums[lo]; }
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }
        if (nums[lo] > nums[mid]) {
            return findMinInternal(nums, lo, mid);
        } else if (nums[mid + 1] > nums[hi]) {
            return findMinInternal(nums, mid + 1, hi);
        } else {
            return min(findMinInternal(nums, lo, mid), findMinInternal(nums, mid + 1, hi));
        }
    }
};
