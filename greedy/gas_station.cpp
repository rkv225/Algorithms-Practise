/*
Problem:
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. 
If there exists a solution, it is guaranteed to be unique.

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.

Solution:
1. Sum all the cost and gas.
2. If sum(gas) < sum(cost) then we can't travel.
3. Now we have a guarantee that the sum exists.
4. Imagine an array diff[] having diff[i] = gas[i] - cost[i].
Our task is now reduced to finding a non negative half in diff array that we can traverse. 
This is because we know that sum(diff) >= 0.
If one half is positive then other can't be more negative.
5. Start from 0 index and get the diff and have a total.
6. If the total gets below 0 then reset and start from next index.
7. Till the end you will hve atleast a point to start which will end positive. 
And from previous check we know that sum(diff) >= 0. So we can say if we start with the computed index, we will be able to finish.

Time Complexity: O(n)
Space Complexity: O(1)

Link: https://leetcode.com/problems/gas-station
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gs = accumulate(gas.begin(), gas.end(), 0);
        int cs = accumulate(cost.begin(), cost.end(), 0);
        if(gs < cs)
            return -1;
        int total = 0, start = 0;
        for(int cur = 0; cur < n; cur++) {
            total = total + gas[cur] - cost[cur];
            if(total < 0) {
                total = 0;
                start = cur + 1;
            }
        }
        return start;
    }
};