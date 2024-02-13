/*
* Floyd Warshall algorithm uses dynamic programming approach for all pair of shortest path in a graph.
* We assume that there is an intermediate vertex k between u & v, for V vertices on the shortest path from u to v.
* We can define the above as, u ~> k ~> v. d(u,v)=d(u,k)+d(k,v)
* We increase the value of k till V.count and if d(u,v) > d(u,k) + d(k,v) then we assign d(u,v) new distance.
* Analysis: for v vertices we go from k = 1 to V.count = O(V)
* and traverse the graph(assuming adjacency matrix) = O(V^2) 
* Then overall complexity = O(V^3)
*/

#include<iostream>
#include<vector>

#define INF 999999
#define NIL -999999

using namespace std;

class Graph
{
private:
	int n;
	vector<vector<int>> Adj;
	vector<vector<int>> Parent;

	void PrintPathHelper(int s, int d)
	{
		if (s == d)
		{
			cout << s << "->";
			return;
		}
		int k = Parent[s][d];
		if (Adj[s][d] < INF && k != NIL)
		{
			PrintPathHelper(s, k);
				if (s != k)
					PrintPathHelper(k, d);
		}	
	}
public:
	Graph(int x)
	{
		n = x;
		Adj.resize(n);
		Parent.resize(n);
		for (int i = 0; i < n; i++)
		{
			Adj[i].assign(n, INF);
			Parent[i].assign(n, NIL);
		}
	}
	void AddEdge(int u, int v, int w)
	{
		Adj[u][v] = w;
		Parent[u][v] = u;
	}
	void FloydWarshall()
	{
		for (int i = 0; i < n; i++) // no self loops
			Adj[i][i] = 0;
		for (int k = 0; k < n; k++)
			for (int u = 0; u < n; u++)
				for (int v = 0; v < n; v++)
					if (Adj[u][v] > Adj[u][k] + Adj[k][v])
					{
						Adj[u][v] = Adj[u][k] + Adj[k][v];
						Parent[u][v] = k;	
					}
	}
	void PrintPath(int source, int dest)
	{
		cout << "Source = " << source << endl;
		PrintPathHelper(source, dest);
		cout << dest << "\nDestination = " << dest << endl << "Distance = " << Adj[source][dest];
	}
};

int main()
{
	Graph g(4);
	g.AddEdge(0, 1, 3);
	g.AddEdge(0, 3, 5);
	g.AddEdge(1, 0, 2);
	g.AddEdge(1, 3, 4);
	g.AddEdge(2, 1, 1);
	g.AddEdge(3, 2, 2);
	g.FloydWarshall();
	g.PrintPath(2, 0);
	return 0;
}
