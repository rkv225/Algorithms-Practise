/*
* Search for an element for an infinite sorted array using binary search in O(nlogn)
* Solution: create a window of size 1 initially and keep on shifting and increasing by power of 2 
* If the element if greater than window max element then shift
* else element lies within the current window, so perform a binary search in it
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

bool inf_binary_search(vector<int>& arr, int low, int high, int key)
{
	while (high < arr.size() && key > arr[high])
	{
		low = high;
		high = 2 * high;
	}
	if (high >= arr.size())
		high = arr.size() - 1;
	return binary_search(arr, low, high, key);
}

int main()
{
	vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	bool found = inf_binary_search(arr, 0, 1, 31);
}