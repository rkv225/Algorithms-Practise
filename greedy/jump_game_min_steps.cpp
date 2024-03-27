/*
Problem:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Link: https://leetcode.com/problems/jump-game-ii
*/

/*
Solution: using DP
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_jumps(n, 1e8);
        min_jumps[0] = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j <= nums[i] + i && j < n; j++) {
                min_jumps[j] = min(min_jumps[j], min_jumps[i] + 1);
            }
        }
        return min_jumps[n - 1];
    }
};

/*
Solution: Greedy Optimized
1. We have maintain a window and a farthest point that can be reached from that window.
2. Initially start with cur = 0 and end = 0
3. Calculate the farthest point that can be reached.
4. If we reach end then increment the steps and return
5. if we traversed entire window then extend the window and increase the steps
6. reapeat the process till we reach end

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cur = 0, end = 0, farthest = 0, steps = 0;
        while(cur < n - 1) {
            farthest = max(farthest, cur + nums[cur]);
            if(farthest >= n - 1) { // reached end
                steps++;
                break;
            }
            if(cur == end) { // window traversed
                steps++;
                end = farthest;
            }
            cur++;
        }
        return steps;
    }
};