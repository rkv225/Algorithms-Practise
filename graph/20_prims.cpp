/*
* Prim's algorithm follows strategy to traverse smallest weighted edge to unvisited nodes till all the nodes are visited.
* This follows dijkstra's strategy of shortest path with all nodes key set to INF and then relaxing each one of them till all nodes are visited.
*/
#include<iostream>
#include<vector>
#include<queue>

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
	int operator() (const Node &a, const Node &b)
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
		Adj[v].push_back(u);
		W[u][v] = W[v][u] = w;
	}
	void Prims(int s)
	{
		V[s].key = 0;
		PQ.push(V[s]);
		while (!PQ.empty())
		{
			Node node_u = PQ.top();
			int u = node_u.val;
			PQ.pop();
			if (!Visited[u])
			{
				Visited[u] = true; // mark as visited
				cout << V[u].parent << "->" << u << endl;
			}
			for (vector<int>::iterator vit = Adj[u].begin(); vit != Adj[u].end(); vit++)
			{
				int v = *vit;
				if (!Visited[v] && W[u][v] < V[v].key)
				{
					V[v].parent = u;
					V[v].key = W[u][v];
					PQ.push(V[v]); // push to queue
				}
			}
		}
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
	cout << "Prim's spanning tree:" << endl;
	g.Prims(0);
	return 0;
}