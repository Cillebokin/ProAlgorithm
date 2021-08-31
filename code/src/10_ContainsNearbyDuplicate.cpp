#include "../include/10_ContainsNearbyDuplicate.h"

using namespace std;

bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	k = abs(k);
	if (k == 0)
		return false;

	if (nums.size() == 0)
		return false;

	multimap<int, strMyMap> numsMap;
	vector<int> keyVec;
	vector<int>::iterator keyVecIt;
	int i = 0;
	strMyMap tmpStrMyMap;
	for (vector<int>::iterator numsIt = nums.begin(); numsIt != nums.end(); numsIt++, i++)
	{
		tmpStrMyMap.num = *numsIt;
		tmpStrMyMap.tag = i;
		numsMap.insert(make_pair(*numsIt, tmpStrMyMap));

		keyVecIt = find(keyVec.begin(), keyVec.end(), *numsIt);
		if (keyVecIt == keyVec.end())
			keyVec.push_back(*numsIt);
	}

	
	for (vector<int>::iterator keyIt = keyVec.begin(); keyIt != keyVec.end(); keyIt++)
	{
		int lastTag = -1;
		int newTag = -1;
		pair<multimap<int, strMyMap>::iterator, multimap<int, strMyMap>::iterator> ret;
		ret = numsMap.equal_range(*keyIt);
		for (multimap<int, strMyMap>::iterator it = ret.first; it != ret.second; it++)
		{
			newTag = it->second.tag;
			if (lastTag == -1)
			{
				lastTag = it->second.tag;
			}
			else
			{
				if (newTag - lastTag <= k)
				{
					return true;
				}
				else
				{
					lastTag = newTag;
				}
			}
		}
	}
	return false;
} 