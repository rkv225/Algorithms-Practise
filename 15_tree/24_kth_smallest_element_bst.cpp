/*
Problem:
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Solution: 
1. perform in order traversal and decrement k at every visit
2. when k becomes 0, store the result and then return

Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

class Solution {
public:
    int ksmallest;
    void inorder_trav(TreeNode* root, int& k) {
        if(root == NULL)
            return;
        inorder_trav(root->left, k);
        k--;
        if(k == 0) {
            ksmallest = root->val;
            return;
        }
        inorder_trav(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        ksmallest = 0;
        inorder_trav(root, k);
        return ksmallest;
    }
};