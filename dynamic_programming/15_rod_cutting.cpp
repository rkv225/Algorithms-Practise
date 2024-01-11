/*
Problem:

Link:
*/

/*
memoization
*/
int f(int i, int n, vector<int> &price, vector<vector<int>> &dp){
	if(i < 0 || n == 0) return 0;
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
	for(int i = 0; i < np; i++)
		dp[i][0] = 0;
	for(int i = 0; i < np; i++){
		for(int r = 1; r <= n; r++){
			int not_take = i > 0 ? dp[i - 1][r] : 0;
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
	dp[0] = 0;
	for(int i = 0; i < np; i++){
		for(int r = 1; r <= n; r++){
			int not_take = i > 0 ? dp[r] : 0;
			int rlen = i + 1;
			int take = rlen <= r ? dp[r - rlen] + price[i] : 0;
			dp[r] = max(not_take, take);
		}
	}
	return dp[n];
}