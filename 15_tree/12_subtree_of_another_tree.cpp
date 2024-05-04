/*
Problem:
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Solution:

1. if both are null then true
2. if any of the node is null then false
3. if both the values are same then check if trees are same(function from same_tree)
4. if (3.) returns false then check main tree left and right
5. if any of the (3.) and (4.) return true then return true

Link: https://leetcode.com/problems/subtree-of-another-tree/
*/

class Solution {
public:
    bool same(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return same(p->left, q->left) && same(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL)
            return true;
        if(root == NULL || subRoot == NULL)
            return false;
        bool is_subtree = false;
        if(root->val == subRoot->val)
            is_subtree = same(root, subRoot);
        if(!is_subtree) 
            is_subtree = isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return is_subtree;
    }
};