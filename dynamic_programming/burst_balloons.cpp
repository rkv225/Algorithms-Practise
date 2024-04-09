/*
Problem:
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:
Input: nums = [1,5]
Output: 10

Solution:
1. add packing of 1 on both sides of the array so that we simplify the calculation
2. now instead of thinking which oine to burst first we think in terms of which will bust at last.
3. suppose we have a range and we try all possible values which will burt last.
4. To compute the cost for the last value, we need to look for the left and right values.
As we are computing from bottom to up, for our last value the left and right will be i - 1 and j + 1
suppose if you consider entire array then for last value 1 from both ends will be there to compute the coins 

Time Complexity: O(n^3)
Space Complexity: O(n^2)

Link: https://leetcode.com/problems/burst-balloons/
*/

class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] > -1) return dp[i][j];
        for(int index = i; index <= j; index++) {
            int coins = nums[i - 1] * nums[index] * nums[j + 1];
            int left = f(i, index - 1, nums, dp);
            int right = f(index + 1, j, nums, dp);
            dp[i][j] = max(dp[i][j], coins + left + right);
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return f(1, nums.size() - 2, nums, dp);
    }
};