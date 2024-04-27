/*
Problem:
You are given two strings 'S' and 'T' of lengths 'N' and 'M' respectively. Find the "Edit Distance" between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note:
Strings don't contain spaces in between.

Sample Input 1 :
abc
dc
Sample Output 1 :
2
Explanation For Sample Input 1 :
In 2 operations we can make the string T to look like string S. First, insert the character 'a' to string T, which makes it "adc".
And secondly, replace the character 'd' of the string T with 'b' from the string S. This would make string T to "abc" which is also the string S. Hence, the minimum distance.

Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9

Link: https://www.naukri.com/code360/problems/edit-distance_630420
*/

/*
Solution: Memoization
*/
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    if(i < 0 && j < 0) return 0;
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;
    if(dp[i][j] > -1) return dp[i][j];
    if(s[i] == t[j])
        dp[i][j] = f(i - 1, j - 1, s, t, dp);
    else {
        // insert
        int ic = f(i - 1, j, s, t, dp);
        // delete
        int dc = f(i, j - 1, s, t, dp);
        // replace
        int rc = f(i - 1, j - 1, s, t, dp);
        dp[i][j] = 1 + min(ic, min(dc, rc));
    }
    return dp[i][j];
}
int editDistance(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    f(m - 1, n - 1, str1, str2, dp);
    return dp[m - 1][n - 1];
}

/*
Solution: Tabulation
*/
int editDistance(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for(int  i = 1; i <= m; i++)
        dp[i][0] = i;
    for(int j = 1; j <= n; j++)
        dp[0][j] = j;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int ins = dp[i - 1][j];
                int del = dp[i][j - 1];
                int rep = dp[i - 1][j - 1];
                dp[i][j] = 1 + min(ins, min(del, rep));
            }
        }
    }
    return dp[m][n];
}