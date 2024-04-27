/*
* checking if a number is odd or even using bitwise operators
* any odd number will end with 1 at 2^0th place and even number with 0 at that place
*/

#include <iostream>

using namespace std;

bool check_even(int &x)
{
	return (x & 1) == 0;
}

int main()
{
	int x = 6;
	cout << x << " is " << (check_even(x) ? "even" : "odd") << endl;
	return 0;
}