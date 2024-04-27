#include<iostream>
#include<string>
#include<queue>

using namespace std;

struct node
{
	int value;
	node* parent;
	node* left;
	node* right;
};

class Tree
{
private:
	node* root;
	void InorderTraversalHelper(node* x, queue<int>& q)
	{
		// left root right
		if (x != NULL)
		{
			InorderTraversalHelper(x->left, q);
			q.push(x->value);
			InorderTraversalHelper(x->right, q);
		}
	}
	void PreorderTraversalHelper(node* x, queue<int>& q)
	{
		// root left right
		if (x != NULL)
		{
			q.push(x->value);
			PreorderTraversalHelper(x->left, q);
			PreorderTraversalHelper(x->right, q);
		}
	}
	void PostorderTraversalHelper(node* x, queue<int>& q)
	{
		// left right root
		if (x != NULL)
		{
			PostorderTraversalHelper(x->left, q);
			PostorderTraversalHelper(x->right, q);
			q.push(x->value);
		}
	}
	void PrintTraversalHelper(string title, queue<int>& q)
	{
		cout << title << ":" << endl;
		// print until queue is empty
		while (!q.empty())
		{
			cout << q.front() << "  ";
			q.pop();
		}
		cout << endl;
	}
	int HeightHelper(node* x)
	{
		if (x == NULL) return 0;
		return max(HeightHelper(x->left), HeightHelper(x->right)) + 1;
	}
	node* SearchHelper(int x)
	{
		node* e = root;
		while (e != NULL)
		{
			if (e->value == x) return e;
			else if (x < e->value) e = e->left;
			else e = e->right;
		}
		return NULL;
	}
	node* MinimumFinder(node* x)
	{
		while (x->left != NULL)
			x = x->left;
		return x;
	}
	node* MaximumFinder(node* x)
	{
		while (x->right != NULL)
			x = x->right;
		return x;
	}
	void Transplant(node* a, node* b)
	{
		if (a == b) return;
		node* p = a->parent;
		if (p == NULL) //a is root node
			root = b;
		else if (a == p->left) //left child of parent
			p->left = b;
		else //right child parent
			p->right = b;
		if (b != NULL)
			b->parent = p;
	}
public:
	Tree()
	{
		root = NULL;
	}
	void Insert(int x)
	{
		node* new_node = new node{ x, NULL, NULL, NULL };
		if (root == NULL)
			root = new_node;
		else
		{
			// find a suitable place to insert
			node* p = root;
			node* c = root;
			while (c != NULL)
			{
				p = c;
				if (x < c->value)
					c = c->left;
				else
					c = c->right;
			}
			c = new_node;
			if (x < p->value)
				p->left = c;
			else
				p->right = c;
			c->parent = p;
		}
	}
	void InorderTraversal()
	{
		queue<int> st;
		InorderTraversalHelper(root, st);
		PrintTraversalHelper("Inorder Traversal", st);
	}
	void PreorderTraversal()
	{
		queue<int> st;
		PreorderTraversalHelper(root, st);
		PrintTraversalHelper("Preorder Traversal", st);
	}
	void PostorderTraversal()
	{
		queue<int> st;
		PostorderTraversalHelper(root, st);
		PrintTraversalHelper("Postorder Traversal", st);
	}
	int Height()
	{
		return HeightHelper(root);
	}
	bool Exists(int x)
	{
		return SearchHelper(x) != NULL;
	}
	node* Search(int x)
	{
		return SearchHelper(x);
	}
	node* Minimum()
	{
		return MinimumFinder(root);
	}
	node* Maximum()
	{
		return MaximumFinder(root);
	}
	node* Predecessor(node* x)
	{
		if (x->left != NULL)
			return MaximumFinder(x->left);
		while (x->parent != NULL && x != x->parent->right) // move up until x becomes the right child
			x = x->parent;
		return x->parent;
	}
	node* Successor(node* x)
	{
		if (x->right != NULL)
			return MinimumFinder(x->right);
		while (x->parent != NULL && x != x->parent->left) // move up until x becomes the left child
			x = x->parent;
		return x->parent;
	}
	void Delete(node* x)
	{
		if (x->right == NULL && x->left == NULL) // Case 1: No child is present
		{
			if (x->parent != NULL)
			{
				if (x == x->parent->left)
					x->parent->left = NULL;
				else
					x->parent->right = NULL;
			}
		}
		else if (x->left != NULL && x->right == NULL) // Case 2: only left child is present
		{
			Transplant(x, x->left);
		}
		else if (x->right != NULL && x->left == NULL) // Case 3: only right child is present
		{
			Transplant(x, x->right);
		}
		else // Case 4: both child are present
		{
			node* r_min = MinimumFinder(x->right); // take the minimum from right subtree, this will never have a left child
			if (r_min->parent != x)
			{
				Transplant(r_min, r_min->right); // replace this minimum with it's right child
				r_min->right = x->right; // put r_min in x's right
				r_min->right->parent = r_min;
			}
			Transplant(x, r_min);
			r_min->left = x->left;
			r_min->left->parent = r_min;
		}
		free(x);
	}
};

int main()
{
	Tree t;
	t.Insert(7);
	t.Insert(1);
	t.Insert(0);
	t.Insert(3);
	t.Insert(2);
	t.Insert(5);
	t.Insert(4);
	t.Insert(6);
	t.Insert(9);
	t.Insert(8);
	t.Insert(10);
	t.PreorderTraversal();
	t.InorderTraversal();
	t.PostorderTraversal();
	cout << "Tree Height: " << t.Height() << endl;
	bool sr = t.Exists(4);
	sr = t.Exists(11);
	node* min = t.Minimum();
	cout << "Tree Minimum: " << min->value << endl;
	node* max = t.Maximum();
	cout << "Tree Maximum: " << max->value << endl;
	int searchKey = 6;
	node* k = t.Search(searchKey);
	if (k != NULL)
	{
		node* p = t.Predecessor(k);
		node* s = t.Successor(k);
		cout << "Predecessor of " << k->value << ":  " << p->value << endl;
		cout << "Successor of " << k->value << ":  " << s->value << endl;
	}
	else
	{
		cout << "Key " << searchKey << " not found" << endl;
	}
	t.Delete(k);
	sr = t.Exists(searchKey);
}