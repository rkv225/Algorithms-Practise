/*
* Finding element in sorted rotated array using binary search technique
* Solution: find the mid element, atleast one side will be sorted.
* if element present in sorted side then perform binary search 
* otherwise keep on recursing until array is exhausted or element is found in a sorted portion
*/

#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<int>& arr, int low, int high, int key)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key == arr[mid])
			return true;
		if (key < arr[mid])
			high = mid - 1;
		if (key > arr[mid])
			low = mid + 1;
	}
	return false;
}

bool array_search(vector<int>& arr, int low, int high, int key)
{
	if (low >= high)
		return false;
	int mid = (low + high) / 2;
	bool left_sorted = false;
	if (arr[low] < arr[mid]) // left is sorted
	{
		left_sorted = true;
		if (key >= arr[low] && key <= arr[mid]) // key is present in left
			return binary_search(arr, low, mid, key);
	}
	if (arr[mid + 1] < arr[high] && key >= arr[mid + 1] && key <= arr[high]) // right is sorted & key is present in right
		return binary_search(arr, mid + 1, high, key);
	if (left_sorted) // means that the key was not present in left sorted part
		return array_search(arr, mid + 1, high, key); // search the right part that is not sorted
	return array_search(arr, low, mid, key); // search the left part that is not sorted
}

int main()
{
	vector<int> arr = { 6, 7, 8, 9, 1, 2, 3, 4 };
	bool res = array_search(arr, 0, 7, 4);
}