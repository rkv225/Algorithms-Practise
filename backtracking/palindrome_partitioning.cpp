/*
Problem: 

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.

Solution:

1. start with a left partition that is a palindrome (we have to consider all the partitions by shifting the index)
2. push it to prefix and do recursion on right part
3. when right part is exhausted then add to ans
4. while backtracking remove the last prefix that was added

Time Complexity: O(n x 2^n)
Space Complexity: O(n)

Link: https://leetcode.com/problems/palindrome-partitioning
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> prefix;
        rec(s, prefix, ans);
        return ans;
    }
    void rec(string s, vector<string>& prefix, vector<vector<string>>& ans) {
        if(s.size() == 0) {
            ans.push_back(prefix);
            return;
        }
        for(int i = 1; i <= s.size(); i++) {
            string left = s.substr(0, i);
            if(is_palindrome(left)) {
                prefix.push_back(left);
                string right = i < s.size() ? s.substr(i, s.size() - i) : "";
                rec(right, prefix, ans);
                prefix.pop_back();
            }
        }
    }
    bool is_palindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i <= j && s[i] == s[j]) {
            i++;
            j--;
        }
        return i > j;
    }
};