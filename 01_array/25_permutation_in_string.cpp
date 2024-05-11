/*
Problem:
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Solution:
1. create a signature of s1
2. create a window of size s1 in s2
3. maintain a signature of s2 window
4. compare signature and keep shifting window while updating signature as well

Time: O(s2)
Space: O(s1)

Link: https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool compare_signature(vector<int>& sig1, vector<int>& sig2) {
        bool equal = true;
        for(int i = 0; i < 26; i++) {
            if(sig1[i] != sig2[i]) {
                equal = false;
                break;
            }
        }
        return equal;
    }
    vector<int> create_signature(string s, int i , int j) {
        vector<int> signature(26, 0);
        for(int t = i; t <= j; t++)
            signature[s[t] - 'a']++;
        return signature;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        int i = 0, j = s1.size() - 1;
        vector<int> signature = create_signature(s1, 0, s1.size() - 1);
        vector<int> window = create_signature(s2, 0, s1.size() - 1);
        while(!compare_signature(signature, window) && j < s2.size() - 1) {
            window[s2[i] - 'a']--;
            i++;
            j++;
            window[s2[j] - 'a']++;
        }
        return compare_signature(signature, window);
    }
};