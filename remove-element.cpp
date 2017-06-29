// https://leetcode.com/problems/remove-element/#/description

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), i = 0, j = n - 1;
        while (i <= j) {
            if (nums[j] == val) { j--; continue; }
            if (nums[i] == val) { nums[i++] = nums[j--]; continue; }
            i++;
        }
        return i;
    }
};
