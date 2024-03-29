/*
Problem:

Link:
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