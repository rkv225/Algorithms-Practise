/*
Problem:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

Link: https://leetcode.com/problems/two-sum

Solution: using hashmap

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            if(m.find(target - nums[i]) != m.end())
                return {m[target - nums[i]], i};
            m[nums[i]] = i;
        }
        return { -1, -1 };
    }
};