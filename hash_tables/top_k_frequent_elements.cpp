/*
Problem: 
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Link: https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, set<int>, greater<int>> m;
        map<int, int> c;
        for(int i = 0; i < nums.size(); i++) {
            c[nums[i]]++;
            if(c[nums[i]] > 1) {
                m[c[nums[i]] - 1].erase(nums[i]);
            }
            m[c[nums[i]]].insert(nums[i]);
        } 
        int n = 0;
        vector<int> ans;
        for(map<int, set<int>>::iterator it = m.begin(); it != m.end(); it++) {
            set<int> ele = (*it).second;
            for(set<int>::iterator se = ele.begin(); se != ele.end(); se++) {
                if(n < k) ans.push_back(*se);
                n++;
            }
        }
        return ans;
    }
};