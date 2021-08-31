#include "../include/08_IsValid.h"

bool IsValid(string s)
{
	stack<char> strAll;
	int sLength = s.length();

	if ((s[0] == ')' || s[0] == ']' || s[0] == '}'))
	{
		return false;
	}

	for (int i = 0; i < sLength; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			strAll.push(s[i]);
			continue;
		}
		else if (!strAll.empty())
		{
			if ((s[i] == ')' && strAll.top() == '(') || (s[i] == ']' && strAll.top() == '[') || (s[i] == '}'  && strAll.top() == '{'))
			{
				strAll.pop();
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	if (!strAll.empty())
		return false;
	else
		return true;
}