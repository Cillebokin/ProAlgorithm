#include "../include/14_LengthOfLongestSubstring.h"
#include <iostream>
#include <atlstr.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int LengthOfLongestSubstring(string s)
{
	int maxCount = 0;
	if (s.length() <= 1)
		return s.length();

	string tmpStr;
	int tag = -1;

	for (int i = 0; i < s.length(); i++)
	{
		tag = tmpStr.find(s[i]);
		if (tag == -1)
		{
			tmpStr += s[i];
			if (maxCount < tmpStr.length())
				maxCount = tmpStr.length();
		}
		else
		{
			i = i - tmpStr.length();
			tmpStr = "";
		}
	}

	return maxCount;
}