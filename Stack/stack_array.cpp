#include <iostream>

using namespace std;

class stack {
private:
	int top_index;
	int size;
	int s[100];
public:
	stack()
	{
		size = 0;
		top_index = -1;
	}
	bool empty()
	{
		return top_index < 0;
	}
	void push(int element)
	{
		if (size >= 100) return;
		top_index++;
		s[top_index] = element;
		size++;
	}
	int top()
	{
		if (!empty())
			return s[top_index];
		else
			return top_index;
	}
	void pop()
	{
		if (!empty())
		{
			top_index--;
			size--;
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