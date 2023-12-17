/*
* implement stack using two queues
time complexity: push-O(n) and pop-O(1)
*/

#include <iostream>
#include <queue>

using namespace std;

class Mystack
{
private:
	queue<int> q1;
	queue<int> q2;
	void transfer()
	{
		while (!q1.empty())
		{
			q2.push(q1.front());
			q1.pop();
		}
	}
	void transfer_back()
	{
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
public:
	void push(int x)
	{
		transfer();
		q1.push(x);
		transfer_back();
	}

	void pop()
	{
		if (!q1.empty())
			q1.pop();
	}

	int top()
	{
		if (!q1.empty())
			return q1.front();
		return -1; // underflow
	}
};

int main()
{
	Mystack* st = new Mystack();
	st->push(1);
	st->push(2);
	st->push(3);
	int x = st->top();
	st->pop();
	x = st->top();
	st->pop();
	st->pop();
	st->pop();
	x = st->top();
}