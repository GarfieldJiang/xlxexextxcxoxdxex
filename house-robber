// https://leetcode.com/problems/house-robber/description/

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int rob(vector<int>& nums) {
        int bestWithLastSelected = 0;
        int bestWithLastUnselected = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int cachedBestWithLastSelected = bestWithLastSelected;
            bestWithLastSelected = bestWithLastUnselected + nums[i];
            bestWithLastUnselected = MAX(cachedBestWithLastSelected, bestWithLastUnselected);
        }
        
        return MAX(bestWithLastSelected, bestWithLastUnselected);
    }
};
