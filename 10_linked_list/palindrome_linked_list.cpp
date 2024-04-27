/*
* Find if a linked list is a palindrome or not
* Solution: find the middle of the linked list and then reverse the second half. Now we can check for both halves to be equal.
* Time Complexity: O(n) and space complexity O(1)
*/

#include <iostream>

using namespace std;

struct node
{
	char value;
	node* next;
};

bool check_palindrome(node* head)
{
	// find mid of the linked list
	node* fast = head;
	node* slow = head;
	node* prev = NULL;
	while (fast != NULL)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
		}
	}
	// slow has the middle
	prev->next = NULL;
	prev = NULL;
	// reverse from this position
	while (slow != NULL)
	{
		node* tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}
	// prev has the head of reversed part

	// now using slow pointer compare the linked lists
	slow = head;
	while (prev != NULL && slow != NULL)
	{
		if (prev->value != slow->value)
			return false;
		prev = prev->next;
		slow = slow->next;
	}
	return true;
}

node* create_list(string s)
{
	node* head = new node{ '\0', NULL };
	node* curr = head;
	for (string::iterator si = s.begin(); si != s.end(); si++)
	{
		if (curr->value == '\0')
			curr->value = *si;
		else
		{
			curr->next = new node{ *si, NULL };
			curr = curr->next;
		}
	}
	return head;
}

int main()
{
	node* list = create_list("aabcdcbaa");
	bool x = check_palindrome(list);
}
