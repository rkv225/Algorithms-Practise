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

/*
Solution: Two pointer approach
Instead of storing the max right and max left, we know that we need minimum of them so we calculate min.
we keep two pointers one at beginning and one at end
we shift the pointers based on values and calculate

Link: 
https://leetcode.com/problems/trapping-rain-water
*/
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0;
        int r = n - 1;
        int max_left = h[0];
        int max_right = h[n - 1];
        int ans = 0;
        while(l < r) {
            if(max_left <= max_right) {
                // shift left
                l++;
                // update max_left
                max_left = max(max_left, h[l]);
                ans += max_left - h[l];
            } else {
                r--;
                max_right = max(max_right, h[r]);
                ans += max_right - h[r];
            }
        }
        return ans;
    }
};