/*
Problem:
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Example:
Input: ‘R’ = 3, ‘C’ = 4
       ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.

Link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885
*/

/*
solution: recusrion
time: O(2^r*c*c)
space: stack
*/
int f(int i, int ja, int jb, int r, int c, vector<vector<int>> &grid) {
    if(ja < 0 || ja >= c || jb < 0 || jb >= c)
        return -1e8;
    int cur_value = ja == jb ? grid[i][ja] : grid[i][ja] + grid[i][jb];
    if (i == r - 1) 
        return cur_value;
    int value = -1e8;
    for (int am = -1; am <= 1; am++) {
        for (int bm = -1; bm <= 1; bm++) {
            value = max(value, f(i + 1, ja + am, jb + bm, r, c, grid));
        }
    }
    return cur_value + value;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0, 0, c - 1, r, c, grid);
}

/*
solution: tabulation
time: O(r*c*c*9)
space: O(r*c*c)
*/
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1e8)));
    
    // base case
    for(int i = 0; i < c; i++)
        for(int j = 0; j < c; j++)
            if(i == j) dp[r - 1][i][j] = grid[r - 1][i];
            else dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];

    for (int i = r - 2; i >= 0; i--) {
        for (int ja = 0; ja < c; ja++) {
            for (int jb = 0; jb < c; jb++) {
                int cur_value = ja == jb ? grid[i][ja] : grid[i][ja] + grid[i][jb];
                int value = -1e8;
                for (int am = -1; am <= 1; am++) {
                    for (int bm = -1; bm <= 1; bm++) {
                        if(ja + am >= 0 && ja + am <= c - 1 && jb + bm >= 0 && jb + bm <= c - 1)
                            value = max(value, dp[i + 1][ja + am][jb + bm]);
                    }
                }
                dp[i][ja][jb] = cur_value + value;
            }
        }
    }
    return dp[0][0][c - 1];
}