/*
* Validate whether a given tree is a binary search tree or not
* Solution: We can perform an inorder traversal and values are not in non decreasing order then we return false
* Time Complexity: O(N)
* Alternate solution: We can recursively go down the tree and have a maximum and minium limit in the values the subtree can have.
* If a subtree voilates the constraint then we return false
* Time Complexity: O(N)
*/

#include <iostream>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

int trav = INT32_MIN;

bool isBST(node* root)
{
    if (root == NULL)
        return true;
    if (!isBST(root->left))
        return false;
    if (root->value <= trav)
        return false;
    else
        trav = root->value;
    if (!isBST(root->right))
        return false;
    return true;
}

int main()
{
	node* root = new node{ 3, new node{ 2, NULL, NULL }, new node{ 4, new node{ 5, NULL, NULL }, new node{ 7, NULL, NULL } } };
	node* curr = root->left;
	curr->left = new node{ 0, NULL, NULL };
	curr->left->right = new node{ 1, NULL, NULL };
    bool x = isBST(root);

    trav = INT32_MIN;
    root->right->value = 6;
    x = isBST(root);
}