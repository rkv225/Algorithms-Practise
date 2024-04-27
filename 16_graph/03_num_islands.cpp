/*
Problem: 
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Link: https://leetcode.com/problems/number-of-islands

time complexity: O(N*M)
space complexity: O(N*M)
*/

void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if(i < m && i >= 0 && j < n && j >= 0 && grid[i][j] == '1') {
        grid[i][j] = '0';
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int islands = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j, m, n);
                islands++;
            }
        }
    }
    return islands;
}