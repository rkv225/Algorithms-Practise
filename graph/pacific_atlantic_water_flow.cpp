/*
Problem:
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. 
You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

Solution: 
We make a DFS in reverse fashion from shores and traverse till we have value increasing or equal.
Store the traversals separately into arrays and then union them.

Time complexity: O(MN)
space complexity: O(MN)

Link: https://leetcode.com/problems/pacific-atlantic-water-flow/description/
*/
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> atlantic(m, vector<int>(n, 0));
    vector<vector<int>> pacific(m, vector<int>(n, 0));
    vector<vector<int>> ans;
    // traverse from atlantic ocean
    for(int i = 0; i < m; i++)
        if(atlantic[i][n - 1] == 0)
            dfs(i, n - 1, INT32_MIN, m, n, heights, atlantic);
    for(int i = 0; i < n; i++)
        if(atlantic[m - 1][i] == 0)
            dfs(m - 1, i, INT32_MIN, m, n, heights, atlantic);
    // traverse from pacific ocean
    for(int i = 0; i < m; i++)
        if(pacific[i][0] == 0)
            dfs(i, 0, INT32_MIN, m, n, heights, pacific);
    for(int i = 0; i < n; i++)
        if(pacific[0][i] == 0)
            dfs(0, i, INT32_MIN, m, n, heights, pacific);
    // finding union
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(atlantic[i][j] == 1 && pacific[i][j] == 1)
                ans.push_back({i, j});
    return ans;
}

void dfs(int i, int j, int v, int m, int n, vector<vector<int>> &heights, vector<vector<int>> &visit) {
    if(i >= 0 && i < m && j >= 0 && j < n && heights[i][j] >= v && visit[i][j] == 0) {
        visit[i][j] = 1;
        dfs(i - 1, j, heights[i][j], m, n, heights, visit); // up
        dfs(i + 1, j, heights[i][j], m, n, heights, visit);// down
        dfs(i, j - 1, heights[i][j], m, n, heights, visit);// left
        dfs(i, j + 1, heights[i][j], m, n, heights, visit);// right
    }
}