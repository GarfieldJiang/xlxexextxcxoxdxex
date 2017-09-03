// https://leetcode.com/problems/132-pattern/description/

// I didn't think of reversely enumerating the input until a friend of mine hinted me...
// This one finally runs in O(n) time.
//
// The idea is as follows: when you enumerate the input from the right side, you meet an
// increasing subarray until you get a decreasing pair, when 'hasDecreasingPair' is set
// to true. 
//
// - Before that, 'minValue' stores the minimum value met so far, and 'minIndex' the index
//   'minValue' in the input.
//
// - After that, we maintain 'maxValue' and 'minValue' so that they denote the biggest
//   decreasing pair so far, until we found an input element less than 'minValue'.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        
        bool hasDecreasingPair = false;
        int minValue = nums[nums.size() - 1];
        int maxValue = 0;
        int minIndex = nums.size() - 1;
        int maxIndex = -1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (!hasDecreasingPair) {
                if (nums[i] < minValue) {
                    minValue = nums[i];
                    minIndex = i;
                } else if (nums[i] > minValue) {
                    hasDecreasingPair = true;
                    maxValue = nums[i];
                    maxIndex = i;
                    updateMinValue(minIndex, minValue, maxValue, nums);
                }
                continue;
            }
            
            if (nums[i] < minValue) {
                return true;
            }

            if (nums[i] == maxValue) {
                int lastMaxIndex = maxIndex;
                maxIndex = i;
                for (int j = maxIndex + 1; j < lastMaxIndex; j++) {
                    if (nums[j] > minValue) {
                        minValue = nums[j];
                    }
                }
            } else if (nums[i] > maxValue) {
                minValue = maxValue;
                maxValue = nums[i];
                maxIndex = i;
                updateMinValue(minIndex, minValue, maxValue, nums);
            }
        }
        
        return false;
    }
    
private:
    inline void updateMinValue(int& minIndex, int& minValue, int maxValue, vector<int>& nums) {
        for (int j = minIndex + 1; j < nums.size(); j++) {
            if (nums[j] >= maxValue) {
                break;
            }

            if (nums[j] > minValue) {
                minValue = nums[j];
                minIndex = j;
            }
        }
    }
};
