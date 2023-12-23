/*
* Lowest common ancestor of binary tree
* Solution: we keep on going down till we find any if the node or 
* we have a point where we have both the nodes present in left and right child
* Time Complexity: 
*/
#include <iostream>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

int lca(node* root, int a, int b)
{
	if (root == NULL)
		return -1;
	if (root->value == a || root->value == b)
		return root->value;
	int left = lca(root->left, a, b);
	int right = lca(root->right, a, b);
	if (left > 0 && right > 0) // found in subtrees, current is the ancestor
		return root->value;
	return max(left, right); // return lca which will be any of these
}

int main()
{
	node* root = new node{ 1, NULL, NULL };
	root->left = new node{ 2, NULL, NULL };
	root->right = new node{ 3, NULL, NULL };
	node* curr = root->left;
	curr->left = new node{ 4, NULL, NULL };
	curr->right = new node{ 5, NULL, NULL };
	curr = curr->left;
	curr->left = new node{ 10, NULL, NULL };
	curr = root->right;
	curr->left = new node{ 6, NULL, NULL };
	curr = curr->left;
	curr->left = new node{ 7, NULL, NULL };
	curr = curr->left;
	curr->left = new node{ 8, NULL, NULL };
	curr->right = new node{ 9, NULL, NULL };
	curr = curr->left;
	curr->left = new node{ 11, NULL, NULL };

	cout << "lca: " << lca(root, 11, 9);
}