class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int digit = 0;
        // dummy node
        ListNode* sum = new ListNode(0); 
        ListNode* sum_head = sum;
        // add digits and propagate carry
        while(l1 != NULL && l2 != NULL) {
            digit = l1->val + l2->val + carry;
            carry = digit / 10;
            if(carry > 0)
                digit = digit % 10;
            sum->next = new ListNode(digit);
            sum = sum->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        // push all remaining values in l1 if any
        while(l1 != NULL) {
            digit = l1->val + carry;
            carry = digit / 10;
            if(carry > 0)
                digit = digit % 10;
            sum->next = new ListNode(digit);
            sum = sum->next;
            l1 = l1->next;
        }
        // push all remaining values in l2 if any
        while(l2 != NULL) {
            digit = l2->val + carry;
            carry = digit / 10;
            if(carry > 0)
                digit = digit % 10;
            sum->next = new ListNode(digit);
            sum = sum->next;
            l2 = l2->next;
        }
        // if carry remains at last then add it as well
        if(carry > 0)
            sum->next = new ListNode(carry);
        // remove dummy node
        sum_head = sum_head->next;
        return sum_head;
    }
};