#include "../include/05_IsPalindrome.h"

bool IsPalindrome(int x)
{
	if (x < 0)
		return false;

	int reX = x;
	vector<int> nums;
	while (x > 0)
	{
		nums.push_back(x % 10);
		//cout << x % 10 << " ";
		x /= 10;
	}
	long long longNum = 0;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		longNum = longNum * 10 + *it;
		if (longNum > INT_MAX)
			return false;
	}
	if (longNum == reX)
		return true;
	else
		return false;
}