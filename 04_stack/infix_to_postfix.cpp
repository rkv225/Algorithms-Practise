/*
* Convert infix expression to postfix expression
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int get_precedence(char x)
{
	switch (x)
	{
	case '-': return 1;
	case '+': return 2;
	case '*': return 3;
	case '/': return 4;
	default: return -1;
	}
}

bool check_precedence(char a, char b)
{
	return get_precedence(a) > get_precedence(b);
}

bool check_operator(char x)
{
	return get_precedence(x) > 0;
}

string infix_to_postfix(string exp)
{
	string postfix_exp;
	int n = exp.size();
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		if (check_operator(exp[i]))
		{
			while (!st.empty() && !check_precedence(exp[i], st.top()) && st.top() != '(')
			{
				postfix_exp.push_back(st.top());
				st.pop();
			}
			st.push(exp[i]);
		}
		else if (exp[i] == '(')
		{
			st.push(exp[i]);
		}
		else if (exp[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				postfix_exp.push_back(st.top());
				st.pop();
			}
			if (st.empty())
				return "Invalid expression";
			if (st.top() == '(')
				st.pop();
		}
		else
		{
			postfix_exp.push_back(exp[i]);
		}
	}
	while (!st.empty() && st.top() != '(')
	{
		postfix_exp.push_back(st.top());
		st.pop();
	}
	if (!st.empty())
		return "Invalid expression";
	return postfix_exp;
}

int main()
{
	string exp = "a+b*(d+e)";
	cout << "Infix expression: " << exp << endl;
	string postfix_exp = infix_to_postfix(exp);
	cout << "Postfix expression: " << postfix_exp << endl;
}