/*
* Bellman ford algorithm solves single source shortest path problem in general case in which edge weight may be negative.
* bellman ford returns a boolean value depending upon the presence of "negative weight cycle" that is reachable from the source.
* If there exsts a negative weight cycle then no solution exists.
* We keep on relaxing edges(taken in any order) until we have the shortest path from source. This process runs for V-1 times for V vertices.
* It takes into account if we have 3 vertices we have minimum 2 edges if taken in a single line. If we relax the edges we will need at max 2 passes to propagate.
* If there exists a path shorter than we have found after V-1 passes then we can say that ithas a negative weight cycle.
* If you keep on relaxing then you will notice that distance will keep on decreasing.
* Analysis: for v vertices we visit each edge e v-1 times. So complexity = O(VE)
*/
#include<iostream>
#include<vector>
#include<stack>

#define INF 999999
#define NIL -999999

using namespace std;

class Node
{
public:
	int val;
	int parent;
	int key;
	Node(int x)
	{
		val = x;
		parent = NIL;
		key = INF;
	}
};

class Edge
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

class Graph
{
public:
	Graph(int x)
	{
		n = x;
		V.reserve(n);
		for (int i = 0; i < n; i++)
			V.push_back(Node(i));
	}
	void AddEdge(int u, int v, int w)
	{
		E.push_back(Edge(u, v, w));
	}
	bool BellmanFord(int s)
	{
		V[s].key = 0; // set source distance to 0
		for (int pass = 0; pass < n - 1; pass++)
		{
			for (vector<Edge>::iterator edge_it = E.begin(); edge_it != E.end(); edge_it++)
			{
				int u = (*edge_it).from;
				int v = (*edge_it).to;
				int w = (*edge_it).weight;
				if (V[u].key + w < V[v].key)
				{
					V[v].key = V[u].key + w;
					V[v].parent = u;
				}
			}
		}
		for (vector<Edge>::iterator edge_it = E.begin(); edge_it != E.end(); edge_it++)
		{
			int u = (*edge_it).from;
			int v = (*edge_it).to;
			int w = (*edge_it).weight;
			if (V[u].key + w < V[v].key)
			{
				// we have a negative weight cycle present in the graph, so we abort
				return false;
			}
		}
		return true; // our algorithm ran successfully and we have found the shortest paths
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
	vector<Edge> E; // edges
	vector<Node> V; // vertices
};

int main()
{
	Graph g(9);
	g.AddEdge(0, 1, 6);
	g.AddEdge(0, 3, 7);
	g.AddEdge(1, 2, 5);
	g.AddEdge(1, 3, 8);
	g.AddEdge(1, 4, -4);
	g.AddEdge(2, 1, -2);
	g.AddEdge(4, 2, 7);
	g.AddEdge(4, 0, 2);
	g.AddEdge(3, 2, -3);
	g.AddEdge(3, 4, 9);
	bool res = g.BellmanFord(0);
	if (res)
		g.print_path(4);
	return 0;
}