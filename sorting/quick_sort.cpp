#include<iostream>
#include<vector>
#include<iterator>

#define SENTINAL 9999999

using namespace std;

int lomuto_partition(vector<int>& arr, int p, int q)
{
	// this partition technique divides the array into 4 parts
	// we have an array arr[p...q], x is the partition value selected at the end of array
	// p| arr[p...i] < x | arr[i...j] > x | <undiscovered array> | x |q
	// go from left until the undiscovered part is no more

	int i = p - 1;
	for (int j = p; j < q; j++)
	{
		if (arr[j] < arr[q])
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[q]);
	return i + 1;
}

int hoare_partition(vector<int> &arr, int p, int q)
{
	// we select a pivot value at beginning of the array
	// then we traverse arry from both the ends
	// swap if elements are not in their right place
	// do this until pointers from both ends cross eachother

	int x = arr[p];
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if (arr[i] < x)
			i++;
		if (arr[j] >= x)
			j--;
		if (i < j && arr[i] > x && arr[j] < x)
			swap(arr[i], arr[j]);
	}
	swap(arr[j], arr[p]);
	return j;
}

void quick_sort(vector<int> &arr, int p, int q)
{
	if (p < q)
	{
		int partition = hoare_partition(arr, p, q);
		quick_sort(arr, p, partition - 1);
		quick_sort(arr, partition + 1, q);
	}
}

int main()
{
	vector<int> arr = { 14, 33, 27, 10, 35, 19, 42, 44 };
	quick_sort(arr, 0, arr.size() - 1);
	cout << "Sorted Array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
