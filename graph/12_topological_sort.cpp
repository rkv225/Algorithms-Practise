/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/

#include<iostream>
#include<vector>
#include<forward_list>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL -999999
#define INF 999999

using namespace std;

class node
{
public:
	int value;
	int color;
	int discovery;
	int finished;
	int parent;
	node(int v, int c, int d, int f, int p)
	{
		value = v;
		color = c;
		discovery = d;
		finished = f;
		parent = p;
	}
};

class Graph
{
private:
	int n;
	int time;
	vector<node> Vertices;
	vector<vector<int>> Adj;
	vector<int> Traversal;
	forward_list<int> TopologicalSortList;
public:
	Graph(int x)
	{
		n = x;
		for (int i = 0; i < n; i++)
			Vertices.push_back(node(i, WHITE, INF, INF, NIL));
		Adj.resize(n);
	}
	void AddEdge(int u, int v) // u ---> v
	{
		Adj[u].push_back(v);
	}
	void DFSVisit(int u)
	{
		time++;
		Vertices[u].discovery = time; // time of discovery
		Vertices[u].color = GRAY; // paint gray as this is now discovered
		Traversal.push_back(u);
		for (vector<int>::iterator it = Adj[u].begin(); it != Adj[u].end(); it++)
		{
			if (Vertices[(*it)].color == WHITE) // we'll only visit undiscovered nodes
			{
				Vertices[(*it)].parent = u; // set the parent 
				DFSVisit(*it); // visit the undiscovered node
			}
		}
		Vertices[u].color = BLACK; // when all adjacent nodes are traversed, mark node as black
		time++;
		Vertices[u].finished = time; // store finishing time 
		TopologicalSortList.push_front(u);
	}
	void ComputeDFS()
	{
		time = 0;
		for (vector<node>::iterator it = Vertices.begin(); it != Vertices.end(); it++) // go for each node once in graph
		{
			if ((*it).color == WHITE)
				DFSVisit((*it).value);
		}
	}
	void print_traversal()
	{
		cout << "DFS Traversal:" << endl;
		for (vector<int>::iterator it = Traversal.begin(); it != Traversal.end(); it++)
			cout << *it << "(" << Vertices[(*it)].discovery << "/" << Vertices[(*it)].finished << ")" << endl;
	}
	void print_topological_sorted_order()
	{
		cout << "Topologcally sorted list:" << endl;
		for (forward_list<int>::iterator it = TopologicalSortList.begin(); it != TopologicalSortList.end(); it++)
			cout << *it << " ";
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
	g.ComputeDFS();
	g.print_traversal();
	g.print_topological_sorted_order();
	return 0;
}

/*
Problem: 
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]

Link: https://leetcode.com/problems/course-schedule-ii
*/

class Solution {
public:
    bool dfs(int v, int &o, vector<vector<int>> &adj, vector<int> &visit, vector<int> &order) {
        visit[v] = 1;
        for(vector<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++) {
            if(visit[*i] == 1)
                return true;
            if(visit[*i] == 0 && dfs(*i, o, adj, visit, order))
                return true;
        }
        visit[v] = 2;
        order[o--] = v;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visit(numCourses, 0);
        vector<int> order(numCourses, -1);
        for(vector<vector<int>>:: iterator i = prerequisites.begin(); i != prerequisites.end(); i++) {
            vector<int> cur = *i;
            adj[cur[1]].push_back(cur[0]);
        }
        bool isCycle = false;
        int o = numCourses - 1;
        for(int i = 0; i < numCourses; i++)
            if(visit[i] == 0 && dfs(i, o, adj, visit, order))
                isCycle = true;
        if(isCycle)
            order.clear();
        return order;
    }
};