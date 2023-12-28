#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topological_order;
vector<int> indegree_map;

void populate_indegree(int v, vector<int> adj[])
{
	indegree_map.assign(v, 0);
	for (int i = 0; i < v; i++)
		for (vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
			indegree_map[*it]++;
}

void kahn_topological_sort(int v, vector<int> adj[])
{
	queue<int> q;
	populate_indegree(v, adj);
	// put all nodes with initial in-degree = 0
	for (int i = 0; i < v; i++)
		if (indegree_map[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topological_order.push_back(u);
		for (vector<int>::iterator a = adj[u].begin(); a != adj[u].end(); a++)
		{
			indegree_map[*a]--;
			if (indegree_map[*a] == 0)
				q.push(*a);
		}
	}
}

int main()
{
	// vertices
	vector<int> adj[5];

	// edges
	adj[0].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[2].push_back(4);

	kahn_topological_sort(5, adj);
	for (int i = 0; i < 5; i++)
		cout << topological_order[i] << " ";
}