#include <iostream>

using namespace std;

class queue
{
private:
	struct element {
		int value;
		element* next;
	} *head, *tail;
	int max_size;
	int count;
public:
	queue(int s)
	{
		max_size = s;
		count = 0;
	}
	bool empty()
	{
		return count == 0;
	}
	bool full()
	{
		return count == max_size;
	}
	void enqueue(int x)
	{
		if (full()) return;
		if (count == 0)
		{
			head = tail = new element{ x, NULL };
			count++;
		}
		else
		{
			tail->next = new element{ x, NULL };
			tail = tail->next;
			count++;
		}
	}
	void dequeue()
	{
		if (empty()) return;
		head = head->next;
		count--;
	}
	int front_element()
	{
		if (empty()) return -1;
		return head->value;
	}
	void print()
	{
		cout << "queue f-> " << head->value << " b-> " << tail->value << endl;
		element* it = head;
		while(it)
		{
			cout << it->value << " ";
			it = it->next;
		}
		cout << endl;
	}
};

int main()
{
	int n;
	cout << "size of queue" << endl;
	cin >> n;
	queue* q = new queue(n);
	int option = 0;
	int x;
	while (true)
	{
		cout << "1:enqueue, 2:dequeue, 3:front, 4:empty, 5:full, 6:print, 0:exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1: cout << "number: "; cin >> x; q->enqueue(x); cout << endl; break;
		case 2: q->dequeue(); break;
		case 3: cout << "front: " << q->front_element() << endl; break;
		case 4: if (q->empty()) cout << "empty" << endl; break;
		case 5: if (q->full()) cout << "full" << endl; break;
		case 6: q->print(); break;
		default: break;
		}
		if (option == 0) break;
	}
}