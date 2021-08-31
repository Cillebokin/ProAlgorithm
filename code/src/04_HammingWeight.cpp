#include "../include/04_HammingWeight.h"
int HammingWeight(unsigned int n)
{
	int num = 0;
	unsigned int tmp;
	while (n != 0)
	{
		tmp = n & 1;
		if (tmp == 1)
		{
			num++;
		}
		n = n >> 1;
	}
	return num;
}