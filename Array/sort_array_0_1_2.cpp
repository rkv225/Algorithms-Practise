/*
Problem:
You have been given an array/list 'arr' consisting of 'n' elements.
Each element in the array is either 0, 1 or 2.
Sort this array/list in increasing order.
Do not make a new array/list. Make changes in the given array/list.

Example :
Input: 'arr' = [2, 2, 2, 2, 0, 0, 1, 0]
Output: Final 'arr' = [0, 0, 0, 1, 2, 2, 2, 2]
Explanation: The array is sorted in increasing order.

Solution: 
Partition the array into 3 parts
| 0's | 1's | undiscovered | 2's |
      i     j              k
We explore from j to k and accordingly swap till it is exhausted.

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://www.codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977
*/

void sortArray(vector<int>& arr, int n)
{
    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
      if (arr[j] == 0) {
        swap(arr[i], arr[j]);
        i++;
        j++;
      } else if (arr[j] == 2) {
        swap(arr[k], arr[j]);
        k--;
      } else {
        j++;
      }
    }
}