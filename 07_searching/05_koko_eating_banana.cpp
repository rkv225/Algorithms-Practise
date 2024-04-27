/*
Problem:
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23

Solution:
- create a function to eat bananas at given speed and return if it's possible to finish in given time
- take a range on min = 1 to max pile of banana
- apply binary search in this range

Time Complexity: O(n log n)

Link: https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution {
public:
    bool is_safe(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += ceil((double)piles[i]/(double)k);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1, j = *max_element(piles.begin(), piles.end());
        int ans = 1e8;
        while(i <= j) {
            int mid = (i + j) / 2;
            if(is_safe(piles, h, mid)) {
                ans = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};