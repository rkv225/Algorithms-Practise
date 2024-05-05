/*
Problem:

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.
Please implement encode and decode

Example 1:
Input: ["neet","code","love","you"]
Output:["neet","code","love","you"]

Example 2:
Input: ["we","say",":","yes"]
Output: ["we","say",":","yes"]

Link: https://neetcode.io/problems/string-encode-and-decode
*/

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0; i < strs.size(); i++) {
            if(strs[i].size() == 0)
                encoded += "~";
            else
                encoded += strs[i] + "~";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string curr = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '~') {
                decoded.push_back(curr);
                curr = "";
            } else {
                curr += s[i];
            }
        }
        return decoded;
    }
};