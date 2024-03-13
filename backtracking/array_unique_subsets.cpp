/*
Problem:
Given an integer array nums that may contain duplicates, return all possible subsets(the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Solution:

Here we take the same approach of take and not take to find a powerset.
But there's a catch in the approach that we need not to have duplicate subsets. 
In order to do so we sort the input array and we skip entire digit when not take.

Time Complexity: O(n*2^n)
Space Complexity: O(2^n)

Link: https://leetcode.com/problems/subsets-ii
*/

class Solution {
public:
    void rec(int i, vector<int> cur, vector<int>& nums, vector<vector<int>>& ans) {
        if(i >= nums.size()) {
            ans.push_back(cur);
            return;
        }
        // not take
        int j = i;
        while(j < nums.size() && nums[j] == nums[i])
            j++;
        rec(j, cur, nums, ans);
        // take
        cur.push_back(nums[i]);
        rec(i + 1, cur, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        rec(0, cur, nums, ans);
        return ans;
    }
};