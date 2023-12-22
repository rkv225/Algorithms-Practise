/*
* left view and right view of binary tree
* time complexity: O(n) and space complexity O(n)
*/
#include <iostream>
#include <map>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

map<int, node*> level_map;

void print_left_view_helper(node* root, int level)
{
	if (root == NULL) 
		return;
	if (level_map.find(level) == level_map.end())
		level_map[level] = root;
	print_left_view_helper(root->left, level + 1);
	print_left_view_helper(root->right, level + 1);
}

void print_right_view_helper(node* root, int level)
{
	if (root == NULL)
		return;
	level_map[level] = root;
	print_right_view_helper(root->left, level + 1);
	print_right_view_helper(root->right, level + 1);
}

void print_left_view(node* root)
{
	level_map.clear();
	print_left_view_helper(root, 1);

	// print from ordered map
	for (map<int, node*>::iterator it = level_map.begin(); it != level_map.end(); it++)
		cout << (*it).second->value << endl;
}

void print_right_view(node* root)
{
	level_map.clear();
	print_right_view_helper(root, 1);

	// print from ordered map
	for (map<int, node*>::iterator it = level_map.begin(); it != level_map.end(); it++)
		cout << (*it).second->value << endl;
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

	cout << "Left view of binary tree: " << endl;
	print_left_view(root);

	cout << "\nright view of binary tree: " << endl;
	print_right_view(root);
}