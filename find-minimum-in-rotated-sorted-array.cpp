class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1 || nums[0] < nums[n - 1]) {
            return nums[0];
        }
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[lo] > nums[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        throw std::exception();
    }
};
