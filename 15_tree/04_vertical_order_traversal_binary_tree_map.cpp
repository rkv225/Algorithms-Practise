/*
* vertical order traversal of binary tree
* Solution: Using an ordered map
* Time complexity: O(n) for traversal and space complexity O(n) for map
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

map<int, vector<node*>> level_map;

void print_vertical_order_helper(node* root, int level)
{
	if (root == NULL) return;
	level_map[level].push_back(root); // add current node to list
	print_vertical_order_helper(root->left, level - 1); // traverse left node
	print_vertical_order_helper(root->right, level + 1); // traverse right node
}

void print_vertical_order(node* root)
{
	print_vertical_order_helper(root, 0);

	// print all the nodes from each level from the ordered map
	for (map<int, vector<node*>>::iterator it = level_map.begin(); it != level_map.end(); it++)
	{
		vector<node*> level_vector = (*it).second;
		for (vector<node*>::iterator ni = level_vector.begin(); ni != level_vector.end(); ni++)
			cout << (*ni)->value << " ";
		cout << endl;
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

	print_vertical_order(root);
}