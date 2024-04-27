/*
Problem:
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

Solution: 
1. Start from the first matching character in the grid.
2. Then replace the character in the grid with placeholder as we can only use a character once.
3. Keep moving in all directions until we get the entire string
4. If at any point while recursion we encounter boundary or character not equal then we terminate

Time Complexity: O(n x 3^l) -> n = # of cells, l = length of word
Space Complexity: O(l)

Link: https://leetcode.com/problems/word-search/
*/

class Solution {
public:
    bool rec(int i, int j, int k, vector<vector<char>>& board, string word, int m, int n) {
        if(k >= word.size())
            return true;
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[k])
            return false;
        board[i][j] = '#';
        if(
            rec(i, j - 1, k + 1, board, word, m, n) ||
            rec(i, j + 1, k + 1, board, word, m, n) ||
            rec(i - 1, j, k + 1, board, word, m, n) ||
            rec(i + 1, j, k + 1, board, word, m, n)
        )
            return true;
        board[i][j] = word[k];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == word[0])
                    if(rec(i, j, 0, board, word, m, n)) 
                        return true;
        return false;
    }
};