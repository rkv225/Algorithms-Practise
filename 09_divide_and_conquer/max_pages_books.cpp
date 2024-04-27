/*
* Problem: Maximise the maximum number of pages read by a student for number of pages of bool given in array and books to be allocated in contiguous fashion
* Solution: We find max and min pages read by a student for all the books. We find a mid and check if the k students can read within this limit or not.
* We finalyy return the max limit allowed by k students.
* TimeComplexity: O(n log n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
T sum(vector<T>& arr)
{
	T ss = 0;
	for (typename vector<T>::iterator it = arr.begin(); it != arr.end(); it++)
		ss = ss + *it;
	return ss;
}

bool is_safe(vector<int>& arr, int mid, int k)
{
	int ck = 1;
	int curr_sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (curr_sum + arr[i] <= mid)
		{
			curr_sum = curr_sum + arr[i];
		}
		else
		{
			curr_sum = arr[i];
			ck++;
		}
	}
	return ck <= k;
}

int find_max_pages(vector<int>& arr, int k)
{
	int min = *max_element(arr.begin(), arr.end());
	int max = sum<int>(arr);
	int res;

	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (is_safe(arr, mid, k))
		{
			max = mid - 1;
			res = mid;
		}
		else
		{
			min = mid + 1;
		}
	}
	return res;
}

int main()
{
	vector<int> arr = { 5, 10, 5, 6, 15, 2, 12 };
	cout << "max pages read by student: " << find_max_pages(arr, 4);
}