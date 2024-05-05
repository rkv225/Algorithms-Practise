/*
Problem:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Time: O(n)
Space: O(n)

Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        unordered_set<char> window;
        int i = 0, j = 0;
        while(j < s.size()) {
            if(window.find(s[j]) != window.end()) {
                // char repeat, shift from left till you encounter the repeated value
                while(i < j) {
                    window.erase(s[i]);
                    i++;
                    // removed the duplicate value, now no need to remove more values from set
                    if(s[i - 1] == s[j])
                        break;
                }
            }
            window.insert(s[j]); // add to window
            j++; // expand the window
            maxi = max(maxi, j - i); // update max
        }
        return maxi;
    }
};