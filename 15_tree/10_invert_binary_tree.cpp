/*
Problem:
Given the root of a binary tree, invert the tree, and return its root.

Link: https://leetcode.com/problems/invert-binary-tree
*/

class Solution {
public:
    void invert(TreeNode *root) {
        if(root == NULL)
            return;
        if(root->left != NULL || root->right != NULL) {
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};