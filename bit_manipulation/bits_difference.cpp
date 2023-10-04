/*
* find the number of bits needed to convert a number a to b
* solution: first we XOR both numbers which will give which bits are different in bot numbers. 
* Then we count the number of set bits in XOR result using n & n-1 method
*/

#include <iostream>

using namespace std;

int count_set_bits(int& x)
{
	int n = x;
	int count = 0;
	while (n != 0)
	{
		n = n & n - 1;
		count++;
	}
	return count;
}

int main()
{
	int a = 11, b = 7;
	int diff_bits = a ^ b;
	cout << "difference in bits: " << count_set_bits(diff_bits) << endl;
	return 0;
}