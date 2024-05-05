/*
Problem:
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Solution:
1. advance fast pointer with n steps
2. check for base condition (mentioned in comment)
3. start from beginning till fast is exhausted
4. remove from slow position
5. return head

Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // advance n steps
        ListNode* fast = head;
        while(n > 0) {
            fast = fast->next;
            n--;
        }
        if(fast == NULL) {
            // if n is equal to te size of list then we are removing first element
            // as nth element from back will be first element, we only need to remove it
            return head->next;
        }
        ListNode* slow = head;
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};