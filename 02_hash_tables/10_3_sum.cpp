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
In this approach, firstly, we will hash the indices of all elements in a hashMap. In case of repeated elements, the last occurence index would be stored in hashMap.
Here also we fix a number (num[i]), by traversing the loop. But the loop traversal here for fixing numbers would leave last two indices. These last two indices would be covered by the nested loop.
If number fixed is +ve, break there because we can't make it zero by searching after it.
Make a nested loop to fix a number after the first fixed number. (num[j])
To make sum 0, we would require the -ve sum of both fixed numbers. Let us say this required.
Now, we will find the this required number in hashMap. If it exists in hashmap and its last occurrence index > 2nd fixed index, we found our triplet. Push it in answer vector.
Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
Update i to last occurence of 1st fixed number to avoid duplicate triplets.
Return answer vector.

Time Complexity: O(n*n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/3sum
*/

