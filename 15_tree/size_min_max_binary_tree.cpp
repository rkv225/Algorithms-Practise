/*
* Size, minimum and maximum of a binary tree
* time complexity: O(n) and space complexity O(n)
*/

#include <iostream>

using namespace std;

class node
{
public:
    int value;
    node* left;
    node* right;
    node(int x)
    {
        value = x;
    }
};

int size(node* root)
{
    if (root == NULL)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

int max_node_value(node* root)
{
    if (root == NULL)
        return INT32_MIN;
    return max(root->value, max(max_node_value(root->left), max_node_value(root->right)));
}

int min_node_value(node* root)
{
    if (root == NULL)
        return INT32_MAX;
    return min(root->value, max(min_node_value(root->left), min_node_value(root->right)));
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Size of the tree is " << size(root) << endl;
    cout << "Minimum node value " << min_node_value(root) << endl;
    cout << "Maximum node value " << max_node_value(root) << endl;

    return 0;
}