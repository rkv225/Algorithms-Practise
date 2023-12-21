/*
* Level order traversal of binary tree
* Solution: Using a queue
* Time complexity: O(n) for traversal and space complexity O(n) for queue
*/
#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

void print_level_order(node* root)
{
	queue<node*> q;
	q.push(root);
	node* new_line = new node{ -1, NULL, NULL };
	q.push(new_line);
	while (!q.empty())
	{
		node* curr = q.front();
		if (curr->value == -1)
		{
			q.pop();
			if (q.empty())
				return;
			q.push(new_line);
			cout << endl;
			continue;
		}
		q.pop();
		cout << curr->value << " ";
		if (curr->left != NULL)
			q.push(curr->left);
		if (curr->right != NULL)
			q.push(curr->right);
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

	print_level_order(root);
}