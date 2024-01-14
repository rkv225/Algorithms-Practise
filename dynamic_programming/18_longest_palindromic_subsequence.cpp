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