/*
Problem:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Solution: recall the same_tree problem where we perform a preorder traversal
We make similar function and treat left and right subtree of original tree as separate
We perform traversals as:
NLR on left, NRL on right and compare both left and child recursively.

Link: https://leetcode.com/problems/symmetric-tree
*/

class Solution {
public:
    bool is_same(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return is_same(p->left, q->right) && is_same(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return is_same(root->left, root->right);
    }
};