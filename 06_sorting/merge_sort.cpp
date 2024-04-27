#include<iostream>
#include<vector>
#include<iterator>

#define SENTINAL 9999999

using namespace std;

void merge(vector<int>& arr, int a, int b, int c)
{
	// assign left and right arrays
	vector<int> left, right;
	for (int i = a; i <= b; i++)
		left.push_back(arr[i]);
	for (int i = b + 1; i <= c; i++)
		right.push_back(arr[i]);

	// placing sentinal element at the back
	left.push_back(SENTINAL);
	right.push_back(SENTINAL);

	// merging into source array in sorted order
	int li = 0, ri = 0;
	for (int i = a; i <= c; i++)
	{
		if (left[li] < right[ri])
		{
			arr[i] = left[li];
			li++;
		}
		else
		{
			arr[i] = right[ri];
			ri++;
		}
	}
}

void merge_sort(vector<int> &arr, int a, int b)
{
	int m = (a + b) / 2;
	if (a < b)
	{
		merge_sort(arr, a, m);
		merge_sort(arr, m + 1, b);
		merge(arr, a, m, b);
	}
}

int main()
{
	vector<int> arr = { 14, 33, 27, 10, 35, 19, 42, 44 };
	merge_sort(arr, 0, arr.size() - 1);
	cout << "Sorted Array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
