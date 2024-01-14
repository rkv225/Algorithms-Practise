/*
Problem: Given a String, find the longest palindromic subsequence

Link: https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

/*
tabulation approach 
*/
int longestPalinSubseq(string A) {
    string s = A;
    string t = string(A.rbegin(), A.rend());
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s.size()][t.size()];
}

/*
Problem Variation: 
A palindrome string is one that reads the same backward as well as forward.
You are given a string 'str'.
Find the minimum number of characters needed to insert in 'str' to make it a palindromic string.

Example :
Input: 'str' = "abca"

Output: 1

Explanation:
If we insert the character ‘b’ after ‘c’, we get the string "abcba", which is a palindromic string. Please note that there are also other ways possible.

Link: https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-palindrome_985293

*/
int longestPalinSubseq(string &A) {
    string s = A;
    string t = string(A.rbegin(), A.rend());
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return A.size() - dp[s.size()][t.size()];
}

int minimumInsertions(string &str)
{
	return longestPalinSubseq(str);
}