/*
Problem: 
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

Solution: 
This problem can be solved using Bellman Ford algorithm by performing k+1 relaxations, that's it, if after k+1 relaxations price is not INT_MAX, then return price otherwise return -1.
Let's start: (Taking temp array)
0 -> 1, original price = price[1] = Infinity, new price = 0+100 -> tempPrice[1] = 100. //tempPrice is updated, not price.
1 -> 2, original price = price[2] = Infinity, new price = price[1] (Infinity) + 100 -> tempPrice[2] = Infinity.
0 -> 2, original price = price[2] = Infinity,new price = price[0] + 500 -> which is smaller than infinity -> Update tempPrice[2] = 500.
Hence price[2] = 500 taking 0 stops in between.

Time Complexity: O(EK) as we are ony making k passes

Space Complexity: O(n) as we are only storing distance for each vertex

Link: https://leetcode.com/problems/cheapest-flights-within-k-stops
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e8);
        dist[src] = 0; // set source distance to 0
        for(int step = 0; step <= k; step++) {
            vector<int> tmp(dist);
            for(int e = 0; e < flights.size(); e++) {
                int u = flights[e][0];
                int v = flights[e][1];
                int w = flights[e][2];
                tmp[v] = min(tmp[v], dist[u] + w);
            }
            dist = tmp;
        }
        if(dist[dst] < 1e8)
            return dist[dst];
        return -1;
    }
};