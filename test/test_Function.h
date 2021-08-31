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

//���������
int CountVector(vector<int>& digits);
//��ֳ�Ԫ��
void SplitVector(vector<int>& digits, int num);
//��ֳ�Ԫ��string��
void SplitVectorString(vector<int>& digits, LPTSTR str);
//��ֳ�Ԫ��String plus��
void SplitVectorStringPlus(vector<int>& digits, LPTSTR str);
void SplitVectorStringPlus(vector<string>& digits, LPTSTR str);

void VectorIntToListNode(vector<int> &tmpVec, ListNode &tmpHead);

//��ι���������
void CreateFloorBinaryTreePreWork(std::vector<std::string> &digits, LPTSTR str);
void CreateFloorBinaryTreeAnotherWork(std::vector<std::string> &digits, TreeNode* &T);
TreeNode* CreateFloorBinaryTree2(vector<string> &digits, int i);
void FreeBinaryTree(TreeNode* &root);
#endif