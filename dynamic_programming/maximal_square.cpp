/*
Problem:
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

Solution:
1. initalize first row and column equal to the value in matrix
2. for each element compute the largest square that can be made at bottom right
3. keep a global maxi to store maximum

Time Complexity: O(n*n)
Space Complexity: O(n*n)

Link: https://leetcode.com/problems/maximal-square
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // declare dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // maxi to store global max
        int maxi = 0;
        // fill first column
        for(int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            if(maxi == 0 && matrix[i][0] == '1')
                maxi = 1;
        }
        // fill first row
        for(int j = 1; j < n; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            if(maxi == 0 && matrix[0][j] == '1')
                maxi = 1;
        }
        // for all elements compute the current value using previous values
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] == '1') {
                    int top = dp[i - 1][j];
                    int diagonal = dp[i - 1][j - 1];
                    int left = dp[i][j - 1];
                    dp[i][j] = min(top, min(diagonal, left)) + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        // maxi hold the value of biggest square, area of square = x * x
        return maxi * maxi;
    }
};