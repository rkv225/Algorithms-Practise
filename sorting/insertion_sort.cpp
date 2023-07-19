#include<iostream>
#include<vector>

using namespace std;

/*
* stable sort, in-place sorting algorithm, time-complexity -> O(n^2)
*/
void insertion_sort(vector<int> &arr) // ascending sort
{
	int siz = arr.size();
	for (int j = 1; j < siz; j++) // first element is trivially sorted
	{
		int key = arr[j];
		// insert arr[j] into the sorted sequence arr[0...j-1]
		int i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}

int main()
{
	vector<int> arr = { 14, 33, 27, 10, 35, 19, 42, 44 };
	insertion_sort(arr);
	cout << "Sorted Array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << endl;
	}
}
