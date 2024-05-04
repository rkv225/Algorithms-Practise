/*
Problem:
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Link: https://leetcode.com/problems/reorder-list
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        // return if only one element
        if(head->next == NULL)
            return;
        // find the middle of the list using slow and fast pointer
        ListNode *prev = NULL, *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        // reverse the second half of the linked list
        prev = NULL; 
        ListNode* cur = slow;
        while(cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        // we have heads of the both portion
        fast = prev;
        slow = head;
        // now interleave the list in required order
        cur = new ListNode(-1000); // dummy node
        head = cur;
        while(slow != NULL && fast != NULL) {
            cur->next = slow;
            cur = cur->next;
            slow = slow->next;
            cur->next = fast;
            cur = cur->next;
            fast = fast->next;
        }
        // any list still remaining
        if(slow != NULL)
            cur->next = slow;
        if(fast != NULL)
            cur->next = fast;
        // remove dummy node
        head = head->next;
    }
};