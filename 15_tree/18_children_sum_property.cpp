/*
Problem: 
Given a binary tree of nodes 'N', you need to modify the value of its nodes, such that the tree holds the Children sum property.
A binary tree is said to follow the children sum property if, for every node of that tree, the value of that node is equal to the sum of the value(s) of all of its children nodes( left child and the right child).
Note :
 1. You can only increment the value of the nodes, in other words, the modified value must be at least equal to the original value of that node.
 2. You can not change the structure of the original binary tree.
 3. A binary tree is a tree in which each node has at most two children.      
 4. You can assume the value can be 0 for a NULL node and there can also be an empty tree.

Time Complexity: O(n)

Link: https://www.naukri.com/code360/problems/childrensumproperty_790723
*/

#include <iostream>
using namespace std;
template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode < T >* left;
    BinaryTreeNode < T >* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int get_data(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return 0;
    return root->data;
}
void put_data(BinaryTreeNode<int> *root, int data) {
    if(root != NULL)
        root->data = data;
}
void helper(BinaryTreeNode<int>* root) {
    if (root->data > get_data(root->left) + get_data(root->right)) {
        put_data(root->left, root->data);
        put_data(root->right, root->data);
    }
    if(root->left != NULL)
        helper(root->left);
    if(root->right != NULL)
        helper(root->right);
    if (root->data < get_data(root->left) + get_data(root->right)) {
        root->data = get_data(root->left) + get_data(root->right);
    }
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root != NULL)
        helper(root);
}

int main() 
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(2);
    root->left = new BinaryTreeNode<int>(35);
    root->right = new BinaryTreeNode<int>(10);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(3);
    root->right->left = new BinaryTreeNode<int>(5);
    root->right->right = new BinaryTreeNode<int>(2);
    changeTree(root);
}