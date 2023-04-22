#include<iostream>
#include<vector>
#include<cmath>
#include<math.h>

#define PARENT(i) i / 2
#define LEFT(i) 2 * i
#define RIGHT(i) (2 * i) + 1

using namespace std;

class max_priority_queue
{
private:
	vector<int> arr;
	int size;
	const int root = 9999999;

	void Heapify(int i)
	{
		int largest = i;
		int left = LEFT(i);
		int right = RIGHT(i);
		if (left <= size && arr[left] > arr[largest])
			largest = left;
		if (right <= size && arr[right] > arr[largest])
			largest = right;
		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			Heapify(largest);
		}
	}
	void IncreaseKey(int i, int k)
	{
		if (k <= arr[i])
			return;
		arr[i] = k;
		int j = PARENT(i);
		while (j > 0 && arr[j] < k)
		{
			swap(arr[j], arr[i]);
			i = j;
			j = PARENT(j);
		}
	}
public:
	max_priority_queue()
	{
		// we use a sentinal element at index 0 and heap index start from 1
		arr.push_back(root);
		size = 0;
	}
	void Insert(int x)
	{
		arr.push_back(-9999999);
		size++;
		IncreaseKey(size, x);
	}
	int Max()
	{
		return size > 0 ? arr[1] : -1;
	}
	void RemoveMax()
	{
		if (size <= 0)
			return;
		swap(arr[1], arr[size]);
		size--;
		Heapify(1);
	}
	void ExtractPrint()
	{
		cout << endl;
		while(size > 0)
		{
			cout << Max() << " ";
			RemoveMax();
		}
	}
};

int main()
{
	max_priority_queue queue;
	queue.Insert(4);
	queue.Insert(1);
	queue.Insert(3);
	queue.Insert(2);
	queue.Insert(16);
	queue.Insert(9);
	queue.Insert(10);
	queue.Insert(14);
	queue.Insert(8);
	queue.Insert(7);
	queue.Insert(30);
	queue.Insert(22);
	queue.Insert(28);
	queue.Insert(19);
	queue.Insert(12);
	queue.Insert(20);
	queue.Insert(27);
	queue.Insert(25);

	queue.ExtractPrint();
}
