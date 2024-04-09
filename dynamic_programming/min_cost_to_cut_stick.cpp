/*
Problem:
Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:

|-|-|-|-|-|-|
0 1 2 3 4 5 6

Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
Return the minimum total cost of the cuts.

Example 1:
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

Example 2:
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

Solution: Memoization
1. Append a 0 at beginning and n at the end of the cuts to indicate no cuts situation and this will also aid in calculating the length of the stick after cut.
2. Sort the array as we need to partition and the index needs to be in the partition
3. Now start with the entire range of cuts
4. check all possible combination of cuts possible within given range and store minimum cost.
5. add curr cost and return

Time Complexity: O(n^3)
Space Complexity: O(n^2)

Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/

class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i > j) return 0;
        if(dp[i][j] > -1) return dp[i][j];
        int cur_cost = cuts[j + 1] - cuts[i - 1];
        dp[i][j] = 1e8;
        for(int index = i; index <= j; index++)
            dp[i][j] = min(dp[i][j], f(i, index - 1, cuts, dp) + f(index + 1, j, cuts, dp));
        dp[i][j] += cur_cost;
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        sort(cuts.begin(), cuts.end());
        return f(1, cuts.size() - 2, cuts, dp);
    }
};