/*
* Flatten a binary tree. Convert a binary tree to doubly linked list of inorder traversal.
* Time complexity: O(n) for tree traversal and constant space
*/
#include <iostream>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

node* head_node = NULL;
node* prev_node = NULL;

void convert_to_dll(node* root)
{
	if (root == NULL)
		return;

	convert_to_dll(root->left);

	if (prev_node == NULL)
	{
		head_node = root;
	}
	else
	{
		root->left = prev_node;
		prev_node->right = root;
	}
	prev_node = root;

	convert_to_dll(root->right);
}

void print_dll()
{
	node* curr_node = head_node;
	while (curr_node != NULL)
	{
		cout << curr_node->value << " -> ";
		curr_node = curr_node->right;
	}
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

	convert_to_dll(root);
	print_dll();
}