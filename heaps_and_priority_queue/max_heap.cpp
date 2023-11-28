/*
/* Heap is a complete binary tree. In a max heap element in root in always larger than it's children.
*/

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
	const int root = 9999999;
public:
	max_heap()
	{
		// we use a sentinal element at index 0 and heap index start from 1
		arr.push_back(root);
	}
	void Insert(int x) // this will break the heap property, need to call heapify after all insertions
	{
		arr.push_back(x);
	}
	void Heapify(int i) // O(h), h = log n, O(log n)
	{
		int length = arr.size() - 1;
		int largest = i;
		int left = LEFT(i);
		int right = RIGHT(i);
		if (left <= length && arr[left] > arr[largest])
			largest = left;
		if (right <= length && arr[right] > arr[largest])
			largest = right;
		if (largest != i)
		{
			swap(arr[largest], arr[i]);
			Heapify(largest);
		}
	}
	void BuildHeap()
	{
		int length = arr.size() - 1;
		for (int i = length / 2; i > 0; i--)
			Heapify(i);
	}

	void PrintHeap()
	{
		int height = log2(arr.size() - 1) + 1;
		int columns = pow(2, height - 1);
		for (int l = 0; l < height; l++)
		{
			int values = pow(2, l);
			int spaces = columns / values;
			int v = values;
			int count = 0;
			while(count < values)
			{
				for (int s = 0; s < spaces;s++)
					cout << "\t";
				if (v < arr.size())
					cout << arr[v];
				count++;
				v++;
			}
			cout << endl;
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

	heap.BuildHeap();
	heap.PrintHeap();
}
