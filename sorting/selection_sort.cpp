/*
* Selection sort is also a O(n^2) sorting technique which is inplace and stable
*/

#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &arr, int n) // ascending sorting
{
	for (int i = 0; i < n - 1; i++)
	{
		// find minimum after index i
		int min = arr[i];
		int min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_index = j;
			}
		}
		// place the number min number on ith index
		swap(arr[i], arr[min_index]);
	}
}

int main()
{
	vector<int> arr = { 1, 45, 54, 71, 76, 12 };
	selection_sort(arr, arr.size());
	cout << "Sorted array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";
	return 0;
}
