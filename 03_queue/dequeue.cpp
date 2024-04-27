#include<iostream>

using namespace std;

class dequeue
{
private:
	int arr[100], front, rear, size, max_size;
	int next(int index)
	{
		index++;
		if (index >= max_size)
			index = 0;
		return index;
	}
	int prev(int index)
	{
		index--;
		if (index < 0)
			index = max_size - 1;
		return index;
	}
public:
	dequeue(int max)
	{
		front = -1;
		rear = -1;
		size = 0;
		max_size = max;
	}
	int front_element()
	{
		return arr[front];
	}
	int rear_element()
	{
		return arr[rear];
	}
	bool push_back(int val)
	{
		if (size < max_size)
		{
			rear = next(rear);
			arr[rear] = val;
			size++;
			if (size == 1)
				front = rear;
			return true;
		}
		return false;
	}
	bool pop_back()
	{
		if (size > 0)
		{
			rear = prev(rear);
			size--;
			if (size <= 0)
				rear = front = -1;
			return true;
		}
		return false;
	}
	bool push_front(int val)
	{
		if (size < max_size)
		{
			front = prev(front);
			arr[front] = val;
			size++;
			if (size == 1)
				rear = front;
			return true;
		}
		return false;
	}
	bool pop_front()
	{
		if (size > 0)
		{
			front = next(front);
			size--;
			if (size <= 0)
				front = rear = -1;
			return true;
		}
		return false;
	}
	bool empty()
	{
		return size == 0;
	}
	bool full()
	{
		return size == max_size;
	}
	void print()
	{
		cout << "queue f-> " << front << " b-> " << rear << endl;
		int it = front, i = 0;
		while (i < size)
		{
			cout << arr[it] << " ";
			it = next(it);
			i++;
			if (i >= size)
				break;
		}
		cout << endl;
	}
};

int main()
{
	int n;
	cout << "size of queue" << endl;
	cin >> n;
	dequeue* q = new dequeue(n);
	int option = 0;
	int x;
	while (true)
	{
		cout << "1:enqueue_front, 2:dequeue_front, 3:enqueue_back, 4:dequeue_back, 5:front_element, 6:back_element, 7:check_empty, 8:check_full, 9:print, 0:exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1: cout << "number: "; cin >> x; q->push_front(x); cout << endl; break;
		case 2: q->pop_front(); break;
		case 3: cout << "number: "; cin >> x; q->push_back(x); cout << endl; break;
		case 4: q->pop_back();break;
		case 5: cout << "front: " << q->front_element() << endl; break;
		case 6: cout << "back: " << q->rear_element() << endl; break;
		case 7: if (q->empty()) cout << "empty" << endl; break;
		case 8: if (q->full()) cout << "full" << endl; break;
		case 9: q->print(); break;
		default: break;
		}
		if (option == 0) break;
	}
}