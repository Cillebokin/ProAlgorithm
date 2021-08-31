#include "../include/18_FindMinFibonacciNumbers.h"
#include <iostream>
#include <vector>

using namespace std;

int FindMinFibonacciNumbers(int k)
{
	if (k < 1 || k >= 1000000000)
		return -2147483648;

	vector<int> fibonacci;
	int num1 = 1, num2 = 1;
	int count = 0;
	fibonacci.push_back(num1);
	fibonacci.push_back(num2);
	while (num1 + num2 <= k) 
	{
		int tmpNum = num1 + num2;
		fibonacci.push_back(tmpNum);
		num1 = num2;
		num2 = tmpNum;
	}
	for (int i = fibonacci.size() - 1; i >= 0; --i)
	{
		if (k >= fibonacci[i]) 
		{
			count++;
			k -= fibonacci[i];
		}
	}
	return count;
}