/*
Problem:
Given a string 'S', you are supposed to return the number of distinct substrings(including empty substring) of the given string. You should implement the program using a trie.
A string ‘B’ is a substring of a string ‘A’ if ‘B’ that can be obtained by deletion of, several characters(possibly none) from the start of ‘A’ and several characters(possibly none) from the end of ‘A’. 
Two strings ‘X’ and ‘Y’ are considered different if there is at least one index ‘i’  such that the character of ‘X’ at index ‘i’ is different from the character of ‘Y’ at index ‘i’(X[i]!=Y[i]).

Sample Input 1 :
2
sds
abc
Sample Output 1 :
6
7
Explanation of Sample Input 1 :
In the first test case, the 6 distinct substrings are { ‘s’,’ d’, ”sd”, ”ds”, ”sds”, “” }
In the second test case, the 7 distinct substrings are {‘a’, ‘b’, ‘c’, “ab”, “bc”, “abc”, “” }.

Sample Input 2 :
2
aa
abab
Sample Output 2 :
3
8
Explanation of Sample Input 2 :
In the first test case, the two distinct substrings are {‘a’, “aa”, “” }.
In the second test case, the seven distinct substrings are {‘a’, ‘b’, “ab”, “ba”, “aba”, “bab”, “abab”, “” }

Solution: 
1. Find all the substrings of array
2. Instead of storingthem in a prefix, store them in trie
3. Incrementally we can append in a single iteration
4. If the trie don't contain the current substring value. it means that it's distinct so we increment the count.

Link: https://www.codingninjas.com/studio/problems/count-distinct-substrings_985292
*/

class Node
{
public:
	char v;
	vector<Node*> child;
	Node(char x)
	{
		v = x;
        child.resize(26);
	}
};

int countDistinctSubstrings(string &s)
{
    Node* root = new Node('#');
    int count = 1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        Node* curr = root;
        for (int j = i; j < n; j++) {
            int index = s[j] - 'a';
            if (curr->child[index] == NULL) {
                curr->child[index] = new Node(s[j]);
                count++;
            }
            curr = curr->child[index];
        }
    }
    return count;
}