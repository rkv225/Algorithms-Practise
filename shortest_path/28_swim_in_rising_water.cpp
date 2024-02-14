/*
Problem:
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

Solution:
Assume each block to be a node.
We will store time in the key value of node.
Initially the value of source node will be the key and we have to reach to bottom right node.
We will apply dijstra's algorithm and and adjacent weight will be calculated as:
if adjacent node value > current node key then weight will be the difference 
else 0
Finally the key of the node[n - 1][n - 1] will have the answer.

Time complexity: As we have used adjacency matrix O(V^2)

Space Complexity: O(V^2) for storing adjacency matrix. O(V) for min heap.

Link: https://leetcode.com/problems/swim-in-rising-water
*/

class Solution {
    public:
    class node {
    public:
        int i;
        int j;
        int k;
        node(int i, int j, int k) {
            this->i = i;
            this->j = j;
            this->k = k;
        }
    };
    bool in_grid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    // comparator for min heap
    class comparator {
    public:
        int operator() (const node& a, const node& b) {
            return a.k > b.k;
        }
    };
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, 0));
        vector<vector<int>> keys(n, vector<int>(n, 1e8));
        priority_queue<node, vector<node>, comparator> pq;
        vector<int> dx = { -1, 0, 1, 0 }; // left, top, right, bottom
        vector<int> dy = { 0, -1, 0, 1};
        pq.push(node(0, 0, grid[0][0]));
        keys[0][0] = grid[0][0];
        while(!pq.empty()) {
            node cur = pq.top();
            pq.pop();
            visit[cur.i][cur.j] = 1;
            for(int d = 0; d < 4; d++) {
                int xi = cur.i + dx[d];
                int yj = cur.j + dy[d];
                if(in_grid(xi, yj, n) && !visit[xi][yj]) {
                    int f = cur.k < grid[xi][yj] ? grid[xi][yj] - cur.k : 0;
                    if(cur.k + f < keys[xi][yj]) {
                        keys[xi][yj] = cur.k + f;
                        pq.push(node(xi, yj, cur.k + f));
                    }
                }
            }
        }
        return keys[n - 1][n - 1];
    }
};