
/*
Problem: You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’, 
which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point ‘A’ to point ‘B’.
In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, 
your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i] [j], 
you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

Link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470
*/

/*
solution: plain recursion
time: O(2^m*n)
space: O(m*n) recusrion stack
*/
int f(int i, int j, int m, int n) {
	if(i >= m || j >= n)
		return 0;
	if(i == m - 1 && j == n - 1)
		return 1;
	int curr = f(i + 1, j, m, n) + f(i, j + 1, m, n);
	return curr;
}

int uniquePaths(int m, int n) {
	return f(0, 0, m, n);
}

/*
solution: memoization
time: O(m*n)
space: O(m*n) + recursion stack
*/
int f(int i, int j, int m, int n, vector<vector<int>> &dp) {
	if(i >= m || j >= n)
		return 0;
	if(i == m - 1 && j == n - 1)
		return 1;
	int right = dp[i + 1][j] >= 0 ? dp[i + 1][j] : f(i + 1, j, m, n, dp);
	int down = dp[i][j + 1] >= 0 ? dp[i][j + 1] : f(i, j + 1, m, n, dp); 
	dp[i][j] = right + down;
	return dp[i][j];
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1)); 
	return f(0, 0, m, n, dp);
}

/*
solution: tabulation
time: O(m*n)
space: O(m*n)
*/
int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (i == 0 && j == 0) {
        dp[i][j] = 1;
      } else {
        if (i > 0)
          dp[i][j] += dp[i - 1][j];
        if (j > 0)
          dp[i][j] += dp[i][j - 1];
      }
  return dp[m - 1][n - 1];
}

/*
solution: tabulation with space optimization
time: O(m*n)
space: O(n)
*/
int uniquePaths(int m, int n) {
  vector<int> prev(n, 0);
  vector<int> curr(n, 0);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      curr[j] = 0;
      if (i == 0 && j == 0) {
        curr[j] = 1;
      } else {
        curr[j] += prev[j];
        if (j > 0)
          curr[j] += curr[j - 1];
      }
    }
    prev = curr;
  }
  return prev[n - 1];
}