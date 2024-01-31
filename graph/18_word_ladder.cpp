/*
Problem:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

Solution: 
1. Create a map with all the words. We have to apply BFS and find the shortest distance to destination from source.
2. Add start to queue with distance 0
3. For all combination of chars on each index. If the word is present and not been visited, add to queue and update it's distance.
4. Check for final distance if not infinite then return the distance

Link: https://leetcode.com/problems/word-ladder/description/

Time Complexity: O(N*W) where W is word size

Space Complexity: O(N*W) for map, vertices and queue

*/

struct node {
    int index;
    string val;
    int color;
    int parent;
    int distance;
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, int> word_set;
        vector<node> vertices;
        for(int i = 0; i < n; i++){
            word_set[wordList[i]] = i;
            vertices.push_back({ i, wordList[i], 0, -1, 10000 });
        }
        if(word_set.find(beginWord) == word_set.end()) { // begin word not in list
            word_set[beginWord] = n;
            vertices.push_back({ n, beginWord, 0, -1, 10000 });
        }   
        int startIndex = word_set[beginWord];
        if(word_set.find(endWord) == word_set.end()) { // end word not in list
            return 0;
        }
        int endIndex = word_set[endWord]; 
        queue<int> q;
        // place begin word to queue
        vertices[startIndex].color = 1;
        vertices[startIndex].distance = 0;
        vertices[startIndex].parent = -1;
        q.push(startIndex);
        while(!q.empty()){
            int cur = q.front();
            string curstr = vertices[cur].val;
            q.pop();
            vector<int> neighbor;
            int sl = curstr.size();
            for(int i = 0; i < sl; i++) {
                char oc = curstr[i]; // backup orig char at index
                for(char c = 'a'; c <= 'z'; c++) {
                    curstr[i] = c;
                    if(word_set.find(curstr) != word_set.end() && vertices[word_set[curstr]].color == 0) {
                        neighbor.push_back(word_set[curstr]);
                    }
                }
                curstr[i] = oc; // replace orig char at index
            }
            // push each unvisited neighbor to queue after marking it visited
            for(int i = 0; i < neighbor.size(); i++) {
                vertices[neighbor[i]].color = 1;
                vertices[neighbor[i]].parent = cur;
                vertices[neighbor[i]].distance = vertices[cur].distance + 1;  
                q.push(neighbor[i]);
            }
        }
        return vertices[endIndex].distance >= 10000 ? 0 : vertices[endIndex].distance + 1;
    }
};