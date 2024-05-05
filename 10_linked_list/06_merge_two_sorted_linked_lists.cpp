/*
Problem: 
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Link: https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution {
public:
    void helper(ListNode* list1, ListNode* list2, ListNode* head) {
        while(list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if(list1 != NULL)
            head->next = list1;
        if(list2 != NULL)
            head->next = list2;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // creating a dummy node
        ListNode *head = new ListNode(-1000);      
        helper(list1, list2, head);
        // remove dummy node
        head = head->next;
        return head;
    }
};