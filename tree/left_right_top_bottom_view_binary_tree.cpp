/*
* left view, right view, top view and bottom view of binary tree
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

void print_top_view_helper(node* root, int level)
{
	if (root == NULL)
		return;
	if (level_map.find(level) == level_map.end())
		level_map[level] = root;
	print_top_view_helper(root->left, level - 1);
	print_top_view_helper(root->right, level + 1);
}

void print_bottom_view_helper(node* root, int level)
{
	if (root == NULL)
		return;
	level_map[level] = root;
	print_bottom_view_helper(root->left, level - 1);
	print_bottom_view_helper(root->right, level + 1);
}

void print_map()
{
	// print from ordered map
	for (map<int, node*>::iterator it = level_map.begin(); it != level_map.end(); it++)
		cout << (*it).second->value << endl;
}

void print_view(node* root, char view)
{
	level_map.clear();
	switch (view)
	{
	case 'l': 
		print_left_view_helper(root, 1);
		break;
	case 'r':
		print_right_view_helper(root, 1);
		break;
	case 't':
		print_top_view_helper(root, 0);
		break;
	case 'b':
		print_bottom_view_helper(root, 0);
		break;
	default:
		cout << "invalid view" << endl;
		break;
	}
	print_map();
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

	cout << "left view of binary tree: " << endl;
	print_view(root, 'l');

	cout << "\nright view of binary tree: " << endl;
	print_view(root, 'r');

	cout << "\ntop view of binary tree: " << endl;
	print_view(root, 't');

	cout << "\nbottom view of binary tree: " << endl;
	print_view(root, 'b');
}