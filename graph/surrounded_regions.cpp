/*
problem:
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Our task is to give the board that will be after capture.
A O is only safe if it's connected to a O at the border

solution: from all the border elements perform dfs if it's O.
mark them as safe 'S' if previous is safe
replace O with X and S with O

time complexity: O(MN)

link: https://leetcode.com/problems/surrounded-regions
*/

void dfs(int i, int j, char p, int m, int n, vector<vector<char>>& board) {
    if(i >= 0 && i < m && j >= 0 && j < n && p == 'S' && board[i][j] == 'O') {
        board[i][j] = 'S'; 
        dfs(i - 1, j, board[i][j], m, n, board);
        dfs(i + 1, j, board[i][j], m, n, board);
        dfs(i, j - 1, board[i][j], m, n, board);
        dfs(i, j + 1, board[i][j], m, n, board);
    }
}
void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();
    // top
    for(int i = 0; i < n; i++)
        if(board[0][i] == 'O')
            dfs(0, i, 'S', m, n, board);
    // bottom
    for(int i = 0; i < n; i++)
        if(board[m - 1][i] == 'O')
            dfs(m - 1, i, 'S', m, n, board);
    // left
    for(int i = 0; i < m; i++)
        if(board[i][0] == 'O')
            dfs(i, 0, 'S', m, n, board);
    // right
    for(int i = 0; i < m; i++)
        if(board[i][n - 1] == 'O')
            dfs(i, n - 1, 'S', m, n, board);
    // revert back S to O
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'O')
                board[i][j] = 'X'; 
            else if(board[i][j] == 'S')
                board[i][j] = 'O';
}