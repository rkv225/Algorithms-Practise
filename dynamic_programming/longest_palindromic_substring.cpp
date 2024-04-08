/*
Problem:
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Solution:
Expand around center, extend as far as possible, store max length

Time Complexity: O(n^2)
Space Complexity: O(1)

Link: https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    void check_expand(int i, int j, int& max_left, int& max_right, int& max_length, string& s) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            if(j - i + 1 > max_length) {
                max_length = j - i + 1;
                max_left = i;
                max_right = j;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        int max_left = 0, max_right = 0, max_length = -1;
        for(int i = 0; i < s.size() - 1; i++) {
            // for odd length
            check_expand(i, i, max_left, max_right, max_length, s);
            // for even length
            check_expand(i, i + 1, max_left, max_right, max_length, s);
        }
        string ans;
        for(int i = max_left; i <= max_right; i++)
            ans.push_back(s[i]);
        return ans;
    }
};

/*
Problem Variation:
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Link: https://leetcode.com/problems/palindromic-substrings/
*/

class Solution {
public:
    void check_expand(int i, int j, int& count, string& s) {
        while(i >= 0 && j < s.size() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++) {
            // for odd length
            check_expand(i, i, count, s);
            // for even length
            check_expand(i, i + 1, count, s);
        }
        return count;
    }
};