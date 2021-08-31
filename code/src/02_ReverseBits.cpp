#include "02_ReverseBits.h"
#include <iostream>
#include <cmath>

using namespace std;

uint32_t ReverseBits(uint32_t n)
{
	uint32_t tmp;
	uint32_t sum = 0;
	for (int i = 0, j = 31; i < 32; i++, j--)
	{
		tmp = n % 2;
		n /= 2;
		sum += (unsigned int)tmp * pow(2, j);
	}
	return sum;
}