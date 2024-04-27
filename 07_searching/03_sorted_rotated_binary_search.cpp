/*
* Finding element in sorted rotated array using binary search technique

* Solution: find the mid element, atleast one side will be sorted.
* if element present in sorted side then perform binary search 
* otherwise keep on recursing until array is exhausted or element is found in a sorted portion

Time Complexity: O(log n)
Space Complexity: O(1)

Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int>& nums, int t, int i, int j) {
	if(i > j)
		return -1;
	int mid = (i + j) / 2;
	if(nums[mid] == t)
		return mid;
	else if(t < nums[mid])
		return bs(nums, t, i, mid - 1);
	else
		return bs(nums, t, mid + 1, j);
}
int search_helper(vector<int>& nums, int target, int i, int j) {
	if(i == j && nums[i] == target)
		return i;
	if(i >= j)
		return -1;
	int mid = (i + j) / 2;
	if(nums[i] <= nums[mid] && target <= nums[mid] && target >= nums[i]) {
		// left is sorted and target in left
		return bs(nums, target, i, mid);
	} else if(nums[mid + 1] <= nums[j] && target >= nums[mid + 1] && target <= nums[j]) {
		// right is sorted and target in right
		return bs(nums, target, mid + 1, j);
	} else if(nums[i] <= nums[mid]) {
		// left is sorted but target in right
		return search_helper(nums, target, mid + 1, j);
	} else {
		// target in left
		return search_helper(nums, target, i, mid);
	}
}
int search(vector<int>& nums, int target) {
	int n = nums.size();
	int i = 0, j = n - 1;      
	return search_helper(nums, target, i, j);
}
int main()
{
	vector<int> arr = { 6, 7, 8, 9, 1, 2, 3, 4 };
	bool res = search(arr, 4);
}