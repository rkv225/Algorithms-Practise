/*
* Problem: find nth fibonacci number
* Solution: f(n) = f(n-1) + f(n-2)
* Time complexity: O(n) and space complexity O(n)
* Link: https://takeuforward.org/data-structure/dynamic-programming-introduction/ 
*/

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n, vector<int>& dp)
{
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}

int main()
{
	int n = 25;
	vector<int> dp(n + 1, -1);
	cout << fibonacci(n, dp);
}