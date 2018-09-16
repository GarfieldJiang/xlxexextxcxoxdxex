// Wonderful method, beyond me.

typedef vector<int>::iterator Iter;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int rankLo = (m + n - 1) / 2;
        int rankHi = (m + n) / 2;
        int medianLo = select(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), rankLo);
        if (rankLo == rankHi) return (double)medianLo;
        int medianHi = select(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), rankHi);
        return .5 * (medianLo + medianHi);
    }
    
private:
    int select(Iter beg1, Iter end1, Iter beg2, Iter end2, int rank) {
        int len1 = end1 - beg1;
        int len2 = end2 - beg2;
        if (len1 == 0) return *(beg2 + rank);
        if (len2 == 0) return *(beg1 + rank);
        if (rank == 0) return min(*beg1, *beg2);
        Iter half1 = beg1 + min(len1, (rank + 1) / 2);
        Iter half2 = beg2 + min(len2, (rank + 1) / 2);
        if (*(half1 - 1) < *(half2 - 1)) return select(half1, end1, beg2, end2, rank - (half1 - beg1));
        return select(half2, end2, beg1, end1, rank - (half2 - beg2));
    }
};
