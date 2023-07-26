#include<iostream>
#include<vector>
#include<queue>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -99999
#define INF 99999

using namespace std;

class node
{
private:
	int val;
public:
	int color;
	int parent;
	int distance;

	node(int v, int c, int p, int d)
	{
		val = v;
		color = c;
		parent = p;
		distance = d;
	}
};

class Graph
{
private:
	int n;
	vector<node> Vertices;
	vector<vector<int>> Adj;
	vector<int> Traversal;
public:
	Graph(int x)
	{
		n = x;
		for (int i = 0; i < n; i++)
			Vertices.push_back(node(i, WHITE, NIL, INF));
		Adj.resize(n);
	}
	void AddEdge(int u, int v) // u ---> v
	{
		Adj[u].push_back(v);
	}
	void ComputeBFS(int s)
	{
		queue<int> Q; // declare a queue

		// for the start vertex
		Vertices[s].color = GRAY; // paint gray
		Vertices[s].distance = 0; // mark distance as 0
		Vertices[s].parent = NIL; // set the parent as nil
		Q.push(s); // push start to queue
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			Traversal.push_back(x);
			for (vector<int>::iterator it = Adj[x].begin(); it != Adj[x].end(); it++) // foreach adjacent node to the current vertex
			{
				if (Vertices[*it].color == WHITE) // proceed only if the node is not yet explored
				{
					Vertices[*it].color = GRAY;
					Vertices[*it].distance = Vertices[x].distance + 1;
					Vertices[*it].parent = x;
					Q.push(*it);
				}
			}
			Vertices[x].color = BLACK; // paint node as black to mark it as completed
		}
	}
	void print_traversal()
	{
		cout << "BFS Traversal:" << endl;
		for (vector<int>::iterator it = Traversal.begin(); it != Traversal.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	void print_path(int dest)
	{
		if (Vertices[dest].parent != NIL)
			print_path(Vertices[dest].parent);
		cout << dest << "->";
	}
};

int main()
{
	Graph g(6);
	g.AddEdge(0, 1);
	g.AddEdge(0, 3);
	g.AddEdge(1, 2);
	g.AddEdge(1, 4);
	g.AddEdge(2, 4);
	g.AddEdge(2, 5);
	g.AddEdge(3, 1);
	g.AddEdge(4, 3);
	g.AddEdge(5, 5);
	g.ComputeBFS(0);
	g.print_traversal();
	g.print_path(4);
	return 0;
}