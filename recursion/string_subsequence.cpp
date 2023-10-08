/*
* Find all subsequences of a string
* TimeComplexity: O(2^n)
*/

#include <iostream>
#include <string>

using namespace std;

void subsequence(string prefix, string suffix, int index)
{
	if (index >= suffix.size())
	{
		cout << prefix << endl;
		return;
	}
	// don't add
	subsequence(prefix, suffix, index + 1);
	// add to prefix
	prefix.push_back(suffix[index]);
	subsequence(prefix, suffix, index + 1);
}

int main()
{
	string input = "abcd";
	subsequence("", input, 0);
	return 0;
}

