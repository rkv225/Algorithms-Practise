
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