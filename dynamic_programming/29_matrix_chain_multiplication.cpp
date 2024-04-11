/*
Problem:
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the minimum cost to multiply these matrices. The cost of matrix multiplication is defined as the number of scalar multiplications. A Chain of matrices A1, A2, A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] * arr[2], and so on.
For example:
For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10 * 20], A2 = [20 * 30], A3 = [30 * 40]
Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.

Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
70
8000
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5 3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5] * [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.
In the second test case, there are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then the number of multiplications required is 11250.
If we multiply in order- (A1*A2)*A3, then the number of multiplications required is 8000.
Thus a minimum number of multiplications required is 8000. 

Sample Input 2:
1
4
1 4 3 2
Sample Output 2:
18
Explanation of Sample Output 2:
In the first test case, there are three matrices of dimensions A = [1 4], B = [4 3] and C = [3 2]. The most efficient order of multiplication is (A *  B) * C .

Solution:

- place parentheses at all possible places,
- to calculate the current cost 
ex: A[10x30] and B[30x5] matrices
    number of operations = 10 x 30 x 5 = 150
    Similarly for array,
    [xxxxxxxxx]
      i  k   j
    number of operations for arr[i to k]->[arr[i-1] x arr[k]] and arr[k+1 to j]->[arr[k] x arr[j]] will be arr[i-1]*arr[k]*arr[j]
- calculate the cost for each placement and return the minimum value if partitioned in that manner
- In a chain of matrices of size ‘ n’, we can place the first set of parentheses in ‘n’ - 1 way.

Time Complexity: O(n*n*n)
Space Complexity: O(n*n)

Link: https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344
*/

#include <bits/stdc++.h>
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if(i >= j) return 0;
    if(dp[i][j] > -1) return dp[i][j];
    int mini = INT_MAX;
    for (int index = i; index < j; index++) {
        int cur_op = arr[i - 1] * arr[index] * arr[j];
        mini = min(mini, f(i, index, arr, dp) + f(index + 1, j, arr, dp) + cur_op);
    }
    dp[i][j] = mini;
    return dp[i][j];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, dp);
}