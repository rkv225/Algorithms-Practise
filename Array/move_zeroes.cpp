/*
Problem:
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

Solution:

Get the first zero element and then iterate till the end of the array.
As soon as you encounter any non zero swap it with zero an adavce zero poiner.
This way all the zeroes will come to last and array will exhaust by cur pointer.

Time Complexity: O(n)

Space Complexity: O(1)

Link: https://leetcode.com/problems/move-zeroes/description/
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int fzr = -1;
        int num = nums.size();
        // find the first zero
        while(cur < num && nums[cur] != 0)
            cur++;
        fzr = cur;
        // now after the first zero till the end of array
        cur++;
        while(cur < num) {
            if(nums[cur] != 0) {
                swap(nums[cur], nums[fzr]);
                fzr++;
            }
            cur++;
        }
    }
};