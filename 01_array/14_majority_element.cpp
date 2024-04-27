/*
* Find majority number in an array in O(n) time complexity and O(1) space complexity
* Solution: We know that if an element is in majority then it will be occurring in an array more than n/2 times.
* if we traverse an array and keep the track of only the current element and it's count comes out to be positive at the end.
* Finally we will verify the count of only that element.
* at any point count becomes 0, we switch to new number.
*/

#include <iostream>

using namespace std;

int majorityElement(int a[], int size)
{
    int e = -1;
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (e == a[i])
            c++;
        else
        {
            c--;
            if (c <= 0)
            {
                e = a[i];
                c = 1;
            }
        }
    }
    c = 0;
    for (int i = 0; i < size; i++)
        if (e == a[i])
            c++;
    if (c > (size / 2))
        return e;
    return -1;
}

int main()
{
    int arr[] = { 5, 1, 4, 1, 1 };
    int n = sizeof(arr) / sizeof(int);
    cout << "Mjority Element: " << majorityElement(arr, n) << endl;
	return 0;
}