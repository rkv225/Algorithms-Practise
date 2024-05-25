/*
Problem:
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Print the maximum possible minimum distance.

Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
Output: 2
Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
6 4
0 3 4 7 10 9
Sample Output 1 :
3
Explanation to Sample Input 1 :
The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

Sample Input 2 :
5 2
4 2 1 3 6
Sample Output 2 :
5

Time Complexity: O(n log n)

Link: https://www.naukri.com/code360/problems/aggressive-cows_1082559
*/

bool is_safe(vector<int> &stalls, int k, int sp) {
    int cows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= sp) {
            // if current stall is atleast at given distance from last stall then we can place cow
            last = stalls[i];
            cows++;
        }
        if(cows >= k)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (is_safe(stalls, k, mid)) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}