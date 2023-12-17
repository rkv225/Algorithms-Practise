/*
* Implement queue using stack
* time complexity: enqueue-O(1) dequeue-O(n)
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
	stack<int> push_stack;
	stack<int> pop_stack;
	void shift_stack()
	{
		if (!pop_stack.empty())
			return;
		while (!push_stack.empty())
		{
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
public:
	void enqueue(int x)
	{
		push_stack.push(x);
	}

	void dequeue()
	{
		shift_stack();
		if (!pop_stack.empty())
			pop_stack.pop();
	}

	int front()
	{
		shift_stack();
		if (!pop_stack.empty())
			return pop_stack.top();
		return -1; // underflow
	}
};

using namespace std;

int main()
{
	MyQueue q;
	int option = 0;
	int x;
	while (true)
	{
		cout << "1:enqueue, 2:dequeue, 3:front, 0:exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1: cout << "number: "; cin >> x; q.enqueue(x); cout << endl; break;
		case 2: q.dequeue(); break;
		case 3: cout << "front: " << q.front() << endl; break;
		default: break;
		}
		if (option == 0) break;
	}
}