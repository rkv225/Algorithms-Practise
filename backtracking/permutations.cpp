/*
Problem:
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Solution:
Try drawing recursion tree for this.
For every number in right, take one number to left and rest all to right. 
Repeat this process till right is exhausted and save the result.

Time complexity: O(n * n!)
Given a set of length n, the number of permutations is n!. 
There are n options for the first number, n−1 for the second, n−2 for the third, and so on...
For each permutations, it takes O(n) to copy vector.

Space complexity: O(n)

Link: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    void rec(vector<int> left, vector<int> right, vector<vector<int>>& ans) {
        if(right.size() <= 0) {
            ans.push_back(left);
            return;
        }
        for(int i = 0; i < right.size(); i++) {
            vector<int> pre(left);
            pre.push_back(right[i]);
            vector<int> cur;
            for(int j = 0; j < right.size(); j++)
                if(i != j)
                    cur.push_back(right[j]);
            rec(pre, cur, ans);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> left;
        vector<int> right(nums);
        rec(left, right, ans);
        return ans;
    }
};