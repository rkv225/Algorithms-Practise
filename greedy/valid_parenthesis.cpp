/*
Problem:
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
The following rules define a valid string:
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

DP Solution:
Use dynamic programming with memoization anf convert a recusrsive solution with params curr index and number of open parenthesis. 
This would lead to a time complexity of exponential i.e. O(3^n) and memoization will reduce it to O(n^3)

Greedy Solution: 
1. Have two counters one counter (cmax) for counting the maximum number of right braces we can accommodate with current left braces and stars.
2. Have a second counter(cmin) which represents the minimum number of right braces that must be there further to make sure the whole string is valid(this number can’t be negative, so if it becomes negative then we put it to zero.
3. At any time, if cmax becomes negative, it means we can’t accommodate current right braces with current left braces and stars. So, we return false.
4. In the end if cmin is positive then it means that at least there should be a cmin number of right braces to make sure the overall string is valid. So, we check whether cmin is zero or not and return the answer

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://leetcode.com/problems/valid-parenthesis-string
*/

class Solution {
public:
    bool checkValidString(string s) {
        int min_count = 0, max_count = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                min_count++;
                max_count++;
            } else if(s[i] == ')') {
                min_count--;
                max_count--;
            } else {
                // we need to consider both cases here
                min_count--;
                max_count++;
            }
            // we need to consider the positive cases
            if(min_count < 0)
                min_count = 0;
            // if no open parenthesis to balance close parenthesis
            if(max_count < 0)
                return false;
        }
        // after all the chars have been processed, open parantheisis count should be 0
        return min_count == 0;
    }
};