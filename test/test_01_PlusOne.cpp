#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "01_PlusOne.h"
#include "test_Function.h"

#define PLUSONE_INI_PATH "../code/config/01_PlusOne.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod01_PlusOne)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, PLUSONE_INI_PATH);
			vector<int> numVecBefore;
			vector<int> numVecAfter;
			CString secTag;
			LPCSTR realSecName;
			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				int num = GetPrivateProfileInt(realSecName, "Input", -1, PLUSONE_INI_PATH);
				int sum = GetPrivateProfileInt(realSecName, "Output", -1, PLUSONE_INI_PATH);

				SplitVector(numVecBefore, num);
				SplitVector(numVecAfter, sum);

				PlusOne(numVecBefore);
				vector<int>::iterator itBefore, itAfter;
				for (itBefore = numVecBefore.begin(), itAfter = numVecAfter.begin(); itAfter != numVecAfter.end(); itBefore++, itAfter++)
				{
					Assert::AreEqual(*itBefore, *itAfter);
				}
				numVecBefore.clear();
				numVecAfter.clear();
			}
		}

	};
}