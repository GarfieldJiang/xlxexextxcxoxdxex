// https://leetcode.com/problems/container-with-most-water/#/description

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), s = 0;
        for (int i = 0; i < n - 1; i++) {
            if (height[i] == 0) {
                continue;
            }
            
            int minWidth = s / height[i];
            for (int j = i + minWidth; j < n; j++) {
                int new_s = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
                if (new_s > s) {
                    s = new_s;
                }
            }
        }
        return s;
    }
};
