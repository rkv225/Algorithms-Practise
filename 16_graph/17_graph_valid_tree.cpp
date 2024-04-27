/*
Problem:
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:
Input:
n = 5
edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output:
true

Example 2:
Input:
n = 5
edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output:
false

Solution: Perform a DFS operation from the first node as root of tree.
For a graph to be a tree it must not have a self loop and graph must be connected.
If after dfs operation we found a cycle or any unvisited node then we can say it's not a valid tree.

Link: https://neetcode.io/problems/valid-tree
*/

class Solution {
public:
    bool dfscycle(int v, int p, vector<int>& visit, vector<vector<int>>& adj) {
        visit[v] = 1;
        for(int i = 0; i < adj[v].size(); i++) {
            if(adj[v][i] != p) {
                if(visit[adj[v][i]] == 1) {
                    return true;
                }
                if(visit[adj[v][i]] == 0 && dfscycle(adj[v][i], v, visit, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visit(n, 0);
        // creating adjacency list
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bool cycle = dfscycle(0, -1, visit, adj);
        if(cycle)
            return false;
        bool unvisited = false;
        for(int i = 0; i < n; i++) {
            if(visit[i] == 0) {
                unvisited = true;
                break;
            }
        }
        if(unvisited)
            return false;
        // neither cycle exists nor there is any unvisited node after dfs    
        return true;
    }
};
