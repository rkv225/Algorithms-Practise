/*
* Median finding algorithm:
* Naive method would be to sort the array and then find the middle element; but we don't need to sort the entire array to get the median.
* Assume the median element to be i, we can partition the array to find the pivot
* - if pivot = i return 
* - if pivot < i then find in right
* - if pivot > i then find in left
* But there's a catch, we can still have bottleneck of partitioning that can lead to n^2 complexity, so we to randomise the way we select partition
* We divide the aray into chunks of 5 and find the median of those elements and then finally finding median of medians to get the partition.
* for simplicity we have taken a random partition value
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int random_partition(vector<int>& arr, int l, int r)
{
	// finding random index and swapping it with starting index
	int index = rand() % (r - l);
	swap(arr[l + index], arr[l]);

	// hoare partitioning by traversing from both ends
	int pivot = arr[l];
	int i = l + 1, j = r;
	while (i < j)
	{
		if (arr[i] < pivot)
			i++;
		if (arr[j] >= pivot)
			j--;
		if (i < j && arr[i] > pivot && arr[j] < pivot)
			swap(arr[i], arr[j]);
	}
	swap(arr[j], arr[l]);
	return j;
}

int median_finding(vector<int>& arr, int l, int r)
{
	if (l == r)
		return arr[l];
	int i = (l + r) / 2;
	int pivot = random_partition(arr, l, r);
	if (pivot == i)
		return arr[i];
	else if (pivot < i)
		return median_finding(arr, pivot, r);
	else // if (pivot > i)
		return median_finding(arr, l, pivot); 
}

int main()
{
	vector<int> arr = { 43, 23, 67, 90, 21, 33, 6, 1, 27 };
	int median = median_finding(arr, 0, arr.size() - 1);
	cout << "Median: " << median << endl;
	return 0;
}