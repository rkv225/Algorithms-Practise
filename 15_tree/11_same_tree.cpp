/*
Problem:
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Solution:
Perform an inorder traversal of p and q at same time and return false if not equal at any node.

Time Complexity: O(n)

Link: https://leetcode.com/problems/same-tree/
*/

class Solution {
public:
    bool preorder_traversal(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p != NULL && q == NULL)
            return false;
        if(p == NULL && q != NULL)
            return false;
        if(p->val != q->val)
            return false;
        // now that p and q are same, check left and right subtrees
        return preorder_traversal(p->left, q->left) && inorder_traversal(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder_traversal(p, q);
    }
};