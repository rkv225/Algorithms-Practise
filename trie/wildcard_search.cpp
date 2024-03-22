/*
Problem:

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

Solution:
1. Implement a trie
2. Implement add word method with leaf
3. Now search recursively
    - if char then check current node. return if null or move to next char if exist
    - if it's wilcard then try all possible chars one by one and backtracking if not found
    - at last when you have checked all chars of word then if that's a leaf node then return true else false

Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/

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
class WordDictionary {
private:
    Node *root;
    bool search_helper(Node* cur, string w, int k) {
        if(k >= w.size())
            return cur->leaf;
        if(w[k] != '.') {
            Node* nxt = cur->child[w[k] - 'a'];
            if(nxt == NULL)
                return false;
            return search_helper(nxt, w, k + 1);
        }
        // wildcard matching
        for(char c = 'a'; c <= 'z'; c++) {
            Node* nxt = cur->child[c - 'a'];
            if(nxt != NULL && search_helper(nxt, w, k + 1)) {
                return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node('#');
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL) {
                curr->child[index] = new Node(word[i]);
            }
            curr = curr->child[index];
        }
        curr->leaf = true;
    }
    
    bool search(string word) {
        return search_helper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */