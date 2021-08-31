#include "../include/07_AddBinary.h"

string AddBinary(string a, string b)
{
	int aLength = a.length();
	int bLength = b.length();
	string tmpStrAll;
	if (aLength < bLength)
	{
		tmpStrAll = a;
		a = b;
		b = tmpStrAll;
	}

	int addZeroNum = a.length() - b.length();
	for (int i = 0; i < addZeroNum; i++)
		b = "0" + b;

	int addFlag = 0, tmpNum;
	string tmpStr;
	tmpStrAll = "";
	for (int i = a.length() - 1; i >= 0; i--)
	{
		tmpNum = (a[i] - 48) + (b[i] - 48) + addFlag;
		if (tmpNum >= 2)
			addFlag = 1;
		else
			addFlag = 0;
		
		tmpNum = tmpNum % 2;
		tmpStr = tmpNum + 48;		
		tmpStrAll = tmpStr + tmpStrAll;
	}
	if (addFlag == 1)
		tmpStrAll = "1" + tmpStrAll;

	return tmpStrAll;
}