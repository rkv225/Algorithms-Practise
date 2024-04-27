/*
Problem:
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Link: https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            // check for start of sequence
            if(s.find(nums[i] - 1) == s.end()) {
                // prev num not found, a new sequence starts from here
                int cur = 0;
                int seq = nums[i];
                while(s.find(seq) != s.end()) {
                    cur++;
                    seq++;
                }
                maxi = max(maxi, cur);
            }
        }
        return maxi;
    }
};