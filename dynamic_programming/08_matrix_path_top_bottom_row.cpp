/*
Problem: You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)

Link: https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998

Time: O(n*m)
space: O(m)
*/

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev = matrix[n - 1];
    vector<int> curr(m, INT32_MIN);
    for (int i = n - 2; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
          int down = prev[j];
          int leftd = j > 0 ? prev[j - 1] : INT32_MIN;
          int rightd = j < m - 1 ? prev[j + 1] : INT32_MIN;
          curr[j] = max(down, max(leftd, rightd)) + matrix[i][j];
      }
      prev = curr;
    }
    int max_path = INT32_MIN;
    for (int i = 0; i < m; i++) {
        max_path = max(max_path, prev[i]); 
    }
    return max_path;
}