/*
You are given an array/list of ‘N’ integers. 
You are supposed to return the maximum sum of the subsequence with the 
constraint that no two elements are adjacent in the given array/list.

Link: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261

Time complexity: O(n), space complexity: O(n)
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

/*
* Space complexity: O(1)
*/

int maximumNonAdjacentSum(vector<int> &nums){
    int prev2 = 0;
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int sum_take = nums[i] + prev2;
        int sum_reject = prev;
        int curr = max(sum_take, sum_reject);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}