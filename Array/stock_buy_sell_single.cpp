
/*
* Stock buy sell only once and find the maximum profit that can be achieved
* O(n) solution if to keep track of the minimum before the index and traverse whole array to get maximum profit
*/

#include <iostream>
#include <vector>

using namespace std;

int max_profit(vector<int>& arr, int n)
{
	int minSoFar = INT_MAX;
	int profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (minSoFar > arr[i])
			minSoFar = arr[i];
		if (profit < arr[i] - minSoFar)
			profit = arr[i] - minSoFar;
	}
	return profit;
}

int main()
{
	vector<int> arr = { 3, 1, 4, 8, 7, 2, 5 };
	cout << "Maximum profit is: " << max_profit(arr, arr.size());
}