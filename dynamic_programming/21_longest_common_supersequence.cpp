/*
Problem:
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

Example 2:
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"

Solution:
1. Calculate the dp array of lcs
2. the shortest supersequence will be = len(str1) + len(str2) - lcs(str1, str2)
3. Start from the bottom right
4. just like printing lcs, we will take the chars as follows:
    - once when they are equal
    - if we move up then take row value that will get out of the bounds
    - if we move left then take column value which will go out of the bounds

Time Complexity: O(m*n)
Space Complexity: O(m*n)

Link: https://leetcode.com/problems/shortest-common-supersequence
*/

#include <iostream>
#include <vector>

using namespace std;

string shortestSupersequence(string a, string b)
{
	int m = a.size();
	int n = b.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	string ans = "";
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			// take only once
			ans += a[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1]) {
			// move up
			ans += a[i - 1];
			i--;
		}
		else {
			// move left
			ans += b[j - 1];
			j--;
		}
	}
	while (i > 0) {
		ans += a[i - 1];
		i--;
	}
	while (j > 0) {
		ans += b[j - 1];
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string a = "brute";
	string b = "groot";
	cout << shortestSupersequence(a, b);
}