#include "../include/20_RestoreIpAddress.h"

using namespace std;

void FunSearchIP(string s, int n, string ipAddr, vector<string> &retVec)
{
	if (n == 5 && s.length() == 0)
	{
		retVec.push_back(ipAddr);
		return;
	}
	if (n >= 5)
	{
		return;
	}
	int remain = 5 - n;
	if (s.length() < remain || s.length() > (remain * 3))
	{
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (s.length() < i)
			return;

		string part = s.substr(0, i);
		int num = atoi(part.c_str());
		string numVice = to_string(num);
		if (part.length() != numVice.length())
		{
			return;
		}
		if (num > 255)
			return;

		FunSearchIP(s.substr(i), n + 1, ipAddr + part + ".", retVec);
	}
}

vector<string> RestoreIpAddresses(string s)
{
	vector<string> retVec;

	if (s.length() < 4 || s.length() > 12)
		return retVec;
	
	FunSearchIP(s, 1, "", retVec);
	for (int i = 0; i < retVec.size(); i++)
	{
		retVec[i] = retVec[i].substr(0, retVec[i].length() - 1);
	}

	return retVec;
}