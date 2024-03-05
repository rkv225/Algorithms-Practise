/*
Problem: 
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Solution:

We have to rotate k places-

To rotate right split as: 0 -- n-k-1 & n-k -- n-1
To rotate left split as: 0 -- k-1 & k -- n-1

1. Split the array into 2 parts. 
2. Reverse each part separately.
3. Reverse the entire array.

Time Complexity: O(n)

Space Complexity: O(1)

Link: https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void reverse_array(vector<int> &nums, int i, int j) {
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse_array(nums, n - k, n - 1);
        reverse_array(nums, 0, n - k - 1);
        reverse_array(nums, 0, n - 1);
    }
};