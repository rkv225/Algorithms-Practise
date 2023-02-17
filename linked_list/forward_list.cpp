// only head -> insertion only from front and removal only from front, can iterate all element in forward
#include <iostream>

using namespace std;

class forward_list
{
public:
	forward_list()
	{
		size = 0;
	}
	int count()
	{
		return size;
	}
	void push_front(int x)
	{
		if (size == 0)
		{
			head = new element{ x, NULL };
		}
		else
		{
			element* tmp = new element{ x, head };
			head = tmp;
		}
		size++;
	}
	void pop_front()
	{
		if (size > 0)
		{
			head = head->next;
			size--;
		}
	}
	int front()
	{
		if (size > 0) return head->val;
		return -1;
	}
private:
	struct element
	{
		int val;
		element* next;
	} *head;
	int size;
};

int main()
{
	forward_list* list = new forward_list();
	list->push_front(0);
	list->push_front(1);
	list->push_front(2);
	int cc = list->count();
	cc = list->front();
	list->pop_front();
	cc = list->front();
	cc = list->count();
}