// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        // finals[j - 1]: Least final element of LIS of length j.
        auto finals = vector<int>(n, -1);
        finals[0] = 0;
        
        // predecessors[i]: Predecessor of the LIS ending at position i in nums.
        // auto predecessors = vector<int>(n, -1);
        
        int ret = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[finals[ret - 1]]) {
                finals[ret] = i;
                // predecessors[i] = finals[ret - 1];
                ret++;
                continue;
            }
            
            int lo = 0, hi = ret;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                int midValue = nums[finals[mid]];
                if (midValue < nums[i]) {
                    lo = mid;
                } else if (midValue == nums[i]) {
                    // predecessors[i] = mid > 0 ? finals[mid - 1] : -1;
                    break;
                } else {
                    if (mid == 0 || nums[finals[mid - 1]] < nums[i]) {
                        finals[mid] = i;
                        // predecessors[i] = mid > 0 ? finals[mid - 1] : -1;
                        break;
                    }
                    hi = mid;
                }
            }
        }
        
        // stack<int> s;
        // s.push(nums[finals[ret - 1]]);
        // for (int p = predecessors[finals[ret - 1]]; p >= 0; p = predecessors[p]) {
        //     s.push(nums[p]);
        // }
        
        // stringstream ss;
        // ss << s.top();
        // s.pop();
        // while (!s.empty()) {
        //     ss << "," << s.top();
        //     s.pop();
        // }
        // ss.flush();
        // cout << ss.str() << endl;
        return ret;
    }
};
