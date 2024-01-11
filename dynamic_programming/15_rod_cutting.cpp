/*
Problem:
Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.

Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Link: https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284
*/

/*
memoization
*/
int f(int i, int n, vector<int> &price, vector<vector<int>> &dp){
	if(i == 0) return n * price[0];
	if(dp[i][n] != -1) return dp[i][n];
	int not_take = f(i - 1, n, price, dp);
	int rlen = i + 1;
	int take = rlen <= n ? f(i, n - rlen, price, dp) + price[i] : -1e8;
	dp[i][n] = max(not_take, take);
	return dp[i][n];
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(), vector<int>(n + 1, -1));
	return f(price.size() - 1, n, price, dp);
}

/*
tabulation
*/
int cutRod(vector<int> &price, int n)
{
	int np = price.size();
	vector<vector<int>> dp(np, vector<int>(n + 1, 0));
	for(int r = 0; r <= n; r++)
		dp[0][r] = r * price[0];
	for(int i = 1; i < np; i++){
		for(int r = 1; r <= n; r++){
			int not_take = dp[i - 1][r];
			int rlen = i + 1;
			int take = rlen <= r ? dp[i][r - rlen] + price[i] : 0;
			dp[i][r] = max(not_take, take);
		}
	}
	return dp[np - 1][n];
}

/*
space optimization
*/
int cutRod(vector<int> &price, int n)
{
	int np = price.size();
	vector<int> dp(n + 1, 0);
	for(int r = 0; r <= n; r++)
		dp[r] = r * price[0];
	for(int i = 1; i < np; i++){
		for(int r = 1; r <= n; r++){
			int not_take = dp[r];
			int rlen = i + 1;
			int take = rlen <= r ? dp[r - rlen] + price[i] : 0;
			dp[r] = max(not_take, take);
		}
	}
	return dp[n];
}