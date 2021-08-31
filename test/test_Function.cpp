#include "stdafx.h"
#include "test_Function.h"

//计算成整数
int CountVector(vector<int>& digits)
{
	int mul = pow(10, digits.size() - 1);
	int sum = 0;
	for (vector<int>::iterator it = digits.begin(); it != digits.end(); it++)
	{
		sum += *it * mul;
		mul /= 10;
	}
	return sum;
}
//拆分成元素
void SplitVector(vector<int>& digits, int num)
{
	vector<int>::iterator it;
	it = digits.begin();
	while (num > 0)
	{
		digits.push_back(num % 10);
		num /= 10;
	}
	reverse(digits.begin(), digits.end());
}
//拆分成元素string版
void SplitVectorString(vector<int>& digits, LPTSTR str)
{
	CString newStr;
	char tmpSigChar;
	int tmpSigNum;
	//vector<int>::iterator it = digits.begin();

	newStr.Format(_T("%s"), str);//emm

	for (int i = 0; i < newStr.GetLength(); i++)
	{
		tmpSigChar = newStr[i];
		tmpSigNum = atoi(&tmpSigChar);
		digits.push_back(tmpSigNum);
	}
}
void SplitVectorStringPlus(vector<int>& digits, LPTSTR str)
{
	CString newStr;
	CString tmpSigNumStr;
	int tmpSigNum;

	newStr.Format(_T("%s"), str);//emm
	if (newStr.IsEmpty())
		return;

	newStr += ",";
	for (int i = 0; i < newStr.GetLength(); i++)
	{
		if (newStr[i] != ',')
		{
			tmpSigNumStr += newStr[i];
			continue;
		}
		cout << tmpSigNumStr << endl;
		tmpSigNum = atoi(tmpSigNumStr);
		digits.push_back(tmpSigNum);
		tmpSigNumStr = "";
	}
}
void SplitVectorStringPlus(vector<string>& digits, LPTSTR str)
{
	CString newStr;
	CString tmpSigNumStr;
	int tmpSigNum;

	newStr.Format(_T("%s"), str);//emm
	if (newStr.IsEmpty())
		return;

	newStr += ",";
	for (int i = 0; i < newStr.GetLength(); i++)
	{
		if (newStr[i] != ',')
		{
			tmpSigNumStr += newStr[i];
			continue;
		}
		digits.push_back(tmpSigNumStr.GetBuffer(0));
		tmpSigNumStr = "";
	}
}
void VectorIntToListNode(vector<int> &tmpVec, ListNode &tmpHead)
{
	tmpHead = ListNode(tmpVec[0]);
	ListNode *p = &tmpHead;

	vector<int>::iterator it = tmpVec.begin();
	for (it = ++it; it != tmpVec.end(); it++)
	{
		p->next = new ListNode(*it);
		p = p->next;
	}
}
//层次构建二叉树
void CreateFloorBinaryTreePreWork(std::vector<std::string> &digits, LPTSTR str)
{
	CString newStr;
	CString tmpSigNumStr;
	int tmpSigNum;

	newStr.Format(_T("%s"), str);//emm
	if (newStr.IsEmpty())
		return;

	newStr += ",";
	for (int i = 0; i < newStr.GetLength(); i++)
	{
		if (newStr[i] != ',')
		{
			tmpSigNumStr += newStr[i];
			continue;
		}
		digits.push_back(tmpSigNumStr.GetBuffer(0));
		tmpSigNumStr = "";
	}
}
void CreateFloorBinaryTreeAnotherWork(std::vector<std::string> &digits, TreeNode* &T)
{
	std::queue<TreeNode *>que;
	int i = 0;

	T = new TreeNode;
	T->val = atoi(digits[0].c_str());
	T->left = NULL;
	T->right = NULL;

	TreeNode *p = T, *q;
	que.push(p);
	i = 1;

	while (!que.empty())
	{
		p = que.front();
		que.pop();

		if (!p)
			continue;

		if (digits[i] != "null")
		{
			q = new TreeNode;
			q->val = atoi(digits[i].c_str());
			q->left = NULL;
			q->right = NULL;
			p->left = q;
		}
		else
		{
			p->left = NULL;
		}
		que.push(p->left);

		if (digits[i + 1] != "null")
		{
			q = new TreeNode;
			q->val = atoi(digits[i + 1].c_str());
			q->left = NULL;
			q->right = NULL;
			p->right = q;
		}
		else
		{
			p->right = NULL;
		}
		que.push(p->right);

		i += 2;
		if (i >= digits.size())
			return;
	}
}
TreeNode* CreateFloorBinaryTree2(vector<string> &digits, int i)
{
	if (digits.size() == 0)
		return NULL;

	TreeNode *root = NULL;
	if (i < digits.size() && digits[i] != "null")
	{
		root = new TreeNode;

		if (root == NULL)
			return NULL;

		root->val = atoi(digits[i].c_str());
		root->left = CreateFloorBinaryTree2(digits, 2 * i + 1);
		root->right = CreateFloorBinaryTree2(digits, 2 * i + 2);
	}
	return root;
}
void FreeBinaryTree(TreeNode* &root)
{
	if (root->left != NULL)
	{
		FreeBinaryTree(root->left);
	}
	if (root->right != NULL)
	{
		FreeBinaryTree(root->right);
	}
	delete root;
	return;
}