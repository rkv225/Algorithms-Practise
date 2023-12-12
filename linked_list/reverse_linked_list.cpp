/*
* Reverse a linked list
*/

#include <iostream>

using namespace std;

struct node
{
	int value;
	node* next;
};

node* reverse_list(node* head)
{
	node* curr = head;
	node* prev = NULL;
	while (curr != NULL)
	{
		node* tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	return prev;
}

int main()
{
	node* head = new node{ 1, NULL };
	node* curr = head;
	for (int i = 2; i < 10; i++)
	{
		curr->next = new node{ i, NULL };
		curr = curr->next;
	}
	curr = head;
	cout << "Linked List: " << endl;
	while (curr != NULL)
	{
		cout << curr->value << "->";
		curr = curr->next;
	}
	cout << "\nreversed list: " << endl;
	head = reverse_list(head);
	for (node* i = head; i != NULL; i = i->next)
		cout << i->value << "->";
}