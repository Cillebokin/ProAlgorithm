#include "../include/15_SingleNumber.h"
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int SingleNumber(vector<int>& nums)
{
	if (nums.size() == 0)
		return -2147483648;

	multimap<int, int> numsMap;
	vector<int> keyVec;
	vector<int>::iterator keyVecIt;

	for (int i = 0; i < nums.size(); i++)
	{
		numsMap.insert(make_pair(nums[i], i));

		keyVecIt = find(keyVec.begin(), keyVec.end(), nums[i]);
		if (keyVecIt == keyVec.end())
			keyVec.push_back(nums[i]);
	}

	int tmpCount = 0;
	for (int i = 0; i < keyVec.size(); i++)
	{
		pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ret;
		ret = numsMap.equal_range(keyVec[i]);

		for (multimap<int, int>::iterator it = ret.first; it != ret.second; it++)
		{
			tmpCount++;
		}
		if (tmpCount % 2 == 1)
		{
			return keyVec[i];
		}
	}
	return -2147483648;
}