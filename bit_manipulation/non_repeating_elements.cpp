/*
*  find 2 non repeating element in an array
* sol: if this problem whould have been to find the only non repeating element then we can do XOR of all elements and the xor will get the non repeating element.
* now we go in the same manner and we pluck the least significant bit of xor that will ensure that we have a number with this lsb and other without this.
* we take x = y = 0 and check all the numbers in array and if num is having this as lsb we xor with x and else with y.
* We will have both the numbers in x and y
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 6, 5, 4, 2, 1 };
	int xy = 0, x = 0, y = 0;
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
		xy = xy ^ *it;
	int rsb = xy & (~(xy - 1));
	for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		if ((*it & rsb) > 0)
			x = x ^ *it;
		else
			y = y ^ *it;
	}
	cout << x << " " << y;
	return 0;
}
