/*
Problem:
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Solution:
1. Take a pointer dest at destination n
2. Calculate the distance from n-1 position 
3. If we can reach destination from cur pointer then we shift the destination to cur else check from preceeding values
4. Keep on moving till entire array is traversed in reverse
5. if dest == 0 then we an reach end otherwise we can't

Space Complexity: O(1)
Time Complexity: O(n)

Link: https://leetcode.com/problems/jump-game/
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dest = nums.size() - 1;
        for(int cur = nums.size() - 2; cur >= 0; cur--)
            if(nums[cur] >= dest - cur)
                dest = cur;
        return dest == 0;
    }
};