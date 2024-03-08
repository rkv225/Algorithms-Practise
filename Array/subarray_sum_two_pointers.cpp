/*
Problem:
You are given an array 'a' of size 'n' and an integer 'k'.
Find the length of the longest subarray of 'a' whose sum is equal to 'k'.

Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]
Output: 3
Explanation: Subarrays whose sum = ‘3’ are: [1, 2], [3], [1, 1, 1] and [1, 1, 1]
Here, the length of the longest subarray is 3, which is our final answer.

Solution:
Take two pointers at beginning of the array.
init sum = 0;
increase the sum and inc j pointer if it's less than k
decrease the sum and inc i pointer if greater than k
if(sum == k) then calc length and compare with existing
return the max length

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
*/

int longestSubarrayWithSumK(vector<int> a, long long k) {
  int n = a.size();
  int i = 0, j = 0;
  long long s = 0;
  int l = 0;
  while (j < n) {
    if (s <= k) {
      s = s + a[j];
      j++;
    } else if(s > k) {
      s = s - a[i];
      i++;
    }
    if(s == k) 
      l = max(l, j - i);
  }
  return l;
}