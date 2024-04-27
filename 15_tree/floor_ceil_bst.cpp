/*
* Finding the floor value of a bst. Floor value is the value equal to or greatest value smaller then given value.
* If no such value exisits in tree then it's -1
* link-floor: https://practice.geeksforgeeks.org/problems/floor-in-bst/1
* link-ceil: https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
* solution: search for the given value like a binary search and store the previous value if smaller than the given value.
* Time complexity: O(log h) where h is the height of binary tree
*/

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

int floor(Node* root, int x) {
    Node* curr = root;
    int ans = -1;
    while (curr != NULL)
    {
        if (curr->data < x)
            ans = curr->data;
        if (curr->data == x)
            return x;
        if (curr->data > x)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return ans;
}

int ceil(Node* root, int x)
{
    Node* curr = root;
    int ans = INT32_MAX;
    while (curr != NULL)
    {
        if (curr->data < ans && curr->data > x)
            ans = curr->data;
        if (curr->data == x)
            return x;
        if (curr->data > x)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return ans == INT32_MAX ? -1 : ans;
}

int main()
{
    Node* root = new Node{ 7, new Node{ 2, NULL, NULL }, new Node{ 9, NULL, NULL } };
    root->left->left = new Node{ 5, NULL, NULL };
    root->left->right = new Node{ 6, NULL, NULL };
    root->right->left = new Node{ 8, NULL, NULL };
    root->right->right = new Node{ 20, NULL, NULL };

    cout << "Floor values: " << endl;
    cout << floor(root, 1) << endl;
    cout << floor(root, 8) << endl;
    cout << floor(root, 4) << endl;

    cout << "Ceil values: " << endl;
    cout << ceil(root, 1) << endl;
    cout << ceil(root, 8) << endl;
    cout << ceil(root, 4) << endl;
}