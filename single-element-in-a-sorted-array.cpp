class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int beg = 0, end = nums.size();
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            //cout << "beg=" << beg << ", end=" << end << ", mid=" << mid << endl;
            bool hasLeft = mid > beg;
            bool hasRight = mid < end - 1;
            if ((!hasLeft || nums[mid] != nums[mid - 1]) && (!hasRight || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }
            
            if (hasLeft && nums[mid] == nums[mid - 1]) {
                if (((end - beg + 1) / 2) % 2) {
                    end = mid + 1;
                } else {
                    beg = mid + 1;
                }
            } else {
                if (((end - beg + 1) / 2) % 2) {
                    beg = mid;
                } else {
                    end = mid;
                }
            }
        }
        
        return nums[beg];
    }
};
