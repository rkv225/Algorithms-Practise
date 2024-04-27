/*
* Intersection of two arrays using sets
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void intersection_set(vector<int>& arr1, vector<int>& arr2, unordered_set<int>& int_obj)
{
	unordered_set<int> set1;
	for (vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++)
		set1.insert(*it);
	for (vector<int>::iterator it = arr2.begin(); it != arr2.end(); it++)
		if (set1.find(*it) != set1.end())
			int_obj.insert(*it);
}

int main()
{
	vector<int> arr1 = { 1, 2, 3, 4, 5 };
	vector<int> arr2 = { 3, 4, 5, 6, 7, 8, 9 };
	unordered_set<int> int_obj;
	intersection_set(arr1, arr2, int_obj);
	for (unordered_set<int>::iterator it = int_obj.begin(); it != int_obj.end(); it++)
		cout << *it << " ";
}