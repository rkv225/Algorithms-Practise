#include<iostream>
#include<vector>
#include<cmath>
#include<math.h>

#define PARENT(i) i / 2
#define LEFT(i) 2 * i
#define RIGHT(i) (2 * i) + 1

using namespace std;

class max_heap
{
private:
	vector<int> arr;
	int heap_size;
	const int root = 9999999;
public:
	max_heap()
	{
		// we use a sentinal element at index 0 and heap index start from 1
		arr.push_back(root);
		heap_size = 0;
	}
	void Insert(int x) // this will break the heap property, need to call heapify after all insertions
	{
		arr.push_back(x);
		heap_size++;
	}
	void Heapify(int i)
	{
		int largest = i;
		int left = LEFT(i);
		int right = RIGHT(i);
		if (left <= heap_size && arr[left] > arr[largest])
			largest = left;
		if (right <= heap_size && arr[right] > arr[largest])
			largest = right;
		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			Heapify(largest);
		}
	}
	void BuildHeap()
	{
		for (int i = heap_size / 2; i > 0; i--)
			Heapify(i);
	}
	void Heapsort()
	{
		BuildHeap();
		for (int i = heap_size; i > 0 ; i--)
		{
			swap(arr[1], arr[i]);
			heap_size--;
			Heapify(1);
		}
		heap_size = arr.size() - 1;
	}
	void print()
	{
		for (int i = 1; i <= heap_size; i++)
		{
			cout << arr[i] << " ";
		}
	}
};

int main()
{
	max_heap heap;
	heap.Insert(4);
	heap.Insert(1);
	heap.Insert(3);
	heap.Insert(2);
	heap.Insert(16);
	heap.Insert(9);
	heap.Insert(10);
	heap.Insert(14);
	heap.Insert(8);
	heap.Insert(7);
	heap.Insert(30);
	heap.Insert(22);
	heap.Insert(28);
	heap.Insert(19);
	heap.Insert(12);
	heap.Insert(20);
	heap.Insert(27);
	heap.Insert(25);

	heap.Heapsort();

	heap.print();
}
