/*
Problem:

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.
On a standard telephone keyboard, each number from 2 to 9 corresponds to a set of letters:
2: {a, b, c}
3: {d, e, f}
4: {g, h, i}
5: {j, k, l}
6: {m, n, o}
7: {p, q, r, s}
8: {t,u,v}
9: {w, x, y, z}

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

Solution:

1. start with empty prefix and 0 index
2. take character one by one and add it to prefix and do recursion by incrementing the index
3. when the input string is exhausted, put the prefix into ans

Time Complexity: O(n^n)
Space Complexity: O(n^n)

Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    string getMapping(char digit) {
        switch(digit)
        {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: return "";
        }
    }
    void rec(string digits, int index, int n, string prefix, vector<string>& ans) {
        if(index >= n) {
            if(prefix.size() > 0)
                ans.push_back(prefix);
            return;
        }
        string mp = getMapping(digits[index]);
        for(int i = 0; i < mp.size(); i++) {
            rec(digits, index + 1, n, prefix + mp[i], ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string prefix = "";
        rec(digits, 0, digits.size(), prefix, ans);
        return ans;
    }
};