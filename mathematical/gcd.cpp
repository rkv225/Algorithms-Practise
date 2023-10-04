/*
* GCD of two numbers using euclid algorithm
* important property: a * b = lcm * gcd
*/

#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	int a = 40, b = 110;
	int g = gcd(a, b);
	cout << "gcd: " << g << endl;
	cout << "lcm: " << (a * b) / g << endl;
	return 0;
}