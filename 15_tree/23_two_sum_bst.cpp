/*
* Check if there exists a pair with the given sum in a bst
* Solution: We keep all the values in a hashmap and then we check if value-curr is present in the map or not
* Time Complexity: O(N), space complexity: O(N)
*/

#include <iostream>
#include <unordered_set>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

unordered_set<int> set;

void fill_set(node* root)
{
	if (root == NULL)
		return;
	fill_set(root->left);
	set.insert(root->data);
	fill_set(root->right);
}

bool find_sum(node* root, int value)
{
	if (root == NULL)
		return false;
	if (set.find(value - root->data) != set.end())
		return true;
	return find_sum(root->left, value) || find_sum(root->right, value);
}

bool two_sum(node* root, int value)
{
	set.clear();
	fill_set(root);
	return find_sum(root, value);
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

	bool x = two_sum(root, 15);
	x = two_sum(root, 40);
}