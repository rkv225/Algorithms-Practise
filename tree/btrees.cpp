/*
* B Tree has a branching factor of 50 to 2000 which leads to less height and number of disk access it requires. 
* B Tree Properties:
* a. x.n number of keys are stored in node x in ascending order with x.leaf denoting internal or leaf node.
* b. node x also contains x.n+1 pointers to it's children. Leaf nodes have no children.
* c. For degree t >= 2, every node other than root must have atleast t-1 keys and atmost 2t-1 keys.
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node(int t)
	{
		n = 0;
		leaf = false;
		key.assign(2 * t - 1, 0);
		child.assign(2 * t, NULL);
	}

	int n; // number of keys
	bool leaf;
	vector<int> key;
	vector<Node*> child;
};

class BTree
{
public:
	BTree(int d)
	{
		t = d;
		root = AllocateNode();
		root->leaf = true;
	}
	void Traverse()
	{
		TraverseHelper(root, NULL);
	}
	bool Search(int k)
	{
		Node* cur = root;
		bool finished = false;
		while (!finished)
		{
			int i = 0;
			while (cur->key[i] < k && i < cur->n)
				i++;
			if (i < cur->n && cur->key[i] == k)
				return true;
			if (cur->leaf)
				finished = true;
			else
				cur = cur->child[i];
		}
		return false;
	}
	void Insert(int k)
	{
		Node* r = root;
		if (r->n == 2 * t - 1)
		{
			Node* s = AllocateNode();
			root = s; // set tree root as newly created node
			s->child[0] = r;
			SplitChild(s, 0);
			r = s;
		}
		InsertNonFull(r, k);
	}
	void Delete(int k)
	{

	}
private:
	void SplitChild(Node* x, int i)
	{
		// splitting a node with keys 2t-1 => t-1 + t-1 + 1
		// each node will have t-1 keys
		// 1 key will move to parent node

		Node* y = x->child[i];
		Node* z = AllocateNode();

		z->n = t - 1;
		z->leaf = y->leaf;

		// move t-1 keys from right side of y to z
		for (int j = 0; j < t - 1; j++)
		{
			z->key[j] = y->key[t + j];
			y->key[t + j] = 0;
		}

		// move t children from right if y is not leaf
		if (!y->leaf)
			for (int j = 0; j < t; j++)
			{
				z->child[j] = y->child[j + t];
				y->child[j + t] = NULL;
			}

		int mid = y->key[t - 1];
		y->key[t - 1] = 0;
		y->n = t - 1; // update the size of y

		// updating the parent
		for (int j = x->n - 1; j >= i; j--) // make space for new key
			x->key[j + 1] = x->key[j];
		x->key[i] = mid; // insert key
		for (int j = x->n; j >= j + 1; j--) // make space for new child
			x->child[j + 1] = x->child[j];
		x->child[i + 1] = z; // insert child
		x->n = x->n + 1; // update size of x
	}
	void InsertNonFull(Node* x, int k)
	{
		int j = 0;
		while (x->key[j] < k && j < x->n)
			j++;
		if (k == x->key[j]) // not allowing duplicate keys
			return;
		if (x->leaf)
		{
			for (int i = x->n - 1; i >= j; i--) // shift keys
				x->key[i + 1] = x->key[i];
			x->key[j] = k; // insert key
			x->n = x->n + 1;
		}
		else
		{
			// find appropriate leaf node to insert key
			if (x->child[j]->n == 2 * t - 1) // split if full
			{
				SplitChild(x, j);
				if (x->key[j] < k)
					j++;
			}
			InsertNonFull(x->child[j], k);
		}
	}
	void TraverseHelper(Node* r, Node* p)
	{
		cout << "Parent Node: ";
		if (p != NULL)
			for (int i = 0; i < p->n; i++)
				cout << p->key[i] << " ";
		cout << " ==> ";
		for (int i = 0; i < r->n; i++)
			cout << r->key[i] << " ";
		cout << endl;
		if (!r->leaf)
			for (int i = 0; i <= r->n; i++)
				TraverseHelper(r->child[i], r);
	}

	Node* AllocateNode()
	{
		return new Node(t);
	}

	int t; // degree of btree
	Node* root; // root node of tree
};

int main()
{
	BTree t(3);
	
	t.Insert(8);
	t.Insert(9);
	t.Insert(10);
	t.Insert(11);
	t.Insert(15);
	t.Insert(16);
	t.Insert(17);
	t.Insert(18);
	t.Insert(20);
	t.Insert(23);

	t.Traverse();

	return 0;
}