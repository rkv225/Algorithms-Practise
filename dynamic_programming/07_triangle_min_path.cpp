/*
Problem:
You are given a triangular array/list 'TRIANGLE'. 
Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. 
For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.

Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.

Link: https://www.codingninjas.com/studio/problems/triangle_1229398
*/

/*
solution: recursion
time: O(2^n*n)
space: O(2^n) stack
*/
int f(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &t) {
	if(i == n-1)
		return t[i][j];
	return min(f(i + 1, j, n, dp, t), f(i + 1, j + 1, n, dp, t)) + t[i][j];
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return f(0, 0, n, dp, triangle);
}

/*
solution: memoization
time: O(n^2)
space: O(n^2) + stack 
*/
int f(int i, int j, int n, vector<vector<int>> &dp, vector<vector<int>> &t) {
	if(i == n-1)
		return t[i][j];
	int down = INT32_MAX;
	int diag = INT32_MAX;
	down = dp[i + 1][j] < INT32_MAX ? dp[i + 1][j] : f(i + 1, j, n, dp, t);
	diag = dp[i + 1][j + 1] < INT32_MAX ? dp[i + 1][j + 1] : f(i + 1, j + 1, n, dp, t);
	dp[i][j] = min(down, diag) + t[i][j];
	return dp[i][j];
}

int minimumPathSum(vector<vector<int>>& triangle, int n) {
	vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
	return f(0, 0, n, dp, triangle);
}

/*
solution: tabulation 
time: O(n^2)
space: O(n^2)
*/
int minimumPathSum(vector<vector<int>>& triangle, int n) {
	vector<vector<int>> dp(n, vector<int>(n, INT32_MAX));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			int down = triangle[i][j];
			int diag = triangle[i][j];
			if (i < n - 1) {
				down += dp[i + 1][j];
				diag += dp[i + 1][j + 1];
			}
			dp[i][j] = min(down, diag);
		}
	}
	return dp[0][0];
}

/*
solution: optimization
time: O(n^2)
space: O(n)
*/
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> prev = triangle[n-1];
	vector<int> curr(n, INT32_MAX);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			curr[j] = min(prev[j], prev[j + 1]) + triangle[i][j];
		}
		prev = curr;
	}
	return prev[0];
}