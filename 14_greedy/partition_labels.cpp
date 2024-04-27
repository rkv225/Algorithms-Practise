/*
Problem:
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
Return a list of integers representing the size of these parts.

Example 1:
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

Example 2:
Input: s = "eccbbbbdec"
Output: [10]

Solution:
1. Store the last index of each character occurance in a map
2. Keep track of begin and end of the partition
3. Now for each character
    - check last index
    - if end is less than last then update end
    - if we reached end of the parition then store it

Time Complexity: O(n)
Space Complexity: O(n) for unordered map

Link: https://leetcode.com/problems/partition-labels
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        for(int i = 0; i < s.size(); i++)
            last[s[i]] = i;
        int beg = 0, end = -1;
        vector<int> ans;
        for(int cur = 0; cur < s.size(); cur++) {
            if(end < last[s[cur]])
                end = last[s[cur]];
            if(cur == end) {
                ans.push_back(end - beg + 1);
                beg = cur + 1;
            }
        }
        return ans;
    }
};