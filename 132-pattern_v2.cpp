// https://leetcode.com/problems/132-pattern/description/

class Solution {
public:
    // O(n log n) time.
    bool find132pattern(vector<int>& nums) {
        vector<int> mins;
        vector<int> maxs;
        
        for (int i = 0; i < nums.size(); i++) {
            if (binarySearchForInclusion(nums[i], mins, maxs)) {
                return true;
            }
            
            int last = mins.size() - 1;
            if (last < 0 || nums[i] < mins[last]) {
                mins.push_back(nums[i]);
                maxs.push_back(nums[i]);
            } else if (nums[i] > maxs[last]) {
                maxs[last] = nums[i];
            }
        }
        
        return false;
    }
    
    bool binarySearchForInclusion(int num, vector<int>& mins, vector<int>& maxs) {
        for (int beg = 0, end = mins.size(), mid = end / 2; beg < end; mid = beg + (end - beg) / 2) {
            if (num < maxs[mid] && num > mins[mid]) {
                return true;
            }
            
            if (num >= mins[mid]) {
                end = mid;
            } else {
                beg = mid + 1;
            }
        }
        
        return false;
    }
};
