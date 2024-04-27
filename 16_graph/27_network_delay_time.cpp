/*
Problem:
You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

Solution: apply dijkstra for finding paths to all vertices from source vertex k. Then return the maximum of all the paths. 
If there is any unvisited then return -1.

Time complexity: O(v^2)
space complexity: O(V^2) for storing adjacency matrix

Link: https://leetcode.com/problems/network-delay-time
*/

class Solution {
public:
    class Node
    {
    public:
        int val;
        int parent;
        int key;
        Node(int x)
        {
            val = x;
            parent = -1;
            key = 1e8;
        }
    };
    class MaxNode
    {
    public:
        int operator() (const Node& a, const Node& b)
        {
            return a.key > b.key;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> visit(n + 1, 0);
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));
        // create adjacency matrix
        for(int i = 0; i < times.size(); i++)
            adj[times[i][0]][times[i][1]] = times[i][2];
        // keep all vertex in a vector
        vector<Node> V;
        V.reserve(n + 1);
        V.push_back(Node(0));
        for(int i = 1; i <= n; i++) 
            V.push_back(Node(i));
        priority_queue<Node, vector<Node>, MaxNode> pq;
        // apply dijkstra algorithm to find shortest path to all vertex from source k
        V[k].key = 0;
        pq.push(V[k]);
        while(!pq.empty()) {
            int cur = (pq.top()).val;
            pq.pop();
            visit[cur] = 1;
            for(int i = 1; i <= n; i++) {
                if(adj[cur][i] >= 0 && visit[i] == 0 && V[cur].key + adj[cur][i] < V[i].key) { // if adjacent, not visited and distance is less than current distance
                    V[i].key = V[cur].key + adj[cur][i];
                    V[i].parent = cur;
                    pq.push(V[i]);
                }
            }
        }
        // find maximum path and return
        int ans = -1e8;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, V[i].key);
        }
        if(ans >= 1e8)
            return -1;
        return ans;
    }
};