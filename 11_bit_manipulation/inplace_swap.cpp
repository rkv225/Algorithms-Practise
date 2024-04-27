/*
* swap numbers using bitwise operators
* this method is eefiecient performs the operation without using an extra variable
* perform tree xor operations in seques using the latest values from variables to achieve this:
* 1. a = a ^ b
* 2. b = a ^ b
* 3. a = a ^ b
*/

#include <iostream>

using namespace std;

void inplace_swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	int a = 5, b = 7;
	inplace_swap(a, b);
	return 0;
}