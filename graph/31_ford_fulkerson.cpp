/*
* Ford Fulkerson Algorithm for finding maimum flow for a graph G(V,E)
* Edges represent maximum capacity of edge. We define flow as the content that can flow through source to sink.
* Source represented by s has all outgoing edges while sink t has al incoming edges.
* Algorithm `goes like this:
* We initialize flow of all edges to 0. We have all the capacity initialized to a residual graph. 
* We then find an augmenting path from s to t on residual graph using dfs to get a bottleneck edge.
* We subtract the bottleneck capacity from residual graph and add to flow graph.
* Analysis: DFS = O(V+E), f* dennotes the maximum flow in the transformed network. If we assume that flow value increases by atleast 1 unit in each iteration, 
* so while loop executes atmost |f*| times. If in a residual graph we assume the time to find path O(V+E) = O(E).
* Total Complexity: O(E|f*|)
*/

#include<iostream>
#include<vector>
#include<stack>

#define BLACK 2
#define GRAY 1
#define WHITE 0
#define NIL -999999
#define INF 999999

using namespace std;

class node
{
public:
	int val;
	int color;
	int parent;
	node(int v)
	{
		val = v;
		color = WHITE;
		parent = NIL;
	}
	
	void reset_node()
	{
		color = WHITE;
		parent = NIL;
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
		F.resize(n);
		R.resize(n);
		for (int i = 0; i < n; i++)
		{
			Adj[i].assign(n, 0);
			V.push_back(node(i));
			F[i].assign(n, 0);
			R[i].assign(n, 0);
		}
		BottleneckEdge = INF;
	}
	
	void AddEdge(int u, int v, int w)
	{
		Adj[u][v] = w;
	}
	
	int FordFulkerson(int s, int t)//this return the maximum flow from s to t
	{
		// initialize residual graph
		for (int i = 0; i < n;i++)
			for (int j = 0; j < n; j++)
				R[i][j] = Adj[i][j];

		while (DFS(s,t)) // while there is an augmenting path available in residual graph
		{
			BottleneckEdge = INF;
			int curr = t;
			// get bottleneck edge
			while (curr != s)
			{
				int v = curr;
				int u = V[curr].parent;
				BottleneckEdge = min(BottleneckEdge, R[u][v]);
				curr = u;
			}
			curr = t;
			while (curr != s)
			{
				int v = curr;
				int u = V[curr].parent;
				R[u][v] = R[u][v] - BottleneckEdge; // subtract the bottleneck value from residual graph
				F[u][v] = F[u][v] + BottleneckEdge; // increment the flow in flow graph
				curr = u;
			}
		}
		int flowSum = 0;
		for (int i = 0; i < n; i++) // add all the flow from source to get the maximum flow from flow graph
			flowSum = flowSum + F[s][i];
		return flowSum;
	}

private:
	int n;
	vector<vector<int>> Adj; // adjacency matrix
	vector<node> V; // list of vertices
	vector<vector<int>> F; // flow graph
	vector<vector<int>> R; // residual graph
	int BottleneckEdge; // bottleneck edge value

	bool DFS(int s, int t)
	{
		// reset all the nodes
		for (int i = 0; i < n; i++)
			V[i].reset_node();

		bool pathExists = false;
		stack<int> st;
		st.push(s);
		while (!st.empty())
		{
			int curr = st.top();
			st.pop();
			V[curr].color = GRAY;
			for (int a = 0; a < n; a++)
			{
				if (R[curr][a] > 0 && V[a].color == WHITE)
				{
					V[a].parent = curr;
					st.push(a);
				}
			}
			V[curr].color = BLACK;
			if (curr == t)
			{
				pathExists = true;
				break;
			}
		}
		return pathExists;
	}
};

int main()
{
	Graph g(6);
	g.AddEdge(0, 1, 16);
	g.AddEdge(0, 2, 13);
	g.AddEdge(1, 3, 12);
	g.AddEdge(2, 1, 4);
	g.AddEdge(2, 4, 14);
	g.AddEdge(3, 2, 9);
	g.AddEdge(3, 5, 20);
	g.AddEdge(4, 3, 7);
	g.AddEdge(4, 5, 4);
	int flow = g.FordFulkerson(0, 5);
	cout << "Maximum flow of graph:" << flow << endl;
	return 0;
}