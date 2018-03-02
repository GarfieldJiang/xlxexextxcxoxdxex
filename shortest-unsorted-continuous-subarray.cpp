// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int M = nums[0];
        int beg = -1;
        int end = -1;
        int minReverseIndex = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < M) {
                end = i;
                if (minReverseIndex < 0 || nums[i] < nums[minReverseIndex]) {
                    minReverseIndex = i;
                }
            }
            else {
                M = nums[i];
            }
        }
            
        for (int i = 0; i < minReverseIndex; i++) {
            if (nums[i] > nums[minReverseIndex]) {
                beg = i;
                break;
            }
        }
            
        return beg < 0 ? 0 : end - beg + 1;
    }
};
