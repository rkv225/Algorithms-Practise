/*
* Diameter of a binary tree
* Solution: For all tree node we calculate the height of the binary tree left and right side 
* and check if we have the largest diameter at the current node.
* Time Complexity: O(n)
*/

#include <iostream>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

int diameter = 0;

int find_height(node* root)
{
	if (root == NULL)
		return 0;
	int left_height = find_height(root->left);
	int right_height = find_height(root->right);
	diameter = max(diameter, left_height + right_height);
	return 1 + max(left_height, right_height);
}

int main()
{
	node* root = new node{ 1, new node{ 2, NULL, NULL }, new node{ 3, NULL, NULL } };
	node* curr = root->right;
	curr->left = new node{ 4, NULL, NULL };
	curr->left->left = new node{ 5, NULL, NULL };
	curr->left->left->left = new node{ 9, NULL, NULL };
	curr->right = new node{ 6, NULL, NULL };
	curr->right->right = new node{ 7, NULL, NULL };
	curr->right->right->right = new node{ 8, NULL, NULL };

	cout << "Height of tree: " << find_height(root) << endl;
	cout << "Diameter of tree: " << diameter;
}