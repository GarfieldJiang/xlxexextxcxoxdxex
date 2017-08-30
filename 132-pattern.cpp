// https://leetcode.com/problems/132-pattern/description/

class Solution {
public:
    // O(n^2) time. Slow but accepted.
    bool find132pattern(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        
        float minValue = std::numeric_limits<float>::max();
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= minValue) {
                continue;
            }
                
            float minValue = nums[i];
            float maxValue = nums[i + 1];
            for (int j = i + 2; j < nums.size(); j++) {
                if (nums[j] < maxValue && nums[j] > minValue) {
                    return true;
                }
                
                if (nums[j] > maxValue) {
                    maxValue = nums[j];
                }
            }
        }
        
        return false;
    }
};
