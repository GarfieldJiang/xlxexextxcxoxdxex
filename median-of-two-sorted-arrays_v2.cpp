https://leetcode.com/problems/median-of-two-sorted-arrays/description/

class Solution {
public:
    // O(n) time + O(1) space.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();

        for (int i1 = 0, i2 = 0, currentUse1 = false, lastUse1 = false;
             true;
             i1 += currentUse1, i2 += !currentUse1, lastUse1 = currentUse1) {
            
            currentUse1 = i1 < nums1.size() && (i2 >= nums2.size() || nums2[i2] >= nums1[i1]);
            
            if (i1 + i2 < totalSize / 2) {
                continue;
            }
            
            double current = double(currentUse1 ? nums1[i1] : nums2[i2]);
            if (totalSize % 2) {
                return current;
            } else {
                double last = double(lastUse1 ? nums1[i1 - 1] : nums2[i2 - 1]);
                return .5 * (current + last);
            }
        }
    }
};
