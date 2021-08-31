#ifndef _TEST_FUNCTION_H_
#define _TEST_FUNCTION_H_

#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>
#include <atlstr.h>
#include <../include/12_SortList.h>
#include <../include/13_BinaryTreePaths.h>
using namespace std;

//计算成整数
int CountVector(vector<int>& digits);
//拆分成元素
void SplitVector(vector<int>& digits, int num);
//拆分成元素string版
void SplitVectorString(vector<int>& digits, LPTSTR str);
//拆分成元素String plus版
void SplitVectorStringPlus(vector<int>& digits, LPTSTR str);
void SplitVectorStringPlus(vector<string>& digits, LPTSTR str);

void VectorIntToListNode(vector<int> &tmpVec, ListNode &tmpHead);

//层次构建二叉树
void CreateFloorBinaryTreePreWork(std::vector<std::string> &digits, LPTSTR str);
void CreateFloorBinaryTreeAnotherWork(std::vector<std::string> &digits, TreeNode* &T);
TreeNode* CreateFloorBinaryTree2(vector<string> &digits, int i);
void FreeBinaryTree(TreeNode* &root);
#endif