#include "01_PlusOne.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

void NumChange(vector<int>::reverse_iterator &rit,int &tag)
{
	if (*rit == 9 && tag == 1)
	{
		*rit = 0;
		tag = 1;
	}
	else if(*rit != 9 && tag == 1)
	{
		*rit += 1;
		tag = 0;
	}
	else
		tag = 0;
}
void NumAdd(vector<int>& digits)
{
	vector<int>::iterator it;
	it = digits.begin();
	if (*it == 0)
		digits.insert(it, 1, 1);
}
vector<int> PlusOne(vector<int>& digits)
{
	int tag = 1;
	vector<int>::reverse_iterator rit;

	for (rit = digits.rbegin(); rit != digits.rend(); rit++)
	{
		NumChange(rit, tag);
	}
	NumAdd(digits);

	return digits;
}