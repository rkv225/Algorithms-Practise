/*
Problem: 
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1: 
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

Solution: 
Create a disjoint set. 
Foreach edge
Take nodes from edge.
If they don't belong to same set then union them. 
If they belong to a same set then we have a cycle if we take that edge.

Link: https://leetcode.com/problems/redundant-connection/
*/

class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    void MakeSet(int x) { 
        if (parent.find(x) != parent.end()) 
            return; 
        parent[x] = x; 
        rank[x] = 0; 
    }
    int FindSet(int x) { 
        if (x != parent[x]) 
            parent[x] = FindSet(parent[x]); 
        return parent[x]; 
    }
    void UnionSet(int x, int y) {
        int sx = FindSet(x);
        int sy = FindSet(y);
        if (sx == sy)
            return;
        if (rank[sx] >= rank[sy]) { 
            parent[sy] = sx; 
            rank[sx]++; 
        }
        else { 
            parent[sx] = sy; 
            rank[sy]++; 
        }
    }
    bool Cycle(int x, int y) { 
        return FindSet(x) == FindSet(y);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            MakeSet(edges[i][0]);
            MakeSet(edges[i][1]);
            if (Cycle(edges[i][0], edges[i][1]))
                return edges[i];
            UnionSet(edges[i][0], edges[i][1]);
        }
        return {};
    }
};