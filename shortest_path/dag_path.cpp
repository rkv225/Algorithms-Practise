/*
* For DAG if we take the vertices in topologically sorted order, we can easily calculate shortest path by relaxing the edges of vertex. 
* As there are no cycles present, even with the negative weighted edges this gives correct results.
* Analysis: topological sort take O(V+E) and for each vertex we go by each edge. It also takes O(V+E), So total complexity = O(V+E)
*/
#include<iostream>
#include<vector>
#include<forward_list>
#include<stack>

#define INF 999999
#define NIL -999999
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class node
{
public:
	int val;
	int key;
	int parent;
	int color;
	node(int v)
	{
		val = v;
		key = INF;
		parent = NIL;
		color = WHITE;
	}
};

class Graph
{
public:
	Graph(int x)
	{
		n = x;
		Adj.resize(n);
		W.resize(n);
		V.reserve(n);
		for (int i = 0; i < n; i++)
		{
			W[i].assign(n, NIL);
			V.push_back(node(i));
		}
	}
	void AddEdge(int from, int to, int weight)
	{
		Adj[from].push_back(to);
		W[from][to] = weight;
	}
	void DagShortestPath(int s)
	{
		TopologicalSort();
		V[s].key = 0;
		for (forward_list<int>::iterator tp = topological_order.begin(); tp != topological_order.end(); tp++)
		{
			for (vector<int>::iterator ae = Adj[*tp].begin(); ae != Adj[*tp].end(); ae++)
			{
				if (V[*tp].key + W[*tp][*ae] < V[*ae].key)
				{
					V[*ae].key = V[*tp].key + W[*tp][*ae];
					V[*ae].parent = *tp;
				}
			}
		}
	}
	void print_path(int dest)
	{
		stack<int> path;
		int v = dest;
		while (V[v].parent != NIL)
		{
			path.push(v);
			v = V[v].parent;
		}
		path.push(v);
		cout << "\nStart";
		while (!path.empty())
		{
			v = path.top();
			path.pop();
			cout << "->" << v;
		}
		cout << "(destination), distance = " << V[dest].key;
	}
private:
	int n;
	vector<vector<int>> Adj;
	vector<vector<int>> W;
	vector<node> V;
	forward_list<int> topological_order;
	
	void TopologicalSort()
	{
		for (int i = 0; i < n; i++)
		{
			if (V[i].color == WHITE)
			{
				DFSVisit(i);
			}
		}
	}
	void DFSVisit(int s)
	{
		V[s].color = GRAY;
		for (vector<int>::iterator it = Adj[s].begin(); it != Adj[s].end(); it++)
		{
			if (V[*it].color == WHITE)
			{
				DFSVisit(*it);
			}
		}
		V[s].color = BLACK;
		topological_order.push_front(s);
	}
};

int main()
{
	Graph g(6);
	g.AddEdge(0, 1, 5);
	g.AddEdge(0, 2, 3);
	g.AddEdge(1, 2, 2);
	g.AddEdge(1, 3, 6);
	g.AddEdge(2, 3, 7);
	g.AddEdge(2, 4, 4);
	g.AddEdge(2, 5, 2);
	g.AddEdge(3, 4, -1);
	g.AddEdge(3, 5, 1);
	g.AddEdge(4, 5, -2);
	g.DagShortestPath(1);
	g.print_path(0);
	return 0;
}