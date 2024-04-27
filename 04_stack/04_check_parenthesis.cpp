/*
* Parenthesis checker
* Time Complexity: O(n) and space complexity O(n)
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check_parenthesis(string s)
{
	stack<char> st;
	for (string::iterator si = s.begin(); si != s.end(); si++)
	{
		char c = *si;
		if (c == '(' || c == '{' || c == '[')
			st.push(c);
		else if (st.empty())
			return false;
		else if (c == ')' && st.top() == '(')
			st.pop();
		else if (c == '}' && st.top() == '{')
			st.pop();
		else if (c == ']' && st.top() == '[')
			st.pop();
		else
			return false;
	}
	if (st.empty())
		return true;
}

int main()
{
	cout << check_parenthesis("()") << endl;
	cout << check_parenthesis("(]") << endl;
	cout << check_parenthesis("(({}))") << endl;
	cout << check_parenthesis("[()]]") << endl;
	cout << check_parenthesis("({[({})]})") << endl;
	cout << check_parenthesis("[[[[]]]]{}{}{}") << endl;
	cout << check_parenthesis("[[[[]]]](({)})") << endl;
}