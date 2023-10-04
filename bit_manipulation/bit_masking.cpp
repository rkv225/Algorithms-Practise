/*
* Bit Masking: 1 << i
* find ith bit: n & mask
* set ith bit: n | mask
* clear ith bit: n & (~(1 << i))
*/

# include <iostream>

using namespace std;

void print_binary(int x)
{
	// assume 16 bit number
	int m = 32768;
	while (m != 0)
	{
		if ((x & m) > 0)
			cout << "1 ";
		else
			cout << "0 ";
		m = m >> 1;
	}
	cout << "(" << x << ")" << endl;
}

int main()
{
	int n = 46; // (101110)
	print_binary(n);
	
	int i = 6;
	
	// bit mask
	int mask = 1 << i;
	print_binary(mask);
	
	int bit;

	// find ith bit
	bit = (n & mask) > 0 ? 1 : 0;
	cout << i << "th bit is " << bit << endl;

	// set ith bit
	cout << "setting " << i << "th bit" << endl;
	print_binary(n | mask);

	// clear ith bit
	cout << "clearing " << i << "th bit" << endl;
	print_binary(n & (~mask));
	
	// clear right most set bit
	cout << "clearing right most bit" << endl;
	print_binary(n & (n - 1));

	// get right most set bit
	cout << "pluck the right most set bit" << endl;
	print_binary(n & (~(n - 1)));
	
	return 0;
}