/*
* Problem: Connect N ropes with minimum cost
* Solution: Place all the values in array to a priority queue and then take two samllest ropes and join them till it is a single rope
* Complexity: O(n) time complexity and O(n) space complexity
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calculate_cost(vector<int>& arr)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int cost = 0;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		pq.push(*it);
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int c = a + b;
		pq.push(c);
		cost = cost + c;
	}
	return cost;
}

int main()
{
	vector<int> arr = { 2, 5, 4, 8, 6, 9 };
	cout << calculate_cost(arr);
}