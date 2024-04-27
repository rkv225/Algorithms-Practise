/*
* Flattening a linked list
* time complexity- O(n), space complexity- O(n) 
*/

#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int value;
	node* next;
	node* down;
};

void print_flat_linked_list(node* head)
{
	queue<node*> q;
	q.push(head);
	while (!q.empty())
	{
		node* curr = q.front();
		q.pop();
		while (curr != NULL)
		{
			cout << curr->value << ", ";
			if (curr->down != NULL)
				q.push(curr->down);
			curr = curr->next;
		}
	}
}

int main()
{
	node* head = new node{ 1, NULL, NULL };
	
	node* l1 = head;

	l1->down = new node{ 6, NULL, NULL };
	l1->down->next = new node{ 7, NULL, new node{ 11, NULL, NULL } };
	l1->down->next->next = new node{ 8, NULL, new node{ 12, NULL, new node{ 15, NULL, NULL } } };

	l1->next = new node{ 2, NULL, NULL };
	l1 = l1->next;

	l1->next = new node{ 3, NULL, NULL };
	l1 = l1->next;

	l1->next = new node{ 4, NULL, NULL };
	l1 = l1->next;

	l1->down = new node{ 9, new node{ 10, NULL, NULL}, new node{ 13, new node{ 14, NULL, NULL }, new node{ 16, new node{ 17, NULL, NULL }, NULL } } };

	l1->next = new node{ 5, NULL, NULL };
	l1 = l1->next;

	print_flat_linked_list(head);
}