/*
* Detect cycle in a directed graph
* Solution: 
* 1. Paint all nodes as white
* 2. As we discover any node, mark it as gray
* 3. As we have fully visited all neighbors of a any node, mark black
* 4. If any gray node is encountered while performing dfs visit, then a cycle is present
* Time complexity: O(V+E)
*/

#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

bool dfs_visit(int vertex, vector<int> adj[], vector<int>& visit)
{
    visit[vertex] = GRAY;
    for (vector<int>::iterator it = adj[vertex].begin(); it != adj[vertex].end(); it++)
    {
        if (visit[*it] == GRAY)
            return true;
        if (visit[*it] == WHITE && dfs_visit(*it, adj, visit))
            return true;
    }
    visit[vertex] = BLACK;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visit(V, WHITE);
    for (int i = 0; i < V; i++)
        if (visit[i] == WHITE && dfs_visit(i, adj, visit))
            return true;
    return false;
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
    adj[4].push_back(2);

    bool x = isCyclic(5, adj);
}