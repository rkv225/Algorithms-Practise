/*
Problem:
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Solution:
Backtracking, keep valid, favor trying opens, then try closes if still valid

Time: O(2^n)
Space: O(n)

Link: https://leetcode.com/problems/generate-parentheses/description/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, 0, 0, "", result);
        return result;
    }
private:
    void generate(int n, int open, int close, string str, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str);
            return;
        }
        if (open < n)
            generate(n, open + 1, close, str + '(', result);
        if (open > close)
            generate(n, open, close + 1, str + ')', result);
    }
};