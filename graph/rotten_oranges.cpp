/*
Problem: You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Link: https://leetcode.com/problems/rotting-oranges/

Solution: apply bfs from all the rotten oranges 

Time Complexity: O(n*m)
Space Complexity: O(n*m) 
*/

class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, vector<vector<int>>& time)
    {
        while(!q.empty())
        {
            pair<int, int> o = q.front();
            int i = o.first;
            int j = o.second;
            q.pop();
            //left
            if(j > 0 && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                time[i][j - 1] = time[i][j] + 1;
                q.push(pair<int, int>(i, j - 1));
            }
            //right
            if(j < grid[0].size() - 1 && grid[i][j + 1] == 1) {    
                grid[i][j + 1] = 2;
                time[i][j + 1] = time[i][j] + 1;
                q.push(pair<int, int>(i, j + 1));
            }
            //top
            if(i > 0 && grid[i - 1][j] == 1) {
                grid[i - 1][j] = 2;
                time[i - 1][j] = time[i][j] + 1;
                q.push(pair<int, int>(i - 1, j));
            }
            //bottom
            if( i < grid.size() - 1 && grid[i + 1][j] == 1) {
                grid[i + 1][j] = 2;
                time[i + 1][j] = time[i][j] + 1;
                q.push(pair<int, int>(i + 1, j));
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // place all rotten oranges initially in queue, as all will start to rot from inital rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push(pair<int, int>(i, j));
            }
        }

        // now run bfs 
        bfs(q, grid, time);

        // get the maximium time from grid
        int max_time = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    return -1;
                max_time = max(max_time, time[i][j]);
            }
        }
        return max_time;
    }
};