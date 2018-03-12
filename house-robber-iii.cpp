// https://leetcode.com/problems/house-robber-iii/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int rob(TreeNode* root) {
        int optWithoutRoot;
        return robInternal(root, optWithoutRoot);
    }

private:
    int robInternal(TreeNode* root, int& optWithoutRoot) {
        optWithoutRoot = 0;
        if (!root) return 0;
        
        int leftOptWithoutRoot;
        int leftOpt = robInternal(root->left, leftOptWithoutRoot);
        int rightOptWithoutRoot;
        int rightOpt = robInternal(root->right, rightOptWithoutRoot);
        
        optWithoutRoot = leftOpt + rightOpt;
        int optWithRoot = leftOptWithoutRoot + rightOptWithoutRoot + (root->val);
        return MAX(optWithoutRoot, optWithRoot);
    }
};
