/*
problem: 
You are given an m x n binary matrix grid. 
An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

link: https://leetcode.com/problems/max-area-of-island/
*/

int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
    int area = 0;
    if(i < m && i >= 0 && j < n && j >= 0 && grid[i][j] == 1) {
        area++;
        grid[i][j] = 0;
        area += dfs(grid, i + 1, j, m, n);
        area += dfs(grid, i - 1, j, m, n);
        area += dfs(grid, i, j + 1, m, n);
        area += dfs(grid, i, j - 1, m, n);
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int area = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                area = max(area, dfs(grid, i, j, m, n));
            }
        }
    }
    return area;
}