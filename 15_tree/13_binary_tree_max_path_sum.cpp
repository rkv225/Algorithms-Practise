/*
Problem:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Solution: O(n)

Link: https://leetcode.com/problems/binary-tree-maximum-path-sum
*/

class Solution {
public:
    int max_sum = -1e9;
    int helper(TreeNode* root) {
        if(root == NULL)
            return 0;
        int max_left = max(helper(root->left), 0);
        int max_right = max(helper(root->right), 0);
        max_sum = max(max_sum, max_left + max_right + root->val);
        return root->val + max(max_left, max_right);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_sum;
    }
};