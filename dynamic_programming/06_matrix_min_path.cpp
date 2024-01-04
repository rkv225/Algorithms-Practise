/*
Problem: 
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. 
Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. 
You need to tell the minimum sum of that path.
*/

/*
Solution: recursion
Time: O(2^m*n)
space: O(m*n) recursion stack
*/
int f(int i, int j, vector<vector<int>> &grid) {
    if(i < 0 || j < 0)
        return INT32_MAX; 
    if(i == 0 && j == 0)
        return grid[i][j];
    return min(f(i - 1, j, grid), f(i, j - 1, grid)) + grid[i][j]; 
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return f(n - 1, m - 1, grid);
}

/*
solution: memoization
Time: O(m*n)
space: O(m*n) + recursion stack
*/
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i == 0 && j == 0)
        return grid[i][j];
    int top = INT32_MAX;
    int left = INT32_MAX;
    if(i > 0)
        top = dp[i - 1][j] > 0 ? dp[i - 1][j] : f(i - 1, j, grid, dp);
    if(j > 0)
        left = dp[i][j - 1] > 0 ? dp[i][j - 1] : f(i, j - 1, grid, dp);
    dp[i][j] = min(top, left) + grid[i][j]; 
    return dp[i][j];
}

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return f(n - 1, m - 1, grid, dp);
}

/*
solution: tabulation
Time: O(m*n)
space: O(m*n)
*/
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else {
                int top = INT32_MAX;
                int left = INT32_MAX;
                if(i > 0)
                    top = dp[i - 1][j];
                if(j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = min(top, left) + grid[i][j];
            }
        }
    }
    return dp[n-1][m-1];
}

/*
solution: space optimization
Time: O(m*n)
space: O(m)
*/
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, -1);
    vector<int> curr(m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                curr[j] = grid[i][j];
            else {
                int top = INT32_MAX;
                int left = INT32_MAX;
                if(i > 0)
                    top = prev[j];
                if(j > 0)
                    left = curr[j - 1];
                curr[j] = min(top, left) + grid[i][j];
            }
        }
        prev = curr;
    }
    return prev[m-1];
}