/*
Problem:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Solution: same approach as in array_unique_subsets

Link: https://leetcode.com/problems/combination-sum-ii/description/
*/

class Solution {
public:
    void rec(int i, int cur_sum, vector<int> cur_arr, int target, vector<int>& arr, vector<vector<int>>& ans) {
        if(cur_sum == target) {
            ans.push_back(cur_arr);
            return;
        }
        if(i >= arr.size() || cur_sum > target) {
            return;
        }
        // not take
        int j = i;
        while(j < arr.size() && arr[j] == arr[i])
            j++;
        rec(j, cur_sum, cur_arr, target, arr, ans);
        // take
        cur_sum = cur_sum + arr[i];
        cur_arr.push_back(arr[i]);
        rec(i + 1, cur_sum, cur_arr, target, arr, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur_arr;
        rec(0, 0, cur_arr, target, candidates, ans);
        return ans;
    }
};