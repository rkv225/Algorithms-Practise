/*
* AVL Trees are height balanced trees where for each node difference in heights between it's right and left child is at most 1.
* This means that height of binary tree h = log(base2)n
* Analysis: Search - O(log2n)
*/

#include<iostream>

using namespace std;

class node
{
public:
	int val;
	node* left;
	node* right;
	node* parent;
	int height;

	node(int x, node* p, int h)
	{
		val = x;
		left = NULL;
		right = NULL;
		parent = p;
		height = h;
	}
};

class AVLTree
{
public:
	AVLTree()
	{
		root = NULL;
	}
	void Insert(int x)
	{
		node* curr = root;
		if (curr == NULL)
		{
			root = new node(x, NULL, 1);
		}
		else
		{
			// normal insert operation
			node* prev = NULL; // new node will the child of this node
			while (curr != NULL)
			{
				prev = curr;
				if (x > curr->val)
					curr = curr->right;
				else if (x < curr->val)
					curr = curr->left;
				else
					return; // we are not allowing duplicates in tree
			}
			if (x > prev->val)
				prev->right = new node(x, prev, 1);
			else
				prev->left = new node(x, prev, 1);

			// adjusting and re-calculating the heights
			curr = prev; // traversing back to parent and updating heights
			while (curr != NULL)
			{
				curr->height = 1 + max(Height(curr->left), Height(curr->right));
				int balance = Height(curr->left) - Height(curr->right);
				if (balance >= 2) // left is heavy
				{
					if (curr->left->left != NULL) // left-left case
					{
						RotateRight(curr, curr->left);
					}
					else // left-right case
					{
						RotateLeft(curr->left, curr->left->right);
						RotateRight(curr, curr->left);
					}
				}
				else if (balance <= -2) // right is heavy
				{
					if (curr->right->right != NULL) // right-right case
					{
						RotateLeft(curr, curr->right);
					}
					else // right-left case
					{
						RotateRight(curr->right, curr->right->left);
						RotateLeft(curr, curr->right);
					}
				}
				prev = curr;
				curr = curr->parent;
			}
			if (root != prev)
				root = prev;
		}
	}

	bool Search(int x)
	{
		node* curr = root;
		bool found = false;
		while (curr != NULL)
		{
			if (curr->val == x)
			{
				found = true;
				break;
			}
			if (x > curr->val)
				curr = curr->right;
			else
				curr = curr->left;
		}
		return found;
	}
private:
	node* root;

	int Height(node* x)
	{
		if (x != NULL)
			return x->height;
		return 0;
	}

	void RotateRight(node* x, node* y)
	{
		if (x->parent != NULL)
		{
			if (x = x->parent->right) // x is right child of it's parent
				x->parent->right = y;
			else // x is left child of it's parent
				x->parent->left = y;
		}
		y->parent = x->parent;
		
		x->left = y->right;
		if (y->right != NULL)
			x->left->parent = x;
		
		y->right = x;
		x->parent = y;

		// update heights
		x->height = 1 + max(Height(x->left), Height(x->right));
		y->height = 1 + max(Height(y->left), Height(y->right));
	}

	void RotateLeft(node* x, node* y)
	{
		if (x->parent != NULL)
		{
			if (x = x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
		}
		y->parent = x->parent;

		x->right = y->left;
		if (y->left != NULL)
			x->right->parent = x;
		 
		y->left = x;
		x->parent = y;

		// update heights
		x->height = 1 + max(Height(x->left), Height(x->right));
		y->height = 1 + max(Height(y->left), Height(y->right));
	}
};

int main()
{
	AVLTree tree;
	tree.Insert(15);
	tree.Insert(20);
	tree.Insert(30);
	tree.Insert(35);
	tree.Insert(40);
	tree.Insert(42);
	tree.Insert(48);
	tree.Insert(50);
	tree.Search(50);
	return 0;
}