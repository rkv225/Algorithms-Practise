#include<iostream>
#include<unordered_map>

using namespace std;
/*
* Disjoint forest implemented using hashmaps. This class will act as container for all sets and from calling side we will be only using values.
* This has two main mechanism that helps faster operations: 
* - path compression 
* - union by rank 
*/
class DisjointSets
{
public:
	void make_set(int x) // O(1)
	{
		if (nodes[x] == NULL)
		{
			node* new_node = new node{ 0, x, NULL };
			new_node->parent = new_node; // pointing self to parent
			nodes[x] = new_node;
		}
	}
	int find_set(int x) // O(h) - dependent on the height of tree
	{
		node* node_x = nodes[x];
		node* parent_x = find_set_helper(node_x);
		if (parent_x != NULL)
		{
			return parent_x->value;
		}
		return -1;
	}
	void union_set(int x, int y)
	{
		node* set_x = find_set_helper(nodes[x]);
		node* set_y = find_set_helper(nodes[y]);
		if (set_x != NULL && set_y != NULL)
		{
			if (set_x == set_y) //already in same set
				return;
			union_helper(set_x, set_y);
		}
	}

	void print_set()
	{
		unordered_map<int, node*>::iterator it = nodes.begin();
		while (it != nodes.end())
		{
			pair<int, node*>curr = *it;
			cout << curr.second->value << "->" << curr.second->parent->value << endl;
			it++;
		}
	}

private:
	struct node {
		int rank;
		int value;
		node* parent;
	};

	unordered_map<int, node*> nodes;

	node* find_set_helper(node* x)
	{
		if (x != NULL && x->parent->value != x->value)
		{
			x->parent = find_set_helper(x->parent); // this is path compression
		}
		return x->parent;
	}
	 
	void union_helper(node* x, node* y)
	{
		if (x->rank > y->rank)
		{
			y->parent = x->parent;
		}
		else
		{
			x->parent = y->parent;
			if (x->rank == y->rank)
			{
				x->rank++;
			}
		}
	}
};

int main()
{
	DisjointSets ds;
	ds.make_set(1);
	ds.make_set(2);
	ds.make_set(3);
	ds.make_set(4);
	ds.make_set(5);
	ds.make_set(6);
	ds.make_set(7);
	ds.make_set(8);

	int x;

	x = ds.find_set(5);
	x = ds.find_set(3);

	ds.union_set(5, 3);

	x = ds.find_set(5);
	x = ds.find_set(3);
	ds.print_set();
	return 0;
}