// https://leetcode.com/problems/132-pattern/description/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        vector<int> mins(size);
        vector<int> maxs(size);
        
        int minMaxIndex = -1;
        for (int i = 0; i < size; i++) {
            int afterWhich = binarySearchForInclusion(nums[i], mins, maxs, minMaxIndex + 1);
            if (afterWhich < 0) {
                return true;
            }
            
            if (minMaxIndex < 0 || nums[i] < mins[minMaxIndex]) {
                minMaxIndex++;
                maxs[minMaxIndex] = mins[minMaxIndex] = nums[i];
            } else if (nums[i] > maxs[minMaxIndex]) {
                int newMinMaxIndex = afterWhich;
                maxs[newMinMaxIndex] = nums[i];
                mins[newMinMaxIndex] = mins[minMaxIndex];
                minMaxIndex = newMinMaxIndex;
            }
        }
        
        return false;
    }
    
    // return value:
    //   0 and positive: the index of interval after which num falls.
    //   -1: included in some interval.
    int binarySearchForInclusion(int num, vector<int>& mins, vector<int>& maxs, int count) {
        int afterWhich = 0;
        for (int beg = 0, end = count, mid = end / 2; beg < end; mid = beg + (end - beg) / 2) {
            if (num < maxs[mid] && num > mins[mid]) {
                return -1;
            }
            
            if (num >= maxs[mid]) {
                end = mid;
                afterWhich = mid;
            } else {
                beg = mid + 1;
                afterWhich = mid + 1;
            }
        }
        
        return afterWhich;
    }
};
