/*
Problem:
Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.

Solution:
- LIS with count array

Time Complexity: O(n^3)
Space Complexity: O(n)

Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        // storing the count
        vector<int> count(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    // if we have a longer subsequence through j 
                    if(dp[j] + 1 > dp[i]) {
                        // update length
                        dp[i] = dp[j] + 1; 
                        // this will have same count as in j
                        count[i] = count[j];
                    } else if(dp[j] + 1 == dp[i]){
                        // if length is same then we have more subsequences of same length so add prev and cur
                        count[i] = count[i] + count[j];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        // sum count of all the subsequences of max length
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)
                ans = ans + count[i];
        }
        return ans;
    }
};