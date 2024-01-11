
/*
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.
You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.

Link: https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029
*/

/*
Memoization
*/
int f(int i, int c, vector<vector<int>> &dp, vector<int> &profit, vector<int> &weight){
    if(c == 0 || i < 0)
        return 0;
    if(dp[i][c] != -1)
        return dp[i][c];
    int take = INT32_MIN;
    if(c >= weight[i])
        take = f(i, c - weight[i], dp, profit, weight) + profit[i];
    int not_take = f(i - 1, c, dp, profit, weight);
    dp[i][c] = max(take, not_take);
    return dp[i][c];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, dp, profit, weight);
}

/*
tabulation
*/
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    int mini = -1e8;
    vector<vector<int>> dp(n, vector<int>(w + 1, mini));
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;
    for(int c = 1; c <= w; c++)
        dp[0][c] = c % weight[0] == 0 ? (c / weight[0]) * profit[0] : mini; 
    for(int i = 1; i < n; i++){
        for(int c = 1; c <= w; c++){
            int take = mini;
            if(c >= weight[i])
                take = dp[i][c - weight[i]] + profit[i];
            int not_take = dp[i - 1][c];
            dp[i][c] = max(take, not_take);
        }
    } 
    return dp[n - 1][w] > mini ? dp[n - 1][w] : 0;
}

/*
space optimized tabulation
*/
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    int mini = -1e8;
    vector<int> prev(w + 1, mini);
    for(int i = 0; i < n; i++)
        prev[0] = 0;
    for(int c = 1; c <= w; c++)
        prev[c] = c % weight[0] == 0 ? (c / weight[0]) * profit[0] : mini; 
    for(int i = 1; i < n; i++){
        for(int c = 1; c <= w; c++){
            int take = mini;
            if(c >= weight[i])
                take = prev[c - weight[i]] + profit[i];
            int not_take = prev[c];
            prev[c] = max(take, not_take);
        }
    } 
    return prev[w] > mini ? prev[w] : 0;
}