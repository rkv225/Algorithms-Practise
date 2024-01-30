/*
Problem:
There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.
Return the total number of connected components in that graph.

Example 1:
Input:
n=3
edges=[[0,1], [0,2]]
Output:
1

Example 2:
Input:
n=6
edges=[[0,1], [1,2], [2, 3], [4, 5]]
Output:
2

Solution: 
Approach 1: Using DFS we can find the number of times we called dfs O(V+E) time & O(V) space
Approach 2: Using disjoijnt sets O(E) time and O(V) space:
Make set of all the vertices and then as you take an edge
if vertices don't belong to same set then union and decrement the number of nodes  
at the end you will be left with the number of connected groups

Link: https://neetcode.io/problems/count-connected-components

Time Complexity: O(E)

Space Complexity: O(V)
*/

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int findset(int x) {
        if(x != parent[x])
            parent[x] = findset(parent[x]);
        return parent[x];
    }
    void makeset(int x) {
        if(parent.find(x) != parent.end())
            return; // already exists
        parent[x] = x;
        rank[x] = 0;
    }
    bool unionset(int x, int y) {
        int xs = findset(x);
        int ys = findset(y);
        if(xs == ys)
            return false; // already in same set
        if(rank[xs] >= rank[ys]) {
            parent[ys] = xs;
            rank[xs]++;
        }
        else {
            parent[xs] = ys;
            rank[ys]++;
        }
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int result = n;
        for(int i = 0; i < edges.size(); i++) {
            makeset(edges[i][0]);
            makeset(edges[i][1]);
            if(unionset(edges[i][0], edges[i][1]))
                result--;
        }
        return result;
    }
};

