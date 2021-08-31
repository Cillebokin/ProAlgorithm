#include "../include/13_BinaryTreePaths.h"

#include <string>
#include <atlstr.h>
#include <algorithm>

using namespace std;

void FunFindAllPaths(TreeNode *root, vector<string> &Paths, string strPaths)
{
	if (root->left == NULL && root->right == NULL)
	{
		Paths.push_back(strPaths);
		return;
	}
	if (root->left != NULL)
	{
		string tmpPaths = strPaths + "->" + to_string(root->left->val);
		FunFindAllPaths(root->left, Paths, tmpPaths);
	}
	if (root->right != NULL)
	{
		string tmpPaths = strPaths + "->" + to_string(root->right->val);
		FunFindAllPaths(root->right, Paths, tmpPaths);
	}
}

vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> Paths;
	if (root == NULL)
		return Paths;

	FunFindAllPaths(root, Paths, to_string(root->val));
	return Paths;
}