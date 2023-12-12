/*
* Find median of running stream of numbers
* Solution: We have to keep a sorted list where we need to regularly insert,
* so we keep a max heap and min heap and keep them balanced. At any point of time we can find out the median from top of heaps.
* Time Complexity: heap operation takes O(log n). So for n numbers => O(n log n)
* For two heaps of size n/2 we have space complexity => O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RunningMedian
{
public:
	void Insert(int x)
	{
		if (max_queue.empty() || max_queue.top() > x)
			max_queue.push(x); // insert into left heap
		else 
			min_queue.push(x); // insert into right heap
		if (min_queue.size() > max_queue.size())
		{
			max_queue.push(min_queue.top());
			min_queue.pop();
		}
		if (max_queue.size() > min_queue.size() + 1)
		{
			min_queue.push(max_queue.top());
			max_queue.pop();
		}
	}
	float GetMedian()
	{
		if (min_queue.size() == max_queue.size())
			return (max_queue.top() + min_queue.top()) / (float)2;
		return max_queue.top();
	}
private:
	priority_queue<int> max_queue;
	priority_queue<int, vector<int>, greater<int>> min_queue;
};

int main()
{
	RunningMedian m;
	m.Insert(1);
	m.Insert(2);
	m.Insert(3);
	m.Insert(4);
	m.Insert(5);
	m.Insert(6);
	m.Insert(7);
	m.Insert(8);
	m.Insert(9);
	cout << m.GetMedian() << endl;
	m.Insert(10);
	m.Insert(11);
	m.Insert(12);
	m.Insert(13);
	m.Insert(14);
	cout << m.GetMedian() << endl;
	m.Insert(15);
	cout << m.GetMedian() << endl;
}