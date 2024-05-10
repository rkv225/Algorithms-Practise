/*
Problem:
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Time Complexity: O(n)
Space Complexity: O(26)

Link: https://leetcode.com/problems/longest-repeating-character-replacement
*/

class Solution {
public:
    // we can still consider this function as constant O(1)
    int max_count_element(unordered_map<int, int>& m) {
        int max_count = m[0];
        for(int i = 1; i < 26; i++)
            max_count = max(max_count, m[i]);
        return max_count;
    }
    int characterReplacement(string s, int k) {
        unordered_map<int, int> char_count;
        int i = 0, j = 0, max_count = 0, ans = 0;
        while(j < s.size()) {
            char_count[s[j] - 'A']++;
            max_count = max_count_element(char_count);
            if(j - i + 1 - max_count > k) {
                // window_size - max_count of main char should be less than k as we can only support k operations
                // we need to slide the window to check next elements
                char_count[s[i] - 'A']--;
                i++; 
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};