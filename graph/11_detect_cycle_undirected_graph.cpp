/*
* Detect cycle in an undirected graph
* Solution: perform a dfs operation and if u discover a visited node except for the parent of current node
* then we can say that there is cycle in graph
* Time complexity: O(V+E)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool dfs_visit(int vertex, int parent, vector<int> adj[], vector<bool>& visited)
    {
        visited[vertex] = true;
        for (vector<int>::iterator it = adj[vertex].begin(); it != adj[vertex].end(); it++)
        {
            if (*it == parent)
                continue;
            if (visited[*it])
                return true;
            if (dfs_visit(*it, vertex, adj, visited))
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V, false);
        for (int i = 0; i < V; i++)
            if (!visited[i] && dfs_visit(i, -1, adj, visited))
                return true;
        return false;
    }
};

int main()
{
    // vertices
    vector<int> adj[5];
    
    // edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(4);
    adj[4].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    bool ans = obj.isCycle(5, adj);
}