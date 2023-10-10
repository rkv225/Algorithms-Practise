/* 
* Kadane's algorithm for maximum subarray sum in O(n)
*/

#include <iostream>
#include <vector>

using namespace std;

struct subarray
{
	int sum;
	int start;
	int end;
};

subarray Kadane(vector<int>& arr, int n)
{
	int curr_sum = -999999;
	int max_sum = -999999;
	int a = 0, b = n - 1;
	for (int i = 0; i < n; i++)
	{
		if (curr_sum + arr[i] < arr[i])
		{
			curr_sum = arr[i];
			a = i;
		}
		else
		{
			curr_sum = curr_sum + arr[i];
		}
		if (curr_sum > max_sum)
		{
			max_sum = curr_sum;
			b = i;
		}
	}
	return subarray{ max_sum, a, b };
}

int main()
{
	vector<int> arr = { -5, 4, 6, -3, 4, -1 };
	subarray sa = Kadane(arr, arr.size());
	cout << "max sum is " << sa.sum << " from " << sa.start << " to " << sa.end << endl;
	return 0;
}