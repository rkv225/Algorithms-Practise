/*
* Finding (a^b)%n where a^b is very large i.e. a single variable can't hold it.
* In order to calculate this, we have mathematical formulas
* (a + b) % n = (a % n + b % n) % n
* (a * b) % n = (a % n * b % n) % n
*/

#include <iostream>

using namespace std;

int ab_mod_n(int a, int b, int n)
{
	int y = 1;
	while (b > 0)
	{
		if ((b & 1) != 0)
			y = (y % n * a % n) % n;
		a = (a % n * a % n) % n;
		b = b >> 1;
	}
	return y;
}

int main()
{
	int a = 2, b = 11, n = 10;
	cout << "a^b mod n: " << ab_mod_n(a, b, n) << endl;
	return 0;
}