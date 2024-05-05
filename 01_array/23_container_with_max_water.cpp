/*
Problem:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Solution: 
1. keep left and right pointer at start and end of array as we have to get max volume
2. calculate current volume and keep max
3. we need to have max heights as possible at both ends, so we shift from less height

Time: O(n)
Space: O(1)

Link: https://leetcode.com/problems/container-with-most-water/
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxi = -1e9;
        while(i < j) {
            int cur = min(height[i], height[j]) * (j - i);
            maxi = max(maxi, cur);
            if(height[i] < height[j]) 
                i++;
            else
                j--;
        }
        return maxi;
    }
};