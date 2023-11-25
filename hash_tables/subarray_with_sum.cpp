/*
* Find the subarray with the given sum
* Solution: Create a hashmap of the sums and store it with index. 
* Then reiterate the array to find diff i.e. curr_sum - sum.
* If this diff is found in hashmap and index is less than current index then we can say that we have found 
* a subarray and adjacent to that subarray is our required subarray within current range. 
* Complexity: O(n)
* Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 pair<int, int> find_subarray(vector<int>& arr, int sum)
{
	unordered_map<int, int> hm;
	int n = arr.size();
	int curr_sum = 0;

	// storing the sum till index i
	for (int i = 0; i < n; i++)
	{
		curr_sum = curr_sum + arr[i];
		if (hm.find(curr_sum) == hm.end())
			hm[curr_sum] = i;
	}

	curr_sum = 0;
	// finding the subarray
	for (int i = 0; i < n; i++)
	{
		curr_sum = curr_sum + arr[i];
		int diff = curr_sum - sum;
		if (hm.find(diff) != hm.end() && hm[diff] < i)
			return pair<int, int>(hm[diff] + 1, i);
	}
	return pair<int, int>(-1, -1);
}

 int main()
 {
	 vector<int> arr = { 10, 2, -2, -20, 10 };
	 pair<int, int> ans = find_subarray(arr, -10);
	 cout << "start: " << ans.first << ", end: " << ans.second;
 }