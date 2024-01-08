/*
Problem: 
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example:
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. 
These are {1,3} and {4}. Hence, return true.

Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
*/

/*
solution: memoization
time: O(n*k)
space: O(n*k) + stack
*/
int f(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
  if (target == 0)
    return 1;
  if (index == 0)
    return arr[index] == target ? 1 : 0;
  int not_take = 0;
  int take = 0;
  not_take = dp[index - 1][target] > 0 ? dp[index - 1][target] : f(index - 1, target, arr, dp);
  if(arr[index] <= target)
    take = dp[index - 1][target - arr[index]] > 0 ? dp[index - 1][target - arr[index]] : f(index - 1, target - arr[index], arr, dp);
  dp[index][target] = take + not_take > 0 ? 1 : 0;
  return dp[index][target];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    if(f(n - 1, k, arr, dp) > 0)
        return true;
    else
        return false;
}

/*
solution: tabulation
time: O(n*k)
space: O(n*k)
*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    // base case
    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    // subset found at 0th index
    dp[0][arr[0]] = true;
    
    // go from 1 to n-1 for each target value
    for (int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool take = false;
            if(j >= arr[i])
                take = dp[i - 1][j - arr[i]];
            bool not_take = dp[i - 1][j];
            dp[i][j] = take || not_take;
        }
    }

    return dp[n - 1][k];
}

/*
solution: tabulation with space optimization
time: O(n*k)
space: O(k)
*/
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if (j == 0) prev[0] = true;
            bool take = false;
            if(j >= arr[i])
                take = prev[j - arr[i]];
            bool not_take = prev[j];
            curr[j] = take || not_take;
        }
        prev = curr;
    }
    return prev[k];
}



/*
Problem variation: You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.

For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.

Link: https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980
*/

bool canPartition(vector<int> &arr, int n)
{
	int k = 0;
	for (int i = 0; i < n; i++) {
		k = k + arr[i];
	}
	if(k & 1 == 1)
		return false;
	k = k / 2;
	vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);
    prev[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if (j == 0) prev[0] = true;
            bool take = false;
            if(j >= arr[i])
                take = prev[j - arr[i]];
            bool not_take = prev[j];
            curr[j] = take || not_take;
        }
        prev = curr;
    }
    return prev[k];
}