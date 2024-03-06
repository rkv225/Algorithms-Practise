/*
Problem:

Given two sorted arrays, ‘a’ and ‘b’, of size ‘n’ and ‘m’, respectively, return the union of the arrays.
The union of two sorted arrays can be defined as an array consisting of the common and the distinct elements of the two arrays. 
The final array should be sorted in ascending order.
Note: 'a' and 'b' may contain duplicate elements, but the union array must contain unique elements.

Example:
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]
Output: [1, 2, 3, 4, 5, 6]

Explanation: Common elements in ‘a’ and ‘b’ are: [2, 3]
Distinct elements in ‘a’ are: [1, 4, 6]
Distinct elements in ‘b’ are: [5]
Union of ‘a’ and ‘b’ is: [1, 2, 3, 4, 5, 6]

Solution:

Place a pointer on each array at beginning and insert the smaller element at front of the array.
While inserting in ans array, ensure that the element is already in the list i.e. the last element as both arrays are sorted so the resultant array will also be sorted.

Time Complexity: O(m+n)

Space Complexity: O(1) for solution, O(m+n) for storing the union array.

Link: https://www.codingninjas.com/studio/problems/sorted-array_6613259
*/

void insert(int x, vector<int> &arr) {
    int i = arr.size();
    if (i <= 0 || arr[i - 1] != x) {
        arr.push_back(x);
    }
}
vector<int> sortedArray(vector<int> a, vector<int> b) {
    int p1 = 0;
    int p2 = 0;
    vector<int> ans;
    while (p1 < a.size() && p2 < b.size()) {
        if (a[p1] < b[p2]) {
            insert(a[p1], ans);
            p1++;
        } else {
            insert(b[p2], ans);
            p2++;
        }
    }
    if(p1 == a.size()) {
        // a is exhausted
        while (p2 < b.size()) {
            insert(b[p2], ans);
            p2++;
        }
    } else {    
        // b is exhausted
        while (p1 < a.size()) {
            insert(a[p1], ans);
            p1++;
        }
    }
    return ans;
}