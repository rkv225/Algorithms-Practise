/*
Problem:
Given an integer array nums, return the length of the longest strictly increasing subsequence

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Link: https://leetcode.com/problems/longest-increasing-subsequence
*/

/*
Solution: 
Time Complexity: O(n * n)
Space Complexity: O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
    }
};

/*
Extension: Print LIS
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    pair<int, int> lengthOfLIS(vector<int>& nums, vector<int>& prev) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        int index = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > maxi) {
                        maxi = dp[i];
                        index = i;
                    }
                }
            }
        }
        pair<int, int> res(maxi, index);
        return res;
    }
    vector<int> getLIS(vector<int>& nums, vector<int>& prev, int index) {
        vector<int> lis;
        while (prev[index] != -1) {
            lis.push_back(nums[index]);
            index = prev[index];
        }
        lis.push_back(nums[index]);
        reverse(lis.begin(), lis.end());
        return lis;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
    vector<int> prev(nums.size(), -1);
    pair<int, int> res = s.lengthOfLIS(nums, prev);
    vector<int> lis = s.getLIS(nums, prev, res.second);
    cout << "Max LIS length: " << res.first << endl;
    cout << "Max LIS: ";
    for (auto i : lis)
        cout << i << " ";
}

/*
Solution: Binary search optimized solution
Time Complexity: O(n * log n)
Space Complexity: O(n)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for(int i = 1; i < n; i++) {
            if(dp.back() < nums[i]) {
                dp.push_back(nums[i]);
            } else {
                vector<int>::iterator sc = lower_bound(dp.begin(), dp.end(), nums[i]);
                *sc = nums[i];
            }
        }
        return dp.size();
    }
};