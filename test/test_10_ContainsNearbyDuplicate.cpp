#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "10_ContainsNearbyDuplicate.h"
#include "test_Function.h"

#define CONTAINSNEARBYDUPLICATE_INI_PATH "../code/config/10_ContainsNearbyDuplicate.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod10_ContainsNearbyDuplicate)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, CONTAINSNEARBYDUPLICATE_INI_PATH);
			//Assert::AreEqual(6,secNum);

			LPTSTR arrayLP = (LPTSTR)malloc(40);
			int keyNum;
			LPTSTR outputLP = (LPTSTR)malloc(40);

			LPCSTR realSecName;
			CString secTag;

			vector<int> arrayVec;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Array", "ERROR", arrayLP, 40, CONTAINSNEARBYDUPLICATE_INI_PATH);
				keyNum = GetPrivateProfileInt(realSecName, "Key", 0, CONTAINSNEARBYDUPLICATE_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputLP, 40, CONTAINSNEARBYDUPLICATE_INI_PATH);

				SplitVectorStringPlus(arrayVec, arrayLP);
				bool assert = ContainsNearbyDuplicate(arrayVec, keyNum);
				if (assert == 0)
				{
					Assert::AreEqual("false", outputLP);
				}
				else
				{
					Assert::AreEqual("true", outputLP);
				}
				arrayVec.clear();
			}
		}

	};
}