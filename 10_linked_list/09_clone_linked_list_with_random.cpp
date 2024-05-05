/*
Problem: 
Clone a linked list with next pointer and a random pointer pointing to a node within the linked list

Solution: 
We will have new nodes created after every node and 
we will read the random pointer and point new node's random to the respective position of new node.
finally we will detach the new nodes to form a new linked list which will be replica of the original linked list

Time Complexity: O(n) and O(1) space complexity

Link: https://leetcode.com/problems/copy-list-with-random-pointer/
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create dummy nodes
        Node* curr = head;
        while(curr != NULL) {
            Node* tmp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = tmp;
            curr = curr->next->next; 
        }
        // clone random pointers
        curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        // detach dummy nodes to a separate linked list
        curr = head;
        Node* clone = new Node(-1000); // dummy node to clone
        Node* clone_head = clone;
        while(curr != NULL && curr->next != NULL) {
            clone->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            clone = clone->next;
        }
        // remove dummy node
        clone_head = clone_head->next; 
        return clone_head;
    }
};