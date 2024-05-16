/*
Problem:
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Solution:
using stack to keep next greater element and it's index

Time: O(n)
Space: O(n)

Link: https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<pair<int, int>> st;
        // base case: we can't have warmer temp if only one is given
        if(temperatures.size() == 1)
            return { 0 };
        // rightmost temp can't have ant temp in future
        ans[temperatures.size() - 1] = 0;
        // start with rightmost temp in stack
        st.push(make_pair(temperatures[temperatures.size() - 1], temperatures.size() - 1));
        for(int i = temperatures.size() - 2; i >= 0; i--) {
            // keep popping unless u get temp greater than curr
            while(!st.empty() && st.top().first <= temperatures[i])
                st.pop();
            if(st.empty()) // no temp greater than curr found
                ans[i] = 0;
            else // store index of greater temp
                ans[i] = st.top().second - i;
            // push curr to stack
            st.push(make_pair(temperatures[i], i));
        }
        return ans;
    }
};