/*
Problem:
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Link: https://leetcode.com/problems/wildcard-matching/
*/

/*
Solution: Memoization

Time Complexity: O(m * n)
Space Complexity: O(m * n) + stack space
*/
class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        // both strings are exhausted
        if(i < 0 && j < 0) return true;
        
        // if second string is not exhausted it should only have wilcards to return true
        if(i < 0 && j >= 0) {
            while(j >= 0) {
                if(p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }
        
        // if first string has values
        if( i >= 0 && j < 0) return false;
        
        // chars not equal
        if(s[i] != p[j] && p[j] != '*' && p[j] != '?') return false;

        // if already in dp
        if(dp[i][j] > -1) return dp[i][j] > 0;

        if(s[i] == p[j] || p[j] == '?') {
            dp[i][j] = f(i - 1, j - 1, s, p, dp);
        } else {
            bool empty = f(i, j - 1, s, p, dp);
            bool star = f(i - 1, j, s, p, dp);
            dp[i][j] = empty || star;
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, s, p, dp);
    }
};

/*
Solution: Tabulation

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // true for both empty
        dp[0][0] = true;

        // for all string lengths of 0 all the patterns starting with stars will match
        bool x = true;
        for(int j = 1; j <= n; j++) {
            x = x && p[j - 1] == '*';
            dp[0][j] = x;
        }      
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] != p[j - 1] && p[j - 1] != '*' && p[j - 1] != '?') 
                    dp[i][j] = false;
                else if(s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];              
            }
        }
        return dp[m][n];
    }
};