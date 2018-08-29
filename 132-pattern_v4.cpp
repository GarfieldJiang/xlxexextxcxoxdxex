// https://leetcode.com/problems/132-pattern/description/

// O(n) time, O(n) space. A friend's method. Much clearer than v3.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        bool hasTwo = false;
        int two = 0;
        
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (hasTwo && nums[i] < two) {
                return true;
            }
            
            while (!s.empty() && s.top() < nums[i]) {
                hasTwo = true;
                two = s.top();
                s.pop();
            }
            
            if (!hasTwo || two < nums[i]) {
                s.push(nums[i]);
            }
        }
        
        return false;
    }
};
