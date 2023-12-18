/*
* sliding window maximum
* time complexity: O(n), space complexity: O(k)
*/

#include <iostream>
#include <queue>

using namespace std;

vector<int> sliding_max(vector<int>& arr, int window_size)
{
	deque<int> q;
	vector<int> max_arr;

	// fill inital window of given size
	for (int i = 0; i < window_size; i++)
	{
		if (!q.empty() && q.back() < arr[i])
			q.pop_back();
		q.push_back(arr[i]);
	}

	max_arr.push_back(q.front());

	// take out first element if present in window and push new element to window after popping smaller elements
	for (int i = 0; i < arr.size() - window_size; i++)
	{
		if (!q.empty() && q.front() == arr[i])
			q.pop_front();
		while (!q.empty() && q.back() < arr[i + window_size])
			q.pop_back();
		q.push_back(arr[i + window_size]);
		max_arr.push_back(q.front());
	}
	return max_arr;
}

int main()
{
	vector<int> arr = { 4, 1, 3, 5, 1, 2, 3, 2, 1, 1, 5 };
	vector<int> max_arr = sliding_max(arr, 3);
	for (vector<int>::iterator i = max_arr.begin(); i != max_arr.end(); i++)
		cout << *i << " ";
}

