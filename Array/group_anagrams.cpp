/*
Problem: 

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Solution: 
1. As we know that we only have 26 alphabets to consider
2. We create a signature of 26 char string which will have a blueprint of the string
3. We then store each of the blueprint in a map with strings having same map
4. create a vector of vectors from map

Time Complexity: O(N * 26)
Space Complexity: O(N)

Link: https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    string create_signature(string& s) {
        vector<char> sig(26);
        for(int i = 0; i < s.size(); i++) {
            sig[s[i] - 'a']++;
        }
        string str(sig.begin(), sig.end());
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> ana;
        for(int i = 0; i < strs.size(); i++) {
            ana[create_signature(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(map<string, vector<string>>::iterator it = ana.begin(); it != ana.end(); it++) {
            ans.push_back((*it).second);
        }
        return ans;
    }
};