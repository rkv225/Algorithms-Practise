/*
Problem:
A thief is robbing a store and can carry a maximal weight of W into his knapsack. 
There are N items and the ith item weighs wi and is of value vi. 
Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items.

link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
*/

/*
memoization
*/
int f(int i, int c, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
	if(i < 0 || c <= 0)
		return 0;
	if(dp[i][c] >= 0)
		return dp[i][c];
	int take = INT32_MIN;
	if (wt[i] <= c) {
		take = f(i - 1, c - wt[i], wt, val, dp) + val[i];
	}
	int not_take = f(i - 1, c, wt, val, dp);
	dp[i][c] = max(take, not_take);
	return dp[i][c];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
	return f(n - 1, maxWeight, weight, value, dp);
}

/*
tabulation
*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
	for (int i = 0; i < n; i++)
		dp[i][0] = 0;
	// for last value if capacity equal or more then we can pick 
	for(int i = weight[0]; i <= maxWeight; i++)
		dp[0][i] = value[0];
	for (int i = 1; i < n; i++) {
		for(int w = 1; w <= maxWeight; w++){
			int take = INT32_MIN;
			if(weight[i] <= w){
				take = dp[i - 1][w - weight[i]] + value[i];
			}
			int not_take = dp[i - 1][w];
			dp[i][w] = max(take, not_take);
		}
	}
	return dp[n - 1][maxWeight];
}

/*
optimization
*/
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight + 1, 0);
	vector<int> curr(maxWeight + 1, 0);
	prev[0] = curr[0] = 0;
	// for last value if capacity equal or more then we can pick 
	for(int i = weight[0]; i <= maxWeight; i++)
		prev[i] = value[0];
	for (int i = 1; i < n; i++) {
		for(int w = 1; w <= maxWeight; w++){
			int take = INT32_MIN;
			if(weight[i] <= w){
				take = prev[w - weight[i]] + value[i];
			}
			int not_take = prev[w];
			curr[w] = max(take, not_take);
		}
		prev = curr;
	}
	return prev[maxWeight];
}