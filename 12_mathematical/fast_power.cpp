/*
* Fast Power:
* a^b = (a^2)^b/2 when b is even
* a^b = a . a^b-1 when b is odd
* we keep on dividing b by 2 which will eventually decrease the power to 1
* We will store final result at that time 
*/

#include <iostream>

using namespace std;

long fast_power(int a, int b)
{
	// you are still limited to the size of long
	// y = x^b
	long x = a, y = 1;
	while (b > 0)
	{
		// if b is odd multiply with y
		if ((b & 1) != 0)
			y = y * x;
		// when b is even multiply with a
		x = x * x;
		b = b >> 1; // divide b by 2
	}
	return y;
}

int main()
{
	int a = 2, b = 11;
	cout << "fast power: " << fast_power(a, b) << endl;
	return 0;
}