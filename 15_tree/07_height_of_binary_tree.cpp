/*
Problem: Max height/depth of binary tree node
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {    
        if(root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left, right);
    }
};