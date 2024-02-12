/*
Problem:
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20

Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18

Solution: Using prim's minimum spanning tree algorithm

Time Complexity: O(n log n) where n is number of points

Space complexity: O(n) for vector of nodes and priority queue

link: https://leetcode.com/problems/min-cost-to-connect-all-points
*/

class Solution {
public:
    class node {
    public:
        int point;
        int x;
        int y;
        int parent;
        int key;
        int color;
        node(int p, int x, int y, int par, int ke, int c) {
            this->point = p;
            this->x = x;
            this->y = y;
            this->parent = par;
            this->key = ke;
            this->color = c;
        }
    };
    class maxnode 
    {
    public:
        int operator() (const node &a, const node &b)
        {
            return a.key > b.key;
        }
    };
    int distance(int xi, int yi, int xj, int yj) {
        return abs(xi - xj) + abs(yi - yj);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<node> m;
        for(int i = 0 ; i < n; i++) {
            m.push_back(node(i, points[i][0], points[i][1], -1, 1e8, 0));
        }
        priority_queue<node, vector<node>, maxnode> pq;
        int ans = 0;
        m[0].key = 0;
        pq.push(m[0]);
        while(!pq.empty()){
            node cur = pq.top();
            int curi = cur.point;
            pq.pop();
            if(m[curi].color == 0 && m[curi].parent != -1) {
                ans += m[curi].key;
                m[curi].color = 1;
            }
            for(int i = 0; i < n; i++) {
                if(m[i].color == 0 && distance(m[curi].x, m[curi].y, m[i].x, m[i].y) < m[i].key) {
                    m[i].parent = m[curi].point;
                    m[i].key = distance(m[curi].x, m[curi].y, m[i].x, m[i].y);
                    pq.push(m[i]);
                }
            }
        }
        return ans;
    }
};