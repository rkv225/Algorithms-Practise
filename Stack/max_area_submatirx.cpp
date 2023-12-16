/*
* Problem: Maximum area in a submatrix with all 1's
* Time Complexity: O(N*M) time complexity and O(M) space complexity
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int max_area(vector<int>& arr)
{
	stack<int> st;
	int n = arr.size();
	vector<int> next(n);
	vector<int> prev(n);
	int max_rectangle = 0;

	// populate previous smaller numbers
	prev[0] = -1;
	st.push(0);
	for (int i = 1; i < n; i++)
	{
		if (arr[st.top()] < arr[i])
			prev[i] = st.top();
		else
		{
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop();
			if (st.empty())
				prev[i] = -1;
			else
				prev[i] = st.top();
		}
		st.push(i);
	}

	// clear the stack
	while (!st.empty())
		st.pop();

	// populate the next smaller numbers
	next[n - 1] = n;
	st.push(n - 1);
	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[st.top()] < arr[i])
			next[i] = st.top();
		else
		{
			while (!st.empty() && arr[st.top()] >= arr[i])
				st.pop();
			if (st.empty())
				next[i] = n;
			else
				next[i] = st.top();
		}
		st.push(i);
	}

	// calulating the distance between the max from left and max from right 
	// note - we have calculated the nearest min values but the value before it will be greater than current value
	// this means that we can go till these points and we will have atleast current height
	// so the effective rectangle will be the distance * current height
	for (int i = 0; i < n; i++)
		max_rectangle = max(max_rectangle, (next[i] - prev[i] - 1) * arr[i]);

	return max_rectangle;
}

int max_submatrix_area(vector<vector<int>>& arr)
{
	int n = arr.size();
	int m = arr[0].size();
	int max_area_mat = 0;
	vector<int> strip;
	strip.assign(m, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			strip[j] = (strip[j] + arr[i][j]) * arr[i][j];
		max_area_mat = max(max_area_mat, max_area(strip));
	}
	return max_area_mat;
}

int main()
{
	vector<vector<int>> arr =
	{
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1}
	};
	cout << max_submatrix_area(arr);
}
