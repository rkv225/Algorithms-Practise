/*
Problem:
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique. 

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Link: https://leetcode.com/problems/minimum-window-substring/
*/

/*
Solution:
Here we are not comparing entire signature everytime.
We first consider the maximum window where the condition is satisfied. 
Note we are only storing the chars from t in the map.
Then till the end of the array check keep on shifting and store minimum.

Time: O(n)
Space: O(t)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size())
            return "";
        unordered_map<char, int> t_map;
        unordered_map<char, int> s_map;
        for(int i = 0; i < t.size(); i++)
            t_map[t[i]]++;
        int min_win = 0, max_win = 1e8, min_len = 1e8, i = 0, j = 0, match = 0;
        // fill initial window
        while(j < s.size() && match < t_map.size()) {
            if(t_map.find(s[j]) != t_map.end()) {
                // char in t
                s_map[s[j]]++;
                // required count reached, for greater and smaller we will not increase match
                if(s_map[s[j]] == t_map[s[j]])
                    match++;
            }
            j++;
        }
        j--;
        // traverse entire array 
        while(i <= j) {
            if(match == t_map.size()) {
                if(min_len > j + 1 - i) {
                    // update min window if smaller window found
                    min_win = i;
                    max_win = j + 1;
                    min_len = j + 1 - i;
                }
                if(t_map.find(s[i]) != t_map.end()) {
                    s_map[s[i]]--;
                    if(s_map[s[i]] < t_map[s[i]]) {
                        // count less than req
                        match--;
                    }
                }
                i++;
            } else if(j < s.size() - 1) {
                j++;
                if(t_map.find(s[j]) != t_map.end()) {
                    s_map[s[j]]++;
                    if(s_map[s[j]] == t_map[s[j]]) {
                        // if equal then match
                        match++;
                    }
                }   
            } else {
                break;
            }
        }
        string ans;
        if(min_len < 1e8)
            for(i = min_win; i < max_win; i++)
                ans.push_back(s[i]);
        return ans;
    }
};