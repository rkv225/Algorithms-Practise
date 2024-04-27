/*
Problem:
Given an array ‘a’ of size ‘n’-1 with elements of range 1 to ‘n’. The array does not contain any duplicates. Your task is to find the missing number.

For example:
Input:
'a' = [1, 2, 4, 5], 'n' = 5
Output :
3
Explanation: 3 is the missing value in the range 1 to 5.

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://www.codingninjas.com/studio/problems/missing-number_6680467
*/

// Solution: using sum of ap i.e. sum of first n natural numbers
int missingNumber(vector<int>&a, int N) {
    long long sum = 0;
    for(int i = 0; i < N - 1; i++)
        sum += a[i];
    long long sn = N*(N+1)/2;
    return sn - sum;
}

// Solution: by xoring all the nums in array and range. Only the missing number will be left in xor sum.
int missingNumber(vector<int>&a, int N) {
    int xx = 0;
    for(auto x : a)
        xx ^= x;
    for(int x = 1; x <= N; x++)
        xx ^= x;
    return xx;
}