/*
Problem:
A Subsequence of a string is the string that is obtained by deleting 0 or more letters from the string and keeping the rest of the letters in the same order.
We are given two strings, 'str' and 'sub'.
Find the number of subsequences of 'str' which are equal to 'sub'.
Since the answer can be very large, print it modulo 10 ^ 9 + 7.

Example :
Input: 'str' = “brootgroot” and 'sub' = “brt”
Output: 3
Explanation: The following subsequences formed by characters at given indices (0-based) of 'str' are equal to 'sub' :
str[0] = ‘b’, str[1] = ‘r’, str[4] = ‘t’
str[0] = ‘b’, str[1] = ‘r’, str[9] = ‘t’
str[0] = ‘b’, str[6] = ‘r’, str[9] = ‘t’

Link: https://www.naukri.com/code360/problems/subsequence-counting_3755256
*/

/*
Solution: Memoization
Time Complexity: O(m*n)
Space Complexity: O(m*n) + recursion stack
*/
int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp) {
	int x = 1e9 + 7;
	if(j < 0) return 1;
	if(i < 0) return 0;
	if(dp[i][j] > -1) return dp[i][j];
	if(str[i] == sub[j]) {
		dp[i][j] = (f(i - 1, j - 1, str, sub, dp) + f(i - 1, j, str, sub, dp)) % x;
	}
	else {
		dp[i][j] = f(i - 1, j, str, sub, dp) % x;
	}
	return dp[i][j];
}

int distinctSubsequences(string &str, string &sub)
{
	int m = str.size();
	int n = sub.size();
	vector<vector<int>> dp(m, vector<int>(n, -1));
	f(m - 1, n - 1, str, sub, dp);
	return dp[m - 1][n - 1];
}

/*
Solution: Tabulation
Time Complexity: O(m*n)
Space Complexity: O(m*n)
*/
int distinctSubsequences(string &str, string &sub)
{
	int x = 1e9 + 7;
	int m = str.size();
	int n = sub.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for(int i = 0; i <= m; i++)
		dp[i][0] = 1;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(str[i - 1] == sub[j - 1]) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % x;
			}
			else {
				dp[i][j] = dp[i - 1][j] % x;
			}		
		}
	}
	return dp[m][n];
}

/*
Solution: Space Optimization
Time Complexity: O(m*n)
Space Complexity: O(n)
*/
int distinctSubsequences(string &str, string &sub)
{
	int x = 1e9 + 7;
	int m = str.size();
	int n = sub.size();
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= m; i++)
		for(int j = n; j >= 1; j--)
			if(str[i - 1] == sub[j - 1])
				dp[j] = (dp[j - 1] + dp[j]) % x;
	return dp[n];
}