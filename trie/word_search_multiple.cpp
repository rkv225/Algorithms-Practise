/*
Problem:
Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []

Solution:
1. Construct a trie of input words
2. search the trie in board

Link: https://leetcode.com/problems/word-search-ii
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    char val;
    bool leaf;
    vector<Node*> child;
    Node(char v) {
        val = v;
        leaf = false;
        child.resize(26);
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('#');
    }
    void Insert(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new Node(word[i]);
            curr = curr->child[index];
        }
        curr->leaf = true;
    }
};
class Solution {
public:
    void rec(int i, int j, int m, int n, Node* cur, string prefix, vector<vector<char>>& board, vector<string>& ans) {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*')
            return;

        // save the board value to restore later
        char tmp = board[i][j];
        
        // fetch the node from child
        cur = cur->child[tmp - 'a'];
        if(cur == NULL)
            return;
        
        // add to prefix
        prefix.push_back(tmp);
        
        // word found
        if(cur->leaf) {
            // add to answer
            ans.push_back(prefix);
            // remove the word from trie
            cur->leaf = false;
        }

        // add placeholder to prevent process same char again
        board[i][j] = '*';

        // check in all directions
        rec(i + 1, j, m, n, cur, prefix, board, ans);
        rec(i - 1, j, m, n, cur, prefix, board, ans);
        rec(i, j + 1, m, n, cur, prefix, board, ans);
        rec(i, j - 1, m, n, cur, prefix, board, ans);

        // restore the board
        board[i][j] = tmp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // make a trie of all the given words
        Trie t;
        for(int i = 0; i < words.size(); i++) 
            t.Insert(words[i]);
        
        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        string prefix;
        
        // search trie in the board
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                rec(i, j, m, n, t.root, prefix, board, ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = { "oath", "pea", "eat", "rain" };
    vector<string> ans = s.findWords(board, words);
}