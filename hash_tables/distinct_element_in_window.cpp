/*
* Count the distinct elements in every window of size k
* Solution: Use a hash set to store the window elements and return the size of hash set for each window.
* Time Complexity: O(n)
* Space Complexity: O(k)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> count_distinct(vector<int>& arr, int k)
{
	int i = 0, j = 0, n = arr.size();
	vector<int> res;
	unordered_map<int, int> hs;

	for (j = 0; j < k - 1; j++)
		hs[arr[j]]++;
	
	while (j < n)
	{
		hs[arr[j]]++;
		res.push_back(hs.size());
		hs[arr[i]]--;
		if (hs[arr[i]] == 0)
			hs.erase(arr[i]);
		i++;
		j++;
	}
	return res;
}

int main()
{
	vector<int> arr = { 1, 2, 2, 1, 3, 1, 1, 3 };
	vector<int> res = count_distinct(arr, 4);
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
		cout << *it << endl;
}