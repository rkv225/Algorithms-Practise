/*
problem:
You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. 
You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.

link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091
*/

/*
recursion
*/
int f(int i, int sum, vector<int> &num){
    if(sum == 0)
        return 0;
    if(i < 0)
        return 1e8;
    int ans = 1e8;
    if(sum >= num[i]){
        // take 
        ans = min(ans, f(i, sum - num[i], num) + 1);
    }
    // not take
    ans = min(ans, f(i - 1, sum, num));
    return ans;
}

int minimumElements(vector<int> &num, int x)
{
    int ans = f(num.size() - 1, x, num);
    return ans >= 1e8 ? -1 : ans;
}

/*
memoization
*/
int f(int i, int sum, vector<int> &num, vector<vector<int>> &dp){
    if(sum == 0)
        return 0;
    if(i < 0)
        return 1e8;
    if(dp[i][sum] > -1) return dp[i][sum];
    int ans = 1e8;
    if(sum >= num[i]){
        // take 
        ans = min(ans, f(i, sum - num[i], num, dp) + 1);
    }
    // not take
    dp[i][sum] = min(ans, f(i - 1, sum, num, dp));
    return dp[i][sum];
}

int minimumElements(vector<int> &num, int x)
{
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, -1));
    int ans = f(num.size() - 1, x, num, dp);
    return ans >= 1e8 ? -1 : ans;
}

/*
tabulation
*/
int minimumElements(vector<int> &num, int x)
{
    int maxi = 1e8;
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x + 1, maxi));
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;

    for(int sum = 1; sum <= x; sum++)
        dp[0][sum] = sum % num[0] == 0 ? sum / num[0] : maxi;  
    
    for (int i = 1; i < n; i++) {
        for(int sum = 1; sum <= x; sum++){
            dp[i][sum] = maxi;
            if(sum >= num[i])
                dp[i][sum] = min(dp[i][sum], dp[i][sum - num[i]] + 1);
            dp[i][sum] = min(dp[i][sum], dp[i - 1][sum]);
        }
    }
    return dp[n - 1][x] >= maxi ? -1 : dp[n - 1][x];
}