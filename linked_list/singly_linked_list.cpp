// head and tail -> insertion from front and back in O(1), removal from front in O(1) but removal from back O(n), can iterate all element in forward
#include <iostream>

using namespace std;

class singly_linked_list
{
public:
	singly_linked_list()
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
			head = new element{ x, NULL };
			tail = head;
			size++;
		}
		else
		{
			element* tmp = new element{ x,  head };
			head = tmp;
			size++;
		}
	}
	void push_back(int x)
	{
		if (head == NULL)
		{
			head = new element{ x, NULL };
			tail = head;
			size++;
		}
		else
		{
			element* tmp = new element{ x, NULL };
			tail->next = tmp;
			tail = tmp;
			size++;
		}
	}
	void pop_front()
	{
		if (size > 0)
		{
			element* tmp = head;
			head = head->next;
			size--;
			free(tmp);
		}
	}
	void pop_back()
	{
		if (size == 1)
		{
			free(head);
			head = tail = NULL;
			size--;
		}
		if (size > 1)
		{
			element *tmp = tail;
			element* it = head;
			while (it->next != tail)
			{
				it = it->next;
			}
			tail = it;
			free(tmp);
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

private:
	struct element
	{
		int val;
		element* next;
	} *head, *tail;
	int size;
};

int main()
{
	singly_linked_list* list = new singly_linked_list();
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
}