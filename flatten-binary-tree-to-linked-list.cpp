// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flattenInternal(root);
    }
private:
    TreeNode* flattenInternal(TreeNode* root) {
        TreeNode* l = 0;
        if (root->left) l = flattenInternal(root->left);
        TreeNode* r = 0;
        if (root->right) r = flattenInternal(root->right);
        if (l) {
            l->right = root->right;
            root->right = root->left;
            root->left = 0;
        }
        return r ? r : l ? l : root;
    }
};
