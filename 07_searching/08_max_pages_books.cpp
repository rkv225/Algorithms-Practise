/*
* Problem: 
Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
There are ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.

Example:
Input: ‘n’ = 4 ‘m’ = 2 
‘arr’ = [12, 34, 67, 90]
Output: 113

Explanation: All possible ways to allocate the ‘4’ books to '2' students are:
12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
We are getting the minimum in the last case.
Hence answer is ‘113’.

* Solution:
 We find max and min pages read by a student for all the books. We find a mid and check if the k students can read within this limit or not.
* We finalyy return the max limit allowed by k students.

* TimeComplexity: O(n log n)

Link: https://www.naukri.com/code360/problems/allocate-books_1090540
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
	// mid - number of max pages a student can read
	// k - number of students

	// student count
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
	// if a student reads only one book then min will be the one with maximum pages
	int min = *max_element(arr.begin(), arr.end());
	// a student can read all the books
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