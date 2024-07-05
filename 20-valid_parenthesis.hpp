/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#ifndef Solution20_H
#define Solution20_H

using namespace std;

class Solution20
{
public:
	bool isValid(string s)
	{
		stack<char> stk; // keeping track of order of brackets. for example if we encounter '(' and place it in stack and so on (only for opening brackets), and then whenever we encounter a closed bracket, we will check the top of the stack if the one we just encountered matches its complementary bracket from the top of the stack. This will cover all possibilities.
		for (auto i : s)
		{
			if (i == '(' || i == '[' || i == '{')
			{
				stk.push(i);
			}
			// else we have encountered a closing bracket
			else
			{
				if (stk.empty() ||
					(stk.top() == '(' && i != ')') ||
					(stk.top() == '[' && i != ']') ||
					(stk.top() == '{' && i != '}'))
				{
					return false;
				}
				else
				{

					stk.pop();
				}
			}
		}
		// VERY IMPORTANT STEP ; since they want us to return a bool value, this basically means that the func would check whether||not it is valid which would be synonymous with the stk returning empty because it would have to be so if all the brackets have been opened and closed in order.
		return stk.empty();
	}
};

#endif