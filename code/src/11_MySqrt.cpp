#include "../include/11_MySqrt.h"

int MySqrt(int x)
{
	if (x < 0)
		return -1;
	else if (x == 0)
		return 0;
	else if (x == 1)
		return 1;

	int lNum = 1, rNum = x / 2;
	while (lNum <= rNum)
	{
		long long midNum = (lNum + rNum) / 2;
		if (midNum * midNum == x)
			return (int)midNum;
		else if (midNum * midNum > x)
		{
			rNum = midNum - 1;
		}
		else
		{
			lNum = midNum +1;
		}
	}
	return rNum;
}