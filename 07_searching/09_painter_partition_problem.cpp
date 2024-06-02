/*
Problem:
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2
Output: 11
Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

Time: O(n log n)

Space: O(1)

Link: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
*/

bool isSafe(vector<int> &boards, int k, int target) {
    int painter = 0;
    int curr = 0;
    for (int i = 0; i < boards.size(); i++) {
        curr += boards[i];
        if (curr == target) {
            curr = 0;
            painter++;
        } else if (curr > target) {
            curr = boards[i];
            painter++;
        }
    }
    if (curr > 0) {
        painter++;
    }
    return painter <= k;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int mini = *max_element(boards.begin(), boards.end());
    int maxi = accumulate(boards.begin(), boards.end(), 0);
    int mid = 0;
    int prev_mid = 0;
    while (mini <= maxi) {
        mid = (mini + maxi) / 2;
        if (isSafe(boards, k, mid)) {
            prev_mid = mid;
            maxi = mid - 1;
        } else {
            mini = mid + 1;
        }
    }
    return prev_mid;
}