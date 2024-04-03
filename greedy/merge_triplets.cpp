/*
Problem:
A triplet is an array of three integers. You are given a 2D integer array triplets, where triplets[i] = [ai, bi, ci] describes the ith triplet. You are also given an integer array target = [x, y, z] that describes the triplet you want to obtain.
To obtain target, you may apply the following operation on triplets any number of times (possibly zero):
Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become [max(ai, aj), max(bi, bj), max(ci, cj)].
For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be updated to [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, or false otherwise.

Example 1:
Input: triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and last triplets [[2,5,3],[1,8,4],[1,7,5]]. Update the last triplet to be [max(2,1), max(5,7), max(3,5)] = [2,7,5]. triplets = [[2,5,3],[1,8,4],[2,7,5]]
The target triplet [2,7,5] is now an element of triplets.

Example 2:
Input: triplets = [[3,4,5],[4,5,6]], target = [3,2,5]
Output: false
Explanation: It is impossible to have [3,2,5] as an element because there is no 2 in any of the triplets.

Example 3:
Input: triplets = [[2,5,3],[2,3,4],[1,2,5],[5,2,3]], target = [5,5,5]
Output: true
Explanation: Perform the following operations:
- Choose the first and third triplets [[2,5,3],[2,3,4],[1,2,5],[5,2,3]]. Update the third triplet to be [max(2,1), max(5,2), max(3,5)] = [2,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,2,3]].
- Choose the third and fourth triplets [[2,5,3],[2,3,4],[2,5,5],[5,2,3]]. Update the fourth triplet to be [max(2,5), max(5,2), max(5,3)] = [5,5,5]. triplets = [[2,5,3],[2,3,4],[2,5,5],[5,5,5]].
The target triplet [5,5,5] is now an element of triplets.

Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet
*/

/*
Solution:
Bruteforce solution TLE 
Similar approach as of subset sum problem
*/
class Solution {
public:
    bool comTrip(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
    }
    bool opTrip(vector<int>& a, vector<int>& b, vector<int>& target) {
        a[0] = max(a[0], b[0]);
        a[1] = max(a[1], b[1]);
        a[2] = max(a[2], b[2]);
        // triplet is valid if every alue is small and we have atleast one value in target triplet
        return !(a[0] > target[0] || a[1] > target[1] || a[2] > target[2]) && 
            (a[0] == target[0] || a[1] == target[1] || a[2] == target[2]);
    }
    bool f(int index, vector<int> cur, vector<int>& target, vector<vector<int>>& triplets) {
        // equal to target
        if(comTrip(cur, target))
            return true;
        // all the combinations processed
        if(index >= triplets.size())
            return false;
        // not take
        if(f(index + 1, cur, target, triplets))
            return true;
        // take
        bool valid = opTrip(cur, triplets[index], target);
        if(valid && f(index + 1, cur, target, triplets))
            return true;
        return false;
    }
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> cur(3, 0);
        return f(0, cur, target, triplets);
    }
};


/*
Solution: Greedy
1. A triplet is valid if any of the value is not greater than target and triplet contains any value from target
2. Make a final triplet from valid triplets
3. check if the triplet equals to final triplet and return the result

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> finalTriplet(3, -1e8);
        for(int i = 0; i < triplets.size(); i++)
            if(!(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) &&
                (triplets[i][0] == target[0] || triplets[i][1] == target[1] || triplets[i][2] == target[2])) {
                finalTriplet[0] = max(finalTriplet[0], triplets[i][0]);
                finalTriplet[1] = max(finalTriplet[1], triplets[i][1]);
                finalTriplet[2] = max(finalTriplet[2], triplets[i][2]);
            }
        return finalTriplet[0] == target[0] && finalTriplet[1] == target[1] && finalTriplet[2] == target[2];
    }
};