/*
Problem:
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]

Solution:
1. put inorder traversal in a map
2. make a helper that we will call recursively
3. check base condition
4. create a root node from preorder
5. find the split index from inorder traversal
6. increment index
7. call for left and right of node

Time: O(n)
Space O(n)

Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& inorder, int& index, int i, int j) {
        if(i > j || index > preorder.size() - 1)
            return NULL;
        TreeNode* root = new TreeNode(preorder[index]);
        int split = inorder[preorder[index]];
        index++;
        root->left = helper(preorder, inorder, index, i, split - 1);
        root->right = helper(preorder, inorder, index, split + 1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;
        int index = 0;
        return helper(preorder, inorder_map, index, 0, preorder.size() - 1);
    }
};