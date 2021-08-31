#include "../include/16_WordBreak.h"
#include <iostream>
#include <atlstr.h>

using namespace std;

bool WordBreak(string s, vector<string>& wordDict)
{
	vector<bool> DP(s.size()+1, false);
	DP[0] = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (DP[i])
		{
			for (auto word : wordDict)
			{
				int j = i + word.size();
				if (j <= s.size() && s.substr(i, word.size()) == word)
					DP[j] = true;
			}
		}
	}
	return DP[s.size()];
}