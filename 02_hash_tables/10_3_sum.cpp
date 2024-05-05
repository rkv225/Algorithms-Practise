/*
Problem:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Solution:
Mentioned in comments.
This is giving TLE on leetcode but intuitive solution.


Time Complexity: O(n*n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/3sum
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // if less than 3 numbers
        if(n < 3)
            return {};
        // if smallest number if greater than 0 then we can't effectively make sum = 0
        if(nums[0] > 0)
            return {};
        vector<vector<int>> result;
        unordered_map<string, vector<int>> final_triplets;
        // hash the entire array
        unordered_map<int, int> hash;
        for(int i = 0; i < n - 1; i++)
            hash[nums[i]] = i;
        // for all combinations of 2 indices
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > 0)
                continue;
            for(int j = i + 1; j < n; j++) {
                int cur = nums[i] + nums[j];
                if(hash.find(cur * -1) != hash.end()) {
                    // triplet with sum 0 found
                    int k = hash[cur * -1];
                    if(i != j && i != k && j != k) {
                        // all three indexes must be different for a valid triplet
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        // sort to avoid duplicate
                        sort(triplet.begin(), triplet.end());
                        string triplet_string = to_string(triplet[0]) + "," + to_string(triplet[1]) + "," + to_string(triplet[2]);
                        if(final_triplets.find(triplet_string) == final_triplets.end())
                            final_triplets[triplet_string] = triplet;
                    }
                }
            }
        }
        for(auto i : final_triplets) {
            vector<int> triplet = i.second;
            result.push_back({ triplet[0], triplet[1], triplet[2] });
        }
        return result;
    }
};