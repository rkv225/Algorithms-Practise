/*
Problem:
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Solution:
Start with empty array & index i = 0
either take the element at index i, put in array and move forward
or don't take and move forward

Time Complexity: O(2^n)
Space Complexity: O(2^n)

Link: https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    void gen(int i, vector<int> prefix, vector<int>& nums, vector<vector<int>>& ans) {
        if(i >= nums.size()) {
            ans.push_back(prefix);
            return;
        }
        // don't take
        gen(i + 1, prefix, nums, ans);
        // take
        prefix.push_back(nums[i]);
        gen(i + 1, prefix, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> prefix;
        gen(0, prefix, nums, ans);
        return ans;
    }
};