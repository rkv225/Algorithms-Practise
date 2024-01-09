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
    if(arr[0] <= k) prev[arr[0]] = true;
    prev[0] = curr[0] = true;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
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
Problem variation: You are given an array 'ARR' of 'N' positive integers. 
Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.
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
    if(arr[0] <= k) prev[arr[0]] = true;
    prev[0] = curr[0] = true;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
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
Problem variation::
You are given an array 'arr' containing 'n' non-negative integers.
Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.
Note:

1. Each array element should belong to exactly one of the subsets.

2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset. 
Example:
Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].

Ouput: 1

Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).

link: https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
*/
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int k = 0;
	for(int i = 0; i < n; i++)
		k = k + arr[i];
	vector<bool> prev(k + 1, false);
    vector<bool> curr(k + 1, false);
    if(arr[0] <= k) prev[arr[0]] = true;
    prev[0] = curr[0] = true;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            bool take = false;
            if(j >= arr[i])
                take = prev[j - arr[i]];
            bool not_take = prev[j];
            curr[j] = take || not_take;
        }
        prev = curr;
    }
	int min_diff = INT32_MAX;
    for (int i = 0; i <= k; i++) {
        if (prev[i]) {
			int s1 = i;
			int s2 = k - i;
			min_diff = min(min_diff, abs(s1 - s2));
        }
    }
	return min_diff;
}

/*
Problem variation: 
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

Example:
Input: 'arr' = [1, 1, 4, 5]
Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.

link: https://www.codingninjas.com/studio/problems/number-of-subsets_3952532
*/
int findWays(vector<int>& arr, int k)
{
	int dli = 1e9+7;
	int n = arr.size();
	vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);
	prev[0] = curr[0] = 1;
	if(arr[0] == 0) prev[0] = curr[0] = 2;
    if(arr[0] <= k && arr[0] != 0) prev[arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            int take = 0;
            if(j >= arr[i])
                take = prev[j - arr[i]] % dli;
            int not_take = prev[j] % dli;
            curr[j] = (take + not_take) % dli;
        }
        prev = curr;
    }
    return prev[k];
}
