/*
Problem:
You are given a binary tree having 'n' nodes.
The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.
Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.

Example :
Sample Input 1:
10 5 20 3 8 18 25 -1 -1 7 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
10 5 3 7 18 25 20

Solution:
- push root to ans
- traverse left and populate left nodes
- perform preorder traversal and put all leaf nodes
- traverse right and populate right nodes

Time Complexity: O(N)

Link: https://www.naukri.com/code360/problems/boundary-traversal-of-binary-tree_790725
*/

void left_traversal(TreeNode<int> *root, vector<int> &trav) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    trav.push_back(root->data);
    if(root->left != NULL)
        left_traversal(root->left, trav);
    else
        left_traversal(root->right, trav);
}
void leaf_traversal(TreeNode<int> *root, vector<int> &trav) {
    if(root == NULL)
        return;
    if (root->left == NULL && root->right == NULL) {
        trav.push_back(root->data);
        return;
    }
    leaf_traversal(root->left, trav);
    leaf_traversal(root->right, trav);
}
void right_traversal(TreeNode<int> *root, vector<int>& trav) {
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    trav.push_back(root->data);
    if(root->right != NULL)
        right_traversal(root->right, trav);
    else
        right_traversal(root->left, trav);
}
// main function
vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> traversal;
    if(root == NULL)
        return traversal;
    traversal.push_back(root->data);
    left_traversal(root->left, traversal);
    leaf_traversal(root, traversal);
    vector<int> right_trav;
    if(root->right != NULL)
        right_traversal(root->right, right_trav);
    for (vector<int>::reverse_iterator it = right_trav.rbegin(); it != right_trav.rend(); it++)
        traversal.push_back(*it);
    return traversal;
}