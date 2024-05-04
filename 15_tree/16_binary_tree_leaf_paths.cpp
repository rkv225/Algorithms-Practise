/*
Problem: 
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]

Link: https://leetcode.com/problems/binary-tree-paths
*/

class Solution {
public:
    vector<string> paths;
    void root_to_node(TreeNode* root, string path) {
        if(root->left == NULL && root->right == NULL) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        if(root->left != NULL)
            root_to_node(root->left, path);
        if(root->right != NULL)
            root_to_node(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        root_to_node(root, "");
        return paths;
    }
};