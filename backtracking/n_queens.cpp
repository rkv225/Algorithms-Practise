/*
Problem:
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

Solution:
1. for each row, check each column
2. if the column is safe, place Queen
3. move to another row
4. if we have placed on all row then store the ans
5. finally while backtracking restore the queen as we have to find all the possible configurations

Time Complexity: O(n!)
Space Complexity: O(n^2)

Link: https://leetcode.com/problems/n-queens/
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool check(int row, int col, int n, vector<string>& board)
    {
        // check vertically
        for(int i = 0; i < n; i++)
            if(board[i][col] == 'Q')
                return false;

        // check horizontally
        for(int i = 0; i < n; i++)
            if(board[row][i] == 'Q')
                return false;

        // top right
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        // top left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // bottom right
        for (int i = row, j = col; i < n && j < n; i++, j++)
            if (board[i][j] == 'Q')
                return false;

        // bottom left
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 'Q')
                return false;
        
        // safe from all directions
        return true;
    }
    void rec(int index, int n, vector<string>& board, vector<vector<string>>& ans)
    {
        if(index >= n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(check(index, i, n, board)) {
                // place queen
                board[index][i] = 'Q';
                rec(index + 1, n, board, ans);
                // restore board
                board[index][i] = '.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<char> row(n, '.');
        vector<string> board(n, string(row.begin(), row.end()));
        rec(0, n, board, ans);
        return ans;
    }
};