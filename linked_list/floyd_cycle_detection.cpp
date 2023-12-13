/*
* Detect and remove cycle in a linked list
* Solution: floyd's cycle detection algorithm
*/

#include <iostream>

using namespace std;

struct node
{
	int value;
	node* next;
};

node* detect_cycle(node* head)
{
	node* fast = head;
	node* slow = head;
	while (fast != NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return fast;
	}
	return NULL;
}

node* find_intersection(node* head, node* meet)
{
	node* start = head;
	node* end = meet;
	while (start != end)
	{
		start = start->next;
		end = end->next;
	}
	return start;
}

node* create_list_with_loop(int n, int loop)
{
	node* head = new node{ 1, NULL };
	node* curr = head;
	for (int i = 2; i <= n; i++)
	{
		curr->next = new node{ i, NULL };
		curr = curr->next;
	}
	node* last = curr;
	curr = head;
	for (int i = 1; i < loop; i++)
		curr = curr->next;
	last->next = curr;
	return head;
}

int main()
{
	node* head = create_list_with_loop(10, 4);
	node* cycle = detect_cycle(head);
	if (cycle != NULL)
	{
		node* intersection = find_intersection(head, cycle);
		cout << intersection->value;
	}
}