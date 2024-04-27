/*
Problem: 
Islands and Treasure
You are given a m×n 2D grid initialized with these three possible values:
-1 - A water cell that can not be traversed.
0 - A treasure chest.
INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.
Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest than the value should remain INF.
Assume the grid can only be traversed up, down, left, or right.

Example 1:
Input: [
  [2147483647,-1,0,2147483647],
  [2147483647,2147483647,2147483647,-1],
  [2147483647,-1,2147483647,-1],
  [0,-1,2147483647,2147483647]
]
Output: [
  [3,-1,0,1],
  [2,2,1,-1],
  [1,-1,2,-1],
  [0,-1,3,4]
]

Example 2:
Input: [
  [0,-1],
  [2147483647,2147483647]
]
Output: [
  [0,-1],
  [1,2]
]

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
grid[i][j] is one of {-1, 0, 2147483647}

Link: https://neetcode.io/problems/islands-and-treasure

Time Complexity: O(m * n)

Space Complexity: O(m * n)
*/


class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // initially fill the water as visited with distance as infinite
        // and also mark the treasure as visited, set distance 0 and add to queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == -1) {
                    visited[i][j] = 1;
                }
                if(grid[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push(pair<int, int>(i, j));
                }
            }
        }

        // perform bfs operation and update the grid distances as we traverse
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;

            // top
            if(i > 0 && visited[i - 1][j] == 0) {
                visited[i - 1][j] = 1;
                grid[i - 1][j] = grid[i][j] + 1;
                q.push(pair<int, int>(i - 1, j));
            }  
            // bottom
            if(i < m - 1 && visited[i + 1][j] == 0) {
                visited[i + 1][j] = 1;
                grid[i + 1][j] = grid[i][j] + 1;
                q.push(pair<int, int>(i + 1, j));
            }  
            // left
            if(j > 0 && visited[i][j - 1] == 0) {
                visited[i][j - 1] = 1;
                grid[i][j - 1] = grid[i][j] + 1;
                q.push(pair<int, int>(i, j - 1));
            }  
            // right
            if(j < n - 1 && visited[i][j + 1] == 0) {
                visited[i][j + 1] = 1;
                grid[i][j + 1] = grid[i][j] + 1;
                q.push(pair<int, int>(i, j + 1));
            }   
        }
    }
};


/*
optimized solution (small code, although same time and space complexity)
extra visited array is removed here
*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = 2147483647;
        int m = grid.size();
        int n = grid[0].size(); 
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 0)
                    q.push(pair<int, int>(i, j));
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first;
            int j = p.second;
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int k = 0; k < 4; k++) {
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di >= 0 && di <= m - 1 && dj >= 0 && dj <= n - 1 && grid[di][dj] == inf) {
                    grid[di][dj] = grid[i][j] + 1;
                    q.push(pair<int, int>(di, dj));    
                }
            }   
        }
    }
};
