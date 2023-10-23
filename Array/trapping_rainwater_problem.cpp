/*
* Trapping rainwater problem: find the the water trapped between adjacent buildings of given heights in O(n) time complexity and O(n) space complexity
*/

#include <iostream>
#include <vector>

using namespace std;

long long trappingWater(vector<int> arr, int n) 
{
    vector<int> left(n);
    vector<int> right(n);
    long long total = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(arr[i], left[i - 1]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(arr[i], right[i + 1]);

    for (int i = 0; i < n; i++)
        total = total + min(left[i], right[i]) - arr[i];

    return total;
}

int main()
{
    vector<int> arr = { 3, 0, 0, 2, 0, 4 };
    cout << "Total water trapped: " << trappingWater(arr, arr.size()) << endl;
}