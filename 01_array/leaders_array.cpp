/*
Problem:
There is an integer array ‘a’ of size ‘n’.
An element is called a Superior Element if it is greater than all the elements present to its right.
You must return an array all Superior Elements in the array ‘a’.
Note: The last element of the array is always a Superior Element. 

Example
Input: a = [1, 2, 3, 2], n = 4
Output: 2 3
Explanation: 
a[ 2 ] = 3 is greater than a[ 3 ]. Hence it is a Superior Element. 
a[ 3 ] = 2 is the last element. Hence it is a Superior Element.
The final answer is in sorted order.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4 
1 2 2 1
Sample Output 1:
1 2
Explanation of Sample Input 1:
Element present at the last index is '1' and is a superior element since there are no integers to the right of it.
Element present at index 2 (0-indexed) is '2' and is greater than all the elements to the right of it.
There are no other superior elements present in the array.
Hence the final answer is [1,2].

Sample Input 2:
3
5 4 3
Sample Output 2:
3 4 5 

Solution:
traverse from right and keep a max. If curr is greater than max then it is a leader and update the max

Link: https://www.naukri.com/code360/problems/superior-elements_6783446
*/

vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n = a.size();
    int right_max = a[n - 1];
    ans.push_back(a[n - 1]);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > right_max) {
            ans.push_back(a[i]);
            right_max = a[i];
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}