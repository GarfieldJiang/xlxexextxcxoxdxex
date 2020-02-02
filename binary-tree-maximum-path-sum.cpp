https://leetcode.com/problems/binary-tree-maximum-path-sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int notStartingAtRoot = maxPathSumInternal(root);
        return max(root->val, notStartingAtRoot);
    }

private:
    int maxPathSumInternal(TreeNode *root) {
        int startingAtRoot = root->val;
        int notStartingAtRoot = INT_MIN;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        if (left) {
            int leftNotStartingAtRoot = maxPathSumInternal(left);   
            startingAtRoot = max(startingAtRoot, root->val + left->val);
            notStartingAtRoot = max(notStartingAtRoot, max(left->val, leftNotStartingAtRoot));
        }
        
        if (right) {
            int rightNotStartingAtRoot = maxPathSumInternal(right);
            startingAtRoot = max(startingAtRoot, root->val + right->val);
            notStartingAtRoot = max(notStartingAtRoot, max(right->val, rightNotStartingAtRoot));
        }
        
        if (left && right) {
            notStartingAtRoot = max(notStartingAtRoot,
                                    root->val + left->val + right->val);
        }
        
        root->val = startingAtRoot;
        return notStartingAtRoot;
    }
};
