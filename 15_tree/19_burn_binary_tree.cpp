/*
* Minimum time taken to burn a tree
* Solution: Convert tree to graph by adding parent pointers to a map. 
* Compute the dfs and the maximum distance will be the min time to burn
* Time Complexity: O(N), space complexity = O(N) due to the use of map, queue of space N
*/

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

unordered_map<node*, node*> parent;

void populate_parents(node* root)
{
	// perform a level order traveral and populate parents
	queue<node*> q;
	q.push(root);
	parent[root] = NULL;
	while (!q.empty())
	{
		node* curr = q.front();
		q.pop();
		if (curr->left != NULL)
		{
			parent[curr->left] = curr;
			q.push(curr->left);
		}
		if (curr->right != NULL)
		{
			parent[curr->right] = curr;
			q.push(curr->right);
		}
	}
}

int compute_bfs(node* start)
{
	unordered_map<node*, bool> discovery;
	unordered_map<node*, int> distance;
	queue<node*> q;
	int max_distance = 0;

	q.push(start);
	discovery[start] = true;
	distance[start] = 0;

	while (!q.empty())
	{
		node* curr = q.front();
		q.pop();
		vector<node*> adj = { curr->left, curr->right, parent[curr] };
		for (int i = 0; i < 3; i++)
		{
			if (adj[i] == NULL || discovery[adj[i]])
				continue;
			discovery[adj[i]] = true;
			distance[adj[i]] = distance[curr] + 1;
			max_distance = max(max_distance, distance[adj[i]]);
			q.push(adj[i]);
		}
	}
	return max_distance;
}

int time_to_burn_tree(node* root, node* start)
{
	populate_parents(root);
	return compute_bfs(start);
}

int main()
{
	node* root = new node{ 1, new node{ 2, NULL, NULL }, new node{ 3, new node{ 5, NULL, NULL }, new node{ 6, NULL, NULL } } };
	node* curr = root->left;
	curr->left = new node{ 4, NULL, NULL };
	curr->left->right = new node{ 7, NULL, NULL };

	cout << "time to burn tree: " << time_to_burn_tree(root, curr) << endl;
}