#include "../include/19_HasAllCodes.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <bitset>

#define KEY_LEN key

using namespace std;

bool HasAllCodes(string s, int k)
{
	if (s.length() < 1 || s.length() > 500000)
		return false;

	if (k < 1 || k > 20)
		return false;

	if (k > s.length())
		return false;

	set<string> sAllSubstr;
	for (int i = 0; i < s.length() - k + 1; i++)
	{
		string tmpStr;
		for (int j = i; j < i + k; j++)
		{
			tmpStr.push_back(s[j]);
		}
		sAllSubstr.insert(tmpStr);
		tmpStr = "";
	}

	if (sAllSubstr.size() < (int)pow(2, k))
		return false;

	return true;
}