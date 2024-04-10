/*
Problem:
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

Solution:
1. Front partition
2. if string already palindrome, no need to partition
3. try all possible ways and solve the other part and take the minimum

Time Complexity: O(n*n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/palindrome-partitioning-ii
*/

class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i <= j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i > j;
    }
    int f(int i, int j, string &s, vector<int> &dp) {
        // string exhausted
        if(i >= j) return 0;
        // aready computed
        if(dp[i] > -1) return dp[i];
        // if given portion is already a palindrome, we don't need to partition it
        if(isPalindrome(i, j, s)) return 0; 
        int mini = 1e8;
        // try all index where we can partition
        for(int index = i; index <= j; index++) {
            if(isPalindrome(i, index, s)) {
                int cur = 1 + f(index + 1, j, s, dp);
                mini = min(mini, cur);
            }
        }
        dp[i] = mini;
        return dp[i];
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return f(0, s.size() - 1, s, dp);      
    }
};