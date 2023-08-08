/*
* Dijkstra's algorithm solves single source shortest path problem. This follows the strategy to relax all the adjacent nodes till all the nodes are visited.
* We keep a map to set the vertices visited and a priority queue to always take the vertex with minimum weight.
* This only works for edges with non negative weight
*/
#include<iostream>
#include<vector>
#include<queue>
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

class MaxNode
{
public:
	int operator() (const Node& a, const Node& b)
	{
		return a.key > b.key;
	}
};

class Graph
{
public:
	Graph(int x)
	{
		n = x;
		Adj.resize(n);
		V.reserve(n);
		W.resize(n);
		Visited.assign(n, false);
		for (int i = 0; i < n; i++)
		{
			V.push_back(Node(i));
			W[i].assign(n, 0);
		}
	}
	void AddEdge(int u, int v, int w)
	{
		Adj[u].push_back(v);
		W[u][v] = w;
	}
	void Dijkstra(int s)
	{
		V[s].key = 0;
		PQ.push(V[s]);
		while (!PQ.empty())
		{
			int u = (PQ.top()).val;
			PQ.pop();
			Visited[u] = true;
			for (vector<int>::iterator vit = Adj[u].begin(); vit != Adj[u].end(); vit++)
			{
				int v = *vit;
				if (!Visited[v] && V[u].key + W[u][v] < V[v].key)
				{
					V[v].key = V[u].key + W[u][v];
					V[v].parent = u;
					PQ.push(V[v]); // push to queue
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
		cout << "(destination)";
	}
private:
	int n;
	vector<vector<int>> Adj; // adj list
	vector<vector<int>> W; // edge weight
	vector<Node> V; // vertices
	vector<bool> Visited; // visited nodes
	priority_queue<Node, vector<Node>, MaxNode> PQ; // priority queue will help in picking least weighted node as we modify the keys
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
	g.Dijkstra(0);
	g.print_path(5);
	return 0;
}