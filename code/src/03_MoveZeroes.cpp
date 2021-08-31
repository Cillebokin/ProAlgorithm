#include "../include/03_MoveZeroes.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void MoveZeroes(vector<int>& nums)
{
	int reSize = nums.size();
	vector<int>::iterator it = remove(nums.begin(), nums.end(), 0);
	nums.erase(it, nums.end());
	reSize -= nums.size();
	for (int i = 0; i < reSize; i++) 
		nums.push_back(0);
}