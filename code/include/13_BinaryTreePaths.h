#ifndef _BINARY_TREE_PATHS_H_
#define _BINARY_TREE_PATHS_H_

#include <iostream>
#include <vector>
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode() : val(0), left(nullptr) , right(nullptr){}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::string> BinaryTreePaths(TreeNode* root);

#endif