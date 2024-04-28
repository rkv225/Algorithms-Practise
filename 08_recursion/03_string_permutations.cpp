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
		// taking out rest of the input string except current character
		string curr_str;
		for (string::iterator ci = input.begin(); ci != input.end(); ci++)
			if (ci != i)
				curr_str.push_back(*ci);
		// now add the current char to prefix and try other combinations with rest of the string
		permutations(prefix + *i, curr_str);
	}
}

int main()
{
	string input = "abcd";
	permutations("", input);
	return 0;
}