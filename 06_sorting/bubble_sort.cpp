#include<iostream>
#include<vector>

using namespace std;

/*
* stable sort, in-place sorting algorithm, time-complexity -> O(n^2)
*/
void bubble_sort(vector<int> &arr) // ascending sort
{
	int siz = arr.size();
	for (int pass = 0; pass < siz - 1; pass++) // for n elements n-1 pass are required
	{
		for (int i = 0; i < siz - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
		}
	}
}

int main()
{
	vector<int> arr = { 14, 33, 27, 10, 35, 19, 42, 44 };
	bubble_sort(arr);
	cout << "Sorted Array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
}
