/*
Problem: 
Given a binary tree, determine if it is height-balanced.

Solution: While finding the height, at any point if our difference of height is more than 1 then it's not a BST

Time Complexity: O(n)

Link: https://leetcode.com/problems/balanced-binary-tree/description/
*/

class Solution {
public:
    int height_helper(TreeNode *root, bool &balanced) {
        if(root == NULL)
            return 0;
        int left_height = height_helper(root->left, balanced);
        int right_height = height_helper(root->right, balanced);
        if(abs(left_height - right_height) > 1)
            balanced = false;
        return 1 + max(left_height, right_height);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        height_helper(root, balanced);
        return balanced;
    }
};