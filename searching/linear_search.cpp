#include<iostream>

using namespace std;

int linear_search(int arr[], int size, int key)
{
	for (int i = 0;i < size;i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int A[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int S = sizeof(A) / sizeof(A[0]);
	cout << linear_search(A, S, 5) << endl;
	cout << linear_search(A, S, 11) << endl;
}
