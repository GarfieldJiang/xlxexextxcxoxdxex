// First version is slow and verbose. This one is much better. 
// I didn't check whether memoization was needed in the first version and then everything became complicated. :P

struct Result
{
    int HasCamera;
    int CoveredByParent;
    int None;
};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto result = calc(root);
        return min(result.HasCamera, result.None);
    }

private:
    Result calc(TreeNode* root) {
        Result result;
        if (!root) {
            result.HasCamera = INT_MAX;
            result.CoveredByParent = 0;
            result.None = 0;
            return result;
        }
        Result leftRes = calc(root->left);
        Result rightRes = calc(root->right);
        result.HasCamera = calcHasCamera(leftRes, rightRes);
        result.CoveredByParent = calcCoveredByParent(leftRes, rightRes);
        result.None = calcNone(leftRes, rightRes);
        return result;
    }
    
    inline int calcHasCamera(const Result& leftRes, const Result& rightRes) {
        int left = min(leftRes.HasCamera, leftRes.CoveredByParent);
        int right = min(rightRes.HasCamera, rightRes.CoveredByParent);
        return (left == INT_MAX || right == INT_MAX) ? INT_MAX : (left + right + 1);
    }
    
    inline int calcCoveredByParent(const Result& leftRes, const Result& rightRes) {
        int left = min(leftRes.HasCamera, leftRes.None);
        int right = min(rightRes.HasCamera, rightRes.None);
        return (left == INT_MAX || right == INT_MAX) ? INT_MAX : (left + right);
    }

    inline int calcNone(const Result& leftRes, const Result& rightRes) {
        int left = min(leftRes.HasCamera, leftRes.None);
        int right = min(rightRes.HasCamera, rightRes.None);
        int cand1 = (leftRes.HasCamera == INT_MAX || right == INT_MAX) ? INT_MAX : (leftRes.HasCamera + right);
        int cand2 = (left == INT_MAX || rightRes.HasCamera == INT_MAX) ? INT_MAX : (left + rightRes.HasCamera);
        return min(cand1, cand2);
    }
};
