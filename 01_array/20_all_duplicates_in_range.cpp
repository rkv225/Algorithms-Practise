/*
Problem:
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant extra space.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Example 2:
Input: nums = [1,1,2]
Output: [1]

Example 3:
Input: nums = [1]
Output: []

Solution:
As we know that the numbers are in range 1 to n.
So we can use our exiting array as a hashmap and mark the elements as negative if that value at that index is found.
If we see a negative value already present that means we have a duplicate

Time: O(n)
Space: O(1)

Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if(nums[cur - 1] > 0) {
                // mark visited
                nums[cur - 1] = nums[cur - 1] * -1;
            } else {
                // already negative then duplicate
                ans.push_back(cur);
            }
        }
        return ans;
    }
};