/*
Problem:
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


Solution:
keep moving from root till both nodes become left and right child, that node will be LCA

Time Complexity: O(h)
Space Complexity: O(1)

Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root->val == p->val)
            return p;
        if(root->val == q->val)
            return q;
        // both on left
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // both on right
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // one lies on left and other on right, so root is LCA
        return root;
    }
};