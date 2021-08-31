#include "../include/09_MyAtoi.h"

int MyAtoi(string s)
{
	if (s.empty())
		return 0;

	s.erase(0, s.find_first_not_of(" "));

	int flag = 1;
	string strNew = "";
	if (s[0] == '-')
	{
		flag = -1;
		s.erase(0,1);
	}
	else if (s[0] == '+')
	{
		flag = 1;
		s.erase(0, 1);
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			strNew += s[i];
		else
			break;
	}

	int headZeroes = 0;
	for (int i = 0; i < strNew.length(); i++)
	{
		if (strNew[i] != '0')
			break;
		else
			headZeroes++;
	}
	strNew.erase(0, headZeroes);

	if (strNew.empty())
		return 0;

	long long  numNew = 0;
	int i;
	for (i = 0; i < strNew.length(); i++)
	{
		numNew = numNew * 10 + strNew[i] - 48;
		cout << numNew << endl;
		if (numNew > INT_MAX)
		{
			if (flag == 1)
				return INT_MAX;
			else
				return INT_MIN;
		}
	}
	return (int)flag * numNew;
}