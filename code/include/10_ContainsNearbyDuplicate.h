#ifndef _CONTAINS_NEARBY_DUPLICATE_H_
#define _CONTAINS_NEARBY_DUPLICATE_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

typedef struct strMyMap
{
	int num;
	int tag;
}strMyMap;

bool ContainsNearbyDuplicate(std::vector<int>& nums, int k);

#endif