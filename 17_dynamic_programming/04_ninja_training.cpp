/*
Problem: Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

Link: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
*/

/*
Solution: memoization solution
Time complexity: O(n * 4)
Space complexity: O(n * 4) + stack space in recursion O(n)
*/
int f(int d, int a, vector<vector<int>> &points, vector<vector<int>> &dp) {
  if (d == 0) {
    int base_sum = 0;
    for (int i = 0; i < 3; i++) {
      if (i != a) {
        base_sum = max(base_sum, points[0][i]);
      }
    }
    dp[0][a] = base_sum;
    return base_sum;
  }

  int maxi = 0;
  for (int i = 0; i < 3; i++) {
    if (i != a) {
        int curr = points[d][i];
        if(dp[d - 1][i] > 0)
            curr += dp[d-1][i];
        else
            curr += f(d - 1, i, points, dp);
        maxi = max(maxi, curr);
    }
  }
  dp[d][a] = maxi;
  return dp[d][a];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}

/*
Solution: Tabulation approach
Time complexity: O(n * 4)
space complexity: O(n * 4)
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    // base case
    for (int a = 0; a < 4; a++)
        for (int i = 0; i < 3; i++)
            if (i != a)
                dp[0][a] = max(dp[0][a], points[0][i]);
    
    // tabulation
    for (int d = 1; d < n; d++)
        for (int pa = 0; pa < 4; pa++)
            for (int ca = 0; ca < 3; ca++)
                if(pa != ca)
                    dp[d][pa] = max(dp[d][pa], points[d][ca] + dp[d-1][ca]);

    return dp[n - 1][3];
}

/*
Solution: Tabulation approach with space optimization
Time complexity: O(n * 4)
space complexity: O(1 * 4)
*/

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    
    // base case
    for (int a = 0; a < 4; a++)
        for (int i = 0; i < 3; i++)
            if (i != a)
                prev[a] = max(prev[a], points[0][i]);
    
    // tabulation
    for (int d = 1; d < n; d++) {
        vector<int> tmp(4, 0);
        for (int pa = 0; pa < 4; pa++)
            for (int ca = 0; ca < 3; ca++)
                if (pa != ca)
                    tmp[pa] = max(tmp[pa], points[d][ca] + prev[ca]);
        prev = tmp;
    }
    return prev[3];
}

