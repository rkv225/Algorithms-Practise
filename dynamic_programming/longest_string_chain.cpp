/*
Problem: 

You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

Solution:
As elements can be taken in any order and we need to find the subset that forms longest chain
1. Sort the list, now we need to find the longest increasing subsequence of words
2. Find the longest increasing subsequence just instead of value we need to check if string can be predecessor

Time Complexity: O(n*n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/longest-string-chain
*/

bool comp(string &s, string &t) {
    return s.size() < t.size();
}
class Solution {
public:
    bool isPre(string &s, string &t) {
        // if s greater than t by more than 1 or equal then t can't be predecessor of s 
        if(s.size() - t.size() != 1) return false;
        // we know that s and t differ by only 1 size, so we need to check that t lies in order in s
        int ss = s.size(), ts = t.size(), i = 0, j = 0;
        while(i < ss && j < ts) {
            if(s[i] == t[j]) {
                // advance both
                i++;
                j++;
            } else {
                // i has extra element
                i++;                
            }
        }
        // if all the elements from t are found in order in s
        return j == ts;
    } 
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(isPre(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};