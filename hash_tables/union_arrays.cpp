/*
* Union of two arrays using sets
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void union_set(vector<int>& arr1, vector<int>& arr2, unordered_set<int>& union_obj)
{
	for (vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++)
		union_obj.insert(*it);
	for (vector<int>::iterator it = arr2.begin(); it != arr2.end(); it++)
		union_obj.insert(*it);
}

int main()
{
	vector<int> arr1 = { 1, 2, 3, 4, 5 };
	vector<int> arr2 = { 3, 4, 5, 6, 7, 8, 9 };
	unordered_set<int> union_obj;
	union_set(arr1, arr2, union_obj);
	for (unordered_set<int>::iterator it = union_obj.begin(); it != union_obj.end(); it++)
		cout << *it << " ";
}