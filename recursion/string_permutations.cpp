/*
* Find all permuations of a string
* Time Complexity: O(n*n!)
*/

#include <iostream>
#include <string>

using namespace std;

void permutations(string prefix, string input)
{
	if (input.size() <= 0)
	{
		cout << prefix << endl;
		return;
	}
	for (string::iterator i = input.begin(); i != input.end(); i++)
	{
		string curr_str;
		for (string::iterator ci = input.begin(); ci != input.end(); ci++)
			if (ci != i)
				curr_str.push_back(*ci);
		permutations(prefix + *i, curr_str);
	}
}

int main()
{
	string input = "abcd";
	permutations("", input);
	return 0;
}