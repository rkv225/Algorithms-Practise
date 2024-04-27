/*
* Counting inversion problem: Count the number of inversions in an array i.e.
* count of every pair in arr[] where a[i] > a[j] for i < j
* We use merge sort algorithm to achieve this. while in merge step we know that we have both arrays sorted
* if any element from left array is greater than any element in right array then,
* all the rest of the elements in left array will be greater than that particular element
* We keep on checking further and adding up the count
*/

#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr, int left, int mid, int right)
{
	vector<int> left_arr, right_arr;

	for (int i = left; i <= mid; i++)
		left_arr.push_back(arr[i]);
	for (int i = mid + 1; i <= right; i++)
		right_arr.push_back(arr[i]);

	int i = 0, j = 0;
	int k = left;
	int inversion_count = 0;

	while (i < left_arr.size() && j < right_arr.size())
	{
		if (left_arr[i] <= right_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else // inversion detected, so all the elements in left from now on will be greater than right[j]
		{
			arr[k] = right_arr[j];
			j++;

			inversion_count += left_arr.size() - i;
		}
		k++;
	}

	// any of the array got exhausted
	while (i < left_arr.size())
		arr[k++] = left_arr[i++];

	while (j < right_arr.size())
		arr[k++] = right_arr[j++];

	return inversion_count;
}

int merge_sort(vector<int> &arr, int left, int right)
{
	if (right == left)
	{
		return 0; // single element
	}
	else
	{
		int mid = (left + right) / 2;
		int left_inversions = merge_sort(arr, left, mid);
		int right_inversions = merge_sort(arr, mid + 1, right);
		int cross_inversions = merge(arr, left, mid, right);
		return left_inversions + right_inversions + cross_inversions;
	}
}

int main()
{
	vector<int> arr = { 1, 20, 6, 4, 5 };
	int result = merge_sort(arr, 0, arr.size() - 1);
	cout << "Number of inversions are " << result << endl;
	return 0;
}
