/*
Problem:
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Solution:
1. Sort the input array so that instead of subset we can find increasing subsequence, this is because for i < j => num[i] < num[j]
2. Perform operation similar to LIS with a slight modification mentioned below.
3. Instead of checking increasing , check if the number is completely divisible or not
4. Keep track of previous values in prev array
5. Finally backtrack and return the subsequence, reversing will return longest divisible subsequence.

Time Complexity: O(n * n)
Space Complxity: O(n)

Link: https://leetcode.com/problems/largest-divisible-subset/
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<int> ans;
        int maxi = 1, index = 0; 
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if(maxi < dp[i]) {
                        maxi = dp[i];
                        index = i;
                    }
                }
            }
        }
        while(prev[index] != -1) {
            ans.push_back(nums[index]);
            index = prev[index];
        }
        ans.push_back(nums[index]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};