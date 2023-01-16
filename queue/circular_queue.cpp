#include <iostream>

using namespace std;

class queue
{
private:
	int size;
	int arr[100];
	int front;
	int back;
	bool is_full;

	int next(int p)
	{
		p++;
		if (p >= size) p = 0;
		return p;
	}
	int prev(int p)
	{
		p--;
		if (p < 0) p = size - 1;
		return p;
	}
public:
	queue(int s)
	{
		front = 0;
		back = 0;
		size = s;
		is_full = false;
	}
	bool empty()
	{
		return front == back && !is_full;
	}
	bool full()
	{
		return is_full;
	}
	void enqueue(int x)
	{
		if (full()) return;
		arr[back] = x;
		back = next(back);
		if (back == front) is_full = true;
	}
	void dequeue()
	{
		if (empty()) return;
		front = next(front);
		if (is_full) is_full = false;
	}
	int front_element()
	{
		if (empty()) return -1;
		return arr[front];
	}
	void print()
	{
		cout << "queue f-> " << front << " b-> " << back << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
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