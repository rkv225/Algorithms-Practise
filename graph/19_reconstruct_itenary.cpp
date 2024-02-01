/*
Problem: You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.
All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Link: https://leetcode.com/problems/reconstruct-itinerary
*/

// Solution: backtracking and DFS
// Time complexity: O(E^2)
// space complexity: O(E)

class Solution {
public:
    bool dfs(unordered_map<string, multiset<string>>& m, string p, vector<string>& result, int target) {
        if(result.size() == target)
            return true;
        if(m[p].size() == 0)
            return false;
        vector<string> tmp(m[p].begin(), m[p].end());
        for(vector<string>::iterator v = tmp.begin(); v != tmp.end(); v++) {
            m[p].erase(m[p].find(*v));
            result.push_back(*v);
            if(dfs(m, *v, result, target))
                return true;
            // backtrack
            result.pop_back();
            m[p].insert(*v);
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for(int i = 0; i < tickets.size(); i++)
            m[tickets[i][0]].insert(tickets[i][1]);
        vector<string> result = { "JFK" };
        dfs(m, "JFK", result, tickets.size() + 1);
        return result;
    }
};

/*
    Greedy DFS, build route backwards when retreating, merge cycles into main path
    Time: O(E log (E / V)) -> E = # of flights, V = # of airports, sorting
    Space: O(V + E) -> store # of airports & # of flights in hash map
*/

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(unordered_map<string, multiset<string>>& m,
        string airport, vector<string>& result) {
        
        while (!m[airport].empty()) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(m, next, result);
        }
        
        result.push_back(airport);
    }
};
