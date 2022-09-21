class Solution {
public:
    int trap(vector<int>& height) {
        const int IndexFactor = 100001;
        int n = height.size();
        int leftMaxHeightIndex = 0;
        int leftMaxHeight = height[0];
        for (int i = 1; i < n; ++i) {
            int h = height[i];
            height[i] += IndexFactor * leftMaxHeightIndex;
            int lastIndex = leftMaxHeightIndex;
            if (h >= leftMaxHeight) {
                leftMaxHeightIndex = i;
                leftMaxHeight = h;
            }
        }

        int sum = 0;
        int rightMaxHeightIndex = n - 1;
        int rightMaxHeight = height[n - 1] % IndexFactor;
        for (int i = n - 2; i >= 1; i--) {
            int h = height[i] % IndexFactor;
            int lh = height[height[i] / IndexFactor] % IndexFactor;
            if (rightMaxHeight > h && lh > h) {
                sum += min(rightMaxHeight, lh) - h;
            }
            if (h >= rightMaxHeight) {
                rightMaxHeightIndex = i;
                rightMaxHeight = h;
            }
        }
        return sum;
    }
};
