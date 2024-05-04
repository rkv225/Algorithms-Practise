/*
Problem:
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Solution: 
1. keep a range of max and min value 
2. start with -inf to +inf
3. when moving left update max range and update min range when moving right
4. if root->val not in given range then return false
5. check all the nodes recursively

Link: https://leetcode.com/problems/validate-binary-search-tree/
*/

class Solution {
public:
    bool isValid(TreeNode* root, long long min_range, long long max_range) {
        if(root == NULL)
            return true;
        if(root->val <= min_range || root->val >= max_range)
            return false;
        return isValid(root->left, min_range, root->val) && isValid(root->right, root->val, max_range);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root, -1e11, 1e11);
    }
};