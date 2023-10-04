/*
* Sieve of Eratosthenes is a simple and ancient algorithm used to find the prime numbers up to any given limit. It is one of the most efficient ways to find small prime numbers.
For a given upper limit n the algorithm works by iteratively marking the multiples of primes as composite, starting from 2. 
Once all multiples of 2 have been marked composite, the muliples of next prime, i.e. 3 are marked composite. 
This process continues until p ≤ √n where p is a prime number.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve_of_eratosthene(int n)
{
	vector<bool> table;
	table.assign(n + 1, true);
	table[0] = table[1] = false;
	for (int i = 2; i * i <= n; i++)
		for (int j = i + i; j <= n; j = j + i)
			table[j] = false;
	vector<int> primes;
	for (int i = 1; i <= n; i++)
		if (table[i])
			primes.push_back(i); 
	return primes;
}

int main()
{
	int n = 120;
	vector<int> primes = sieve_of_eratosthene(n);
	for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++)
		cout << *it << " ";
	return 0;
}