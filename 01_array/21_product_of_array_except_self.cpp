/*
Problem:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Solution:
1. calculate left prefix
2. calculate right postfix
3. at any point ans will be left prefix * right postfix
Space optimization:
we can store the result in ans directly 

Time Complexity: O(n)
Space Complexity: O(1) // ans storage doesn't count

Link: https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        // compute left prefix and store ans
        int prefix = 1;
        for(int i = 0; i < nums.size(); i++) {
            ans[i] = prefix;
            prefix = prefix * nums[i];
        }
        // compute right and update ans
        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = ans[i] * postfix;
            postfix = postfix * nums[i];
        }
        return ans;
    }
};