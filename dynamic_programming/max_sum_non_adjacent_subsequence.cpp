/*
You are given an array/list of ‘N’ integers. 
You are supposed to return the maximum sum of the subsequence with the 
constraint that no two elements are adjacent in the given array/list.
*/

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int sum_take = nums[i];
        if(i > 1)
            sum_take = sum_take + dp[i - 2];
        int sum_reject = dp[i - 1];
        dp[i] = max(sum_take, sum_reject);
    }
    return dp[n - 1];
}