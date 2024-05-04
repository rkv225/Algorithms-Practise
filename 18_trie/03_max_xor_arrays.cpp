/*
Problem: 
You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. 
Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.

Sample Input 1:
1
7 7
6 6 0 6 8 5 6
1 7 1 7 8 0 2
Sample Output 1:
15
Explanation of sample input 1:
First testcase:
Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15

Sample Input 2:
1
3 3
25 10 2
8 5 3
Sample Output 2:
28
Explanation of sample input 2:
First test case:
28 is the maximum possible xor given by pair = (25, 5). It is the maximum possible xor among all possible pairs.

Solution:
1. Create a trie for elements in array 1 in binary i.e. trie will have only 2 child 0 and 1
2. foreach element in array 2, compute xor by finding opposite bit (if possible)
3. return the max xor

Time Complexity: O(N*32) + O(M*32)
Reason: For inserting all the elements of arr1 into the trie take O(N*32) [32 Bit] and O(M*32) for finding the maxXOR for every element of arr2.

Space Complexity: O(N*32)
Reason: Since we are inserting all the elements of arr1 into trie where every element is of size 32 bit but the space complexity will be less than O(N*32) because they might have overlapped.

Link: https://www.codingninjas.com/studio/problems/maximum-xor_973113
*/

class Node {
public:
    vector<Node*> child;
    Node() {
        child.resize(2);
    }
};
void Insert(Node* cur, int x) {
    for (int i = 31; i >= 0; i--) {
        int bit = (x & (1 << i)) > 0 ? 1 : 0;
        if(cur->child[bit] == NULL)
            cur->child[bit] = new Node();
        cur = cur->child[bit];
    }
}
int ComputeSum(Node* cur, int x) {
    int sum = 0;
    for(int i = 31; i >= 0; i--) {
        int bit = (x & (1 << i)) > 0 ? 1 : 0;
        if(cur->child[!bit] != NULL) {
            sum = sum | (1 << i);
            cur = cur->child[!bit];
        } else {
            cur = cur->child[bit];
        }
    }
    return sum;
}
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    int mxor = 0;
    // create a trie from arr1
    Node* trie1 = new Node();
    for (int i = 0; i < arr1.size(); i++)
        Insert(trie1, arr1[i]);
    // compute max xor for each element from arr2
    for(int i = 0; i < arr2.size(); i++) {
        mxor = max(mxor, ComputeSum(trie1, arr2[i]));
    }
    return mxor;
}