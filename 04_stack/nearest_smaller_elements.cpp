/*
* Problem: Nearest smaller element. We have to find previous smaller element and next smaller element from the given array.
* Solution: We will use stack
* Time Complexity: O(n) and space complexity O(n) 
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> previous_smaller(vector<int>& arr)
{
	vector<int> ans(arr.size());
	ans[0] = -1;
	stack<int> st;
	st.push(arr[0]);
	for (int i = 1; i < arr.size(); i++)
	{
		if (st.top() < arr[i])
			ans[i] = st.top();
		else
		{
			while (!st.empty() && st.top() >= arr[i])
				st.pop();
			if (st.empty())
				ans[i] = -1;
			else
				ans[i] = st.top();
		}
		st.push(arr[i]);
	}
	return ans;
}

vector<int> next_smaller(vector<int>& arr)
{
	stack<int> st;
	int n = arr.size();
	vector<int> ans(n);
	ans[n - 1] = -1;
	st.push(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--)
	{
		if (st.top() < arr[i])
			ans[i] = st.top();
		else
		{
			while (!st.empty() && st.top() >= arr[i])
				st.pop();
			if (st.empty())
				ans[i] = -1;
			else
				ans[i] = st.top();
		}
		st.push(arr[i]);
	}
	return ans;
}

int main()
{
	vector<int> arr = { 4, 5, 2, 6, 3, 7, 9, 1, 8 };
	cout << "\noriginal array: " << endl;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		cout << *it << " ";

	vector<int> prev = previous_smaller(arr);
	cout << "\nPrevious smaller elements: " << endl;
	for (vector<int>::iterator it = prev.begin(); it != prev.end(); it++)
		cout << *it << " ";
	
	vector<int> next = next_smaller(arr);
	cout << "\nNext smaller elements: " << endl;
	for (vector<int>::iterator it = next.begin(); it != next.end(); it++)
		cout << *it << " ";
}
