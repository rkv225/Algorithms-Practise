// head and tail -> insertion from front and back in O(1), removal from front in O(1) removal from back O(1), can iterate all element in forward, backward, remove any element from anywhere in O(1)
#include <iostream>

using namespace std;

class doubly_linked_list
{
public:
	doubly_linked_list()
	{
		size = 0;
	}
	int count()
	{
		return size;
	}
	void push_front(int x)
	{
		if (head == NULL)
		{
			head = new element{ x, NULL, NULL };
			tail = head;
			size++;
		}
		else
		{
			element* tmp = new element{ x, NULL, head };
			head->prev = tmp;
			head = tmp;
			size++;
		}
	}
	void push_back(int x)
	{
		if (head == NULL)
		{
			head = new element{ x, NULL, NULL };
			tail = head;
			size++;
		}
		else
		{
			element* tmp = new element{ x, tail, NULL };
			tail->next = tmp;
			tail = tmp;
			size++;
		}
	}
	void pop_front()
	{
		if (size > 1)
		{
			element* tmp = head;
			head = head->next;
			head->prev = NULL;
			free(tmp);
			size--;
		}
		if (size == 1)
		{
			free(head);
			head = tail = NULL;
			size--;
		}
	}
	void pop_back()
	{
		if (size > 1)
		{
			element* tmp = tail;
			tail = tmp->prev;
			tail->next = NULL;
			free(tmp);
			size--;
		}
		if (size == 1)
		{
			free(head);
			head = tail = NULL;
			size--;
		}
	}
	int front()
	{
		if (size > 0) return head->val;
		return -1;
	}
	int back()
	{
		if (size > 0) return tail->val;
		return -1;
	}
	void remove(int x)//removes the first occurance of number from front
	{
		element* it = head;
		while (it != NULL)
		{
			if (it->val == x)
			{
				if (it->prev != NULL) it->prev->next = it->next;
				if (it->next != NULL) it->next->prev = it->prev;
				if (it == head) head = it->next;
				if (it == tail) tail = it->prev;
				size--;
				free(it);
				return;
			}
			it = it->next;
		}
	}

private:
	struct element
	{
		int val;
		element* prev;
		element* next;
	} *head, *tail;
	int size;
};

int main()
{
	doubly_linked_list* list = new doubly_linked_list();
	list->push_front(0);
	list->push_front(1);
	list->push_front(2);
	list->push_back(9);
	list->push_back(8);
	list->push_back(7);
	int cc = list->count();
	cc = list->front();
	list->pop_front();
	cc = list->front();
	cc = list->back();
	list->pop_back();
	cc = list->count();
	list->remove(0);
	list->remove(8);
	list->remove(7);
	list->remove(1);
	list->remove(9);
}