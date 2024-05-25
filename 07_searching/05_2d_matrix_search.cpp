/*
Problem:
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Solution:
first do binary search row wise  then do binary search on a row that may contain value

Time: O(log (m * n))
Space: O(1)

Link: https://leetcode.com/problems/search-a-2d-matrix/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), row = -1, i, j;
        // perform binary search on rows
        i = 0; j = m - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            if(target < matrix[mid][0])
                j = mid - 1;
            else if(target > matrix[mid][n - 1])
                i = mid + 1;
        }
        if(row < 0)
            return false;
        // perform binary search in row
        i = 0; j = n - 1;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(matrix[row][mid] == target)
                return true;
            if(target < matrix[row][mid])
                j = mid - 1;
            else
                i = mid + 1;
        }
        return false;
    }
};