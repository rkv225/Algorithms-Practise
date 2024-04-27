#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int> arr, int key)
{
	int l = 0;
	int r = arr.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (arr[mid] == key) // key found, terminate
			return mid;
		if (arr[mid] > key) // search in left half of array
			r = mid - 1;
		else // search in right half of array
			l = mid + 1;
	}
	return -1; // key not found
}

int main()
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	cout << binary_search(arr, 3) << endl;
	cout << binary_search(arr, 10) << endl;
	cout << binary_search(arr, 5) << endl;
	cout << binary_search(arr, 0) << endl;
	cout << binary_search(arr, 9) << endl;
	cout << binary_search(arr, 1) << endl;
	cout << binary_search(arr, 7) << endl;
}
