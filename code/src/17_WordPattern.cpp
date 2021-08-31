#include "../include/17_WordPattern.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool WordPattern(string pattern, string s)
{
	vector<char> patternVec;
	vector<string> sVec;

	for (int i = 0; i < pattern.size(); i++)
		patternVec.push_back(pattern[i]);

	string tmpStr;
	s.push_back(' ');
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			sVec.push_back(tmpStr);
			tmpStr = "";
		}
		else
			tmpStr += s[i];
	}

	if (patternVec.size() != sVec.size())
		return false;

	map<char, string> patternMap;
	map<string, char> patternChekMap;
	for (int i = 0; i < patternVec.size(); i++)
		patternMap.insert(make_pair(patternVec[i], sVec[i]));
	for (int i = 0; i < sVec.size(); i++)
		patternChekMap.insert(make_pair(sVec[i], patternVec[i]));

	for (int i = 0; i < patternVec.size(); i++)
	{
		map<char, string>::iterator it1 = patternMap.find(patternVec[i]);
		if (it1->second != sVec[i] || it1 == patternMap.end())
		{
			return false;
		}
		else
		{
			map<string, char>::iterator it2 = patternChekMap.find(it1->second);
			if (it2->second != patternVec[i])
			{
				return false;
			}
		} 
	}

	return true;
}