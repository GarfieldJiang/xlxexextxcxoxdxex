// https://leetcode.com/problems/house-robber-ii/description/

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int rob(vector<int>& nums) {
        auto mySize = nums.size();
        if (mySize == 0) return 0;
        if (mySize == 1) return nums[0];
        
        int bestWithLastSelected, bestWithLastUnselected;
        
        bestWithLastSelected = bestWithLastUnselected = nums[0];
        for (int i = 2; i < mySize - 1; i++) {
            int cachedBestWithLastSelected = bestWithLastSelected;
            int cachedBestWithLastUnselected = bestWithLastUnselected;
            bestWithLastUnselected = MAX(cachedBestWithLastSelected, cachedBestWithLastUnselected);
            bestWithLastSelected = cachedBestWithLastUnselected + nums[i];
        }
        int firstSelected = MAX(bestWithLastSelected, bestWithLastUnselected);
        
        bestWithLastSelected = bestWithLastUnselected = 0;
        for (int i = 1; i < mySize; i++) {
            int cachedBestWithLastSelected = bestWithLastSelected;
            int cachedBestWithLastUnselected = bestWithLastUnselected;
            bestWithLastUnselected = MAX(cachedBestWithLastSelected, cachedBestWithLastUnselected);
            bestWithLastSelected = cachedBestWithLastUnselected + nums[i];
        }
        int firstUnselected = MAX(bestWithLastSelected, bestWithLastUnselected);
        
        return MAX(firstSelected, firstUnselected);
    }
};
