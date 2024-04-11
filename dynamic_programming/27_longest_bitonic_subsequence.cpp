/*
Problem:
Minimum Number of Removals to Make Mountain Array

You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

Example 1:
Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.

Example 2:
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].

Solution:
1. Get the LIS from left to right (ltr)
2. Reverse the input
3. Find the LIS from right to left (rtl) i.e. in original array this will be decresing subsequence
4. Now we need to reverse the LIS array as well.
5. Now find the maximum of both the arrays given that both had some in increasing order. (Add -1 as one element will be common in both)
6. This will give us the longest bitonic subsequence
7. substract longest bitonic subsequence from the length of the array

Time Complexity: O(n * n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array
*/

class Solution {
public:
    vector<int> lis(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return dp;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> ltr = lis(nums);
        reverse(nums.begin(), nums.end());
        vector<int> rtl = lis(nums);
        reverse(rtl.begin(), rtl.end());
        int maxi = -1e9;
        for(int i = 0; i < n; i++) {
            if(ltr[i] > 1 && rtl[i] > 1)
                maxi = max(maxi, ltr[i] + rtl[i] - 1);    
        }
        return n - maxi;
    }
};