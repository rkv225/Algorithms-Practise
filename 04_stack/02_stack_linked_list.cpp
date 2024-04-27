#include <iostream>

using namespace std;

class stack {
private:
	int size;
	struct element {
		int value;
		element* next;
	} *top_element;
public:
	stack()
	{
		size = 0;
	}
	bool empty()
	{
		return size == 0;
	}
	void push(int x)
	{
		if (empty())
		{
			top_element = new element{ x, NULL };
			size++;
		}
		else
		{
			element* new_element = new element{ x, top_element };
			top_element = new_element;
			size++;
		}
	}
	int top()
	{
		if (!empty())
			return top_element->value;
		else
			return -1;
	}
	void pop()
	{
		if (!empty())
		{
			size--;
			top_element = top_element->next;
		}
	}
};

int main()
{
	stack* st = new stack();
	bool e = st->empty();
	st->push(1);
	st->push(2);
	st->push(3);
	e = st->empty();
	int x = st->top();
	st->pop();
	x = st->top();
	st->pop();
	st->pop();
	st->pop();
}