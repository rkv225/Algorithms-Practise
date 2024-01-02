/*
Problem: There is a frog on the '1st' step of an 'N' stairs long staircase. 
The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

Link: https://www.codingninjas.com/studio/problems/frog-jump_3621012

Time Complexity: O(n) and space complexity: O(n)
*/

int frogJump(int n, vector<int> &h)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
    return dp[n - 1];
}

/*
* Space optimization: we don't need the entire dp array, our current interation just needs the last 2 values.
* O(1)
*/
int frogJump(int n, vector<int> &h)
{
    int prev2 = 0;
    int prev = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++) {
      int curr = min(prev2 + abs(h[i] - h[i - 2]), prev + abs(h[i] - h[i - 1]));
      prev2 = prev;
      prev = curr;
    }
    return prev;
}