/*
Link: https://leetcode.com/problems/maximum-subarray
*/

class Solution {
public:
    int crossing(int i, int m, int j, vector<int>& nums) {
        int left_max = -1e8, right_max = -1e8, sum = 0;
        for(int a = m; a >= i; a--) {
            sum += nums[a];
            left_max = max(left_max, sum);
        }
        sum = 0;
        for(int b = m + 1; b <= j; b++) {
            sum += nums[b];
            right_max = max(right_max, sum);
        }
        return left_max + right_max;
    }
    int rec(int i, int j, vector<int>& nums) {
        if(i == j)
            return nums[i];
        int m = (i + j) / 2;
        int l = rec(i, m, nums);
        int r = rec(m + 1, j, nums);
        int c = crossing(i, m, j, nums);
        return max(c, max(l, r));
        return c;
    }
    int maxSubArray(vector<int>& nums) {
        return rec(0, nums.size() - 1, nums);
    }
};

/*
* Maximum subarray sum problem using divide ad conquer strategy. 
* We can assume that we can have maximum subarray in left half of array or in right half
* Or we an have maximum subarray in crossing of left and right half
* base condition where we have only one element so that will the maimum subarray sum.
*/

#include <iostream>

using namespace std;

struct sum_value
{
	int left_index;
	int right_index;
	int sum;
};

sum_value crossing_subarray_sum(int arr[], int left, int mid, int right)
{
	int sum = 0;
	int left_max = 0;
	int left_index = 0;
	for (int i = mid; i >= left; i--)
	{
		sum = sum + arr[i];
		if (sum > left_max)
		{
			left_max = sum;
			left_index = i;
		}
	}

	sum = 0;
	int right_max = 0;
	int right_index = 0;
	for (int i = mid + 1; i <= right; i++)
	{
		sum = sum + arr[i];
		if (sum > right_max)
		{
			right_max = sum;
			right_index = i;
		}
	}
	return sum_value{ left_index, right_index, left_max + right_max };
}

sum_value calculate_subarray_sum(int arr[], int left, int right)
{
	if (left == right) // base condition
	{
		return sum_value{ left, right, arr[left] };
	}
	else
	{
		int mid = (left + right) / 2;
		sum_value left_sum = calculate_subarray_sum(arr, left, mid);
		sum_value right_sum = calculate_subarray_sum(arr, mid + 1, right);
		sum_value crossing_sum = crossing_subarray_sum(arr, left, mid, right);
		if (left_sum.sum >= right_sum.sum && left_sum.sum >= crossing_sum.sum)
			return left_sum;
		else if (right_sum.sum >= left_sum.sum && right_sum.sum >= crossing_sum.sum)
			return right_sum;
		else
			return crossing_sum;
	}
}

int main()
{
	int arr[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	sum_value max_subarray_sum = calculate_subarray_sum(arr, 0, sizeof(arr) / sizeof(arr[0]));
	cout << "maximum subarray sum is: " << max_subarray_sum.sum
		<< ", left : " << max_subarray_sum.left_index
		<< ", right: " << max_subarray_sum.right_index
		<< endl;
	return 0;
}