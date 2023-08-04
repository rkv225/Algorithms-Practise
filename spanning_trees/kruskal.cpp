/*
* Spanning is an acyclic subset of edges that connectes all of the vertices and their total sum of weight is minimum.
* It spans the entire graph. If we assume cities connected by roads and we want to paint roads in such a manner that all cities have painted road to other cities.
* The weight defines the paint required. Then,
* MST will find the minimum paint required to paint the roads.
*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

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
			return parent_x->value;
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
			x->parent = find_set_helper(x->parent); // this is path compression
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

struct Edge
{
public:
	int from;
	int to;
	int weight;
	Edge(int f, int t, int w)
	{
		from = f;
		to = t;
		weight = w;
	}
};

bool CompareEdge(Edge& a, Edge& b)
{
	return a.weight < b.weight;
}

class Graph
{
public:
	Graph(int x)
	{
		n = x;
		Adj.resize(x);
		for (int i = 0; i < n; i++)
			Adj[i].assign(x, 0);
	}
	void AddEdge(int u, int v, int w)
	{
		Adj[u][v] = Adj[v][u] = w;
	}
	void Kruskal()
	{
		SpanningTree.clear();

		// assign an each vertex to an individual set
		for (int i = 0; i < n; i++)
			Sets.make_set(i);

		// list all the edges
		vector<Edge> Edges;
		// only scanning the upper triangle as it is an undirectional tree
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (Adj[i][j] > 0)
					Edges.push_back(Edge(i, j, Adj[i][j]));

		// sort the edges in ascending order
		sort(Edges.begin(), Edges.end(), CompareEdge);

		// foreach edge add, union them if they don't belong to the same set
		for (vector<Edge>::iterator it = Edges.begin(); it != Edges.end(); it++)
		{
			Edge currEdge = *it._Ptr;
			int seta = Sets.find_set(currEdge.from);
			int setb = Sets.find_set(currEdge.to);
			if (seta != setb)
			{
				Sets.union_set(currEdge.from, currEdge.to);
				SpanningTree.push_back(currEdge);
			}
		}

		//print the spanning tree
		cout << "Spanning Tree:" << endl;
		for (vector<Edge>::iterator it = SpanningTree.begin(); it != SpanningTree.end(); it++)
			cout << (*it).from << "->" << (*it).to << "(" << (*it).weight << ")" << endl;
	}
private:
	vector<vector<int>> Adj;
	vector<Edge> SpanningTree;
	int n;
	DisjointSets Sets;
};

int main()
{
	Graph g(9);
	g.AddEdge(0, 1, 4);
	g.AddEdge(0, 7, 8);
	g.AddEdge(1, 2, 8);
	g.AddEdge(1, 7, 11);
	g.AddEdge(2, 3, 7);
	g.AddEdge(2, 5, 4);
	g.AddEdge(2, 8, 2);
	g.AddEdge(3, 4, 9);
	g.AddEdge(3, 5, 14);
	g.AddEdge(4, 5, 10);
	g.AddEdge(5, 6, 2);
	g.AddEdge(6, 7, 1);
	g.AddEdge(6, 8, 6);
	g.AddEdge(7, 8, 7);
	g.Kruskal();
	return 0;
}