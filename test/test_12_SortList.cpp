#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "12_SortList.h"
#include "test_Function.h"

#define SORTLIST_INI_PATH "../code/config/12_SortList.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod12_SortList)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, SORTLIST_INI_PATH);
			//Assert::AreEqual(1,secNum);

			LPTSTR headLP = (LPTSTR)malloc(50);
			LPTSTR outputLP = (LPTSTR)malloc(50);

			LPCSTR realSecName;
			CString secTag;

			for (int i = 0; i < secNum; i++)
			{
				vector<int> headVec;
				vector<int> outputVec;

				ListNode headList;
				ListNode outputList;

				ListNode *tmp;
				ListNode *tmpOutput;

				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				GetPrivateProfileString(realSecName, "head", "ERROR", headLP, 50, SORTLIST_INI_PATH);
				GetPrivateProfileString(realSecName, "output", "ERROR", outputLP, 50, SORTLIST_INI_PATH);

				SplitVectorStringPlus(headVec, headLP);
				SplitVectorStringPlus(outputVec, outputLP);

				VectorIntToListNode(headVec, headList);
				VectorIntToListNode(outputVec, outputList);

				tmp = SortList(&headList);
				tmpOutput = &outputList;
				while (tmp != NULL)
				{
					Assert::AreEqual(tmp->val, tmpOutput->val);
					tmp = tmp->next;
					tmpOutput = tmpOutput->next;
				}
			}
		}

	};
}