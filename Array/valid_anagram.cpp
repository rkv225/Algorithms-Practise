/*
Problem:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Solution:
place all the values of string s in hashmap and then remove while iterating string t
if any value at map contains negative or positive value then it's not anagram

Time Complexity: O(n)
Space Complexity: O(26) = O(1)

Link: https://leetcode.com/problems/valid-anagram
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]]++;
        for(int j = 0; j < t.size(); j++)
            m[t[j]]--;
        for(int i = 0; i < m.size(); i++)
            if(m[i] != 0)
                return false;
        return true;
    }
};