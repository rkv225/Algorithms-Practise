/*
* Strongly connected components of a graph
* G = (v, E) is a maximal set of vertices C ⃀ V 
* such that every pair of vertices u and v in C, 
* we have both u ~> v and v ~> u
* i.e. vertices u and v are reachable from eachother
*/
#include<iostream>
#include<vector>
#include<stack>

#define NIL -999999
#define INF 999999
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

class node
{
public:
	int val;
	int color;
	int discovered;
	int finished;
	int parent;
	node(int v)
	{
		val = v;
		reset();
	}
	void reset()
	{
		color = WHITE;
		parent = NIL;
		discovered = INF;
		finished = INF;
	}
};

class Graph
{
private:
	int n;
	int time;
	vector<int> CurrentSet;
	void DFSVisit(int v)
	{
		time++;
		Vertices[v].color = GRAY;
		Vertices[v].discovered = time;
		for (int i = 0; i < n; i++)
		{
			if (AdjMat[v][i] == 1 && Vertices[i].color == WHITE) // if node is adjacent to the traversing node and is undiscovered
			{
				Vertices[i].parent = v;
				DFSVisit(i);
			}
		}
		Vertices[v].color = BLACK;
		time++;
		Vertices[v].finished = time;
		Finishing.push(v);
		CurrentSet.push_back(v);
	}
	void ResetState()
	{
		time = 0;
		for (int i = 0; i < n; i++)
			Vertices[i].reset();
	}
	void TransposeMat()
	{
		// transpose in place by interchanging upper triangle with lower triangle of square matrix
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				swap(AdjMat[i][j], AdjMat[j][i]);
	}
public:
	vector<vector<int>> AdjMat;
	vector<node> Vertices;
	stack<int> Finishing;

	Graph(int x)
	{
		n = x;
		time = 0;
		// creating a n x n vector having all values equal to 0
		AdjMat.resize(n);
		Vertices.reserve(n);
		for (int i = 0; i < n; i++)
		{
			AdjMat[i].assign(n, 0);
			Vertices.push_back(node(i));
		}
	}
	void AddEdge(int from, int to)
	{
		AdjMat[from][to] = 1;
	}
	void ComputeDFS()
	{
		time = 0;
		for (int i = 0; i < n; i++) // for each vertex in graph
		{
			if (Vertices[i].color == WHITE)
				DFSVisit(i);
		}
	}
	void StronglyConnectedComponents()
	{
		ComputeDFS(); // compute DFS and push nodes to stack as they finish, most recently finished will be on top of stack
		TransposeMat(); // reverse the edges
		ResetState(); // clear the dfs colors, parent, times
		// now once again compute dfs 
		// but in the decreasing order of finishing time from the first DFS call 
		while (!Finishing.empty())
		{
			CurrentSet.clear();
			int v = Finishing.top();
			Finishing.pop();
			if (Vertices[v].color == WHITE)
			{
				cout << "\nSet" << "->";
				DFSVisit(v);
				for (vector<int>::iterator it = CurrentSet.begin(); it != CurrentSet.end(); it++)
					cout << *it << " ";
			}
		}
	}
};

int main()
{
	Graph g(8);
	g.AddEdge(0, 1);
	g.AddEdge(1, 2);
	g.AddEdge(1, 4);
	g.AddEdge(1, 5);
	g.AddEdge(2, 3);
	g.AddEdge(2, 6);
	g.AddEdge(3, 2);
	g.AddEdge(3, 7);
	g.AddEdge(4, 0);
	g.AddEdge(4, 5);
	g.AddEdge(5, 6);
	g.AddEdge(6, 5);
	g.AddEdge(6, 7);
	g.AddEdge(7, 7);
	g.StronglyConnectedComponents();
}