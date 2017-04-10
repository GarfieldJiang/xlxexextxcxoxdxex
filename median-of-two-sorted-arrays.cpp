// https://leetcode.com/problems/median-of-two-sorted-arrays/#/description

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums = vector<int>();
        vector<int>::iterator i1, i2;

        // Merge the 2 vectors.
        for (i1 = nums1.begin(), i2 = nums2.begin(); i1 != nums1.end() || i2 != nums2.end(); /* empty */) {
            if (i1 == nums1.end() || i2 != nums2.end() && *i2 < *i1) {
                nums.push_back(*i2);
                i2++;
            } else {
                nums.push_back(*i1);
                i1++;
            }
        }

        size_t size = nums.size();

        // for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
        //     cout << *i << endl;
        // }

        return size % 2 ? (double)nums[(size - 1) / 2] : (nums[size / 2] * .5 + nums[size / 2 - 1] * .5);
    }
};
