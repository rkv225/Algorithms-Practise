/*
Problem:
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Solution: 
Take 2 pointers, i at beginning and j at end of the array.
As the array is sorted, take the sum then shift from left if sum is small or shift from right if sum is large.

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int i = 0;
        int j = n.size() - 1;
        int s = 0;
        while(i < j) {
            s = n[i] + n[j];
            if(s == t)
                break;
            else if(s > t)
                j--;
            else i++;
        }
        return { i + 1, j + 1 };    
    }
};