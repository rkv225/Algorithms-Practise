/*
Problem:
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned

Example 1:
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Example 2:
Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

Solution: We need to create an adjacency list by finding difference of adjacent words.
A word coming first is lexographically less than the one coming after.
So if word xyz comes before abc it means that x -> a
adh & amp => d -> m
This is how we keep on creating adjacency list and finally return the topological order of the graph.

Time Complexity: O(V + E)

Space Complexity: O(V + E)

Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1
*/

class Solution{
    public:
    pair<char, char> compare(string& a, string& b) {
        // this function assumes that a and b will be of same size or will definitely differ at any index 
        int x = 0;
        int y = 0;
        pair<char, char> p;
        while (x < a.size() && y < b.size() && a[x] == b[y]) {
            x++; y++;
        }
        if (x < a.size() && y < b.size()) {
            p.first = a[x];
            p.second = b[y];
        }
        return p;
    }
    bool dfs_visit(char v, unordered_map<char, vector<char>>& adj, unordered_map<char, int>& visit, string& ans) {
        visit[v] = 1;
        for (int i = 0; i < adj[v].size(); i++) {
            if (visit[adj[v][i]] == 1) // gray node encountered
                return true;
            if (visit[adj[v][i]] == 0)
            {
                bool isCycle = dfs_visit(adj[v][i], adj, visit, ans);
                if (isCycle)
                    return true;
            }
        }
        visit[v] = 2;
        ans.push_back(v);
        return false;
    }
    string findOrder(string dict[], int N, int K) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> visit;
        string ans = "";

        char ch = 'a';
        for (int i = 0; i < K; i++) {
            adj[ch];
            visit[ch] = 0;
            ch++;
        }

        for (int i = 0; i < N - 1; i++) {
            pair<char, char> cr = compare(dict[i], dict[i + 1]);
            adj[cr.first].push_back(cr.second);
        }

        for (unordered_map<char, int>::iterator it = visit.begin(); it != visit.end(); it++) {
            char v = (*it).first;
            if (visit[v] == 0) {
                bool isCycle = dfs_visit(v, adj, visit, ans);
                if (isCycle)
                    return "";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};