#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "19_HasAllCodes.h"
#include "test_Function.h"

#define HASALLCODES_INI_PATH "../code/config/19_HasAllCodes.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod19_HasAllCodes)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, HASALLCODES_INI_PATH);
			//Assert::AreEqual(secNum, 6);

			LPTSTR sLP = (LPTSTR)malloc(50);
			int kLP;
			LPTSTR outputLP = (LPTSTR)malloc(50);

			CString secTag;
			LPCSTR realSecName;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "s", "ERROR", sLP, 50, HASALLCODES_INI_PATH);
				kLP = GetPrivateProfileInt(realSecName, "k", 0, HASALLCODES_INI_PATH);
				GetPrivateProfileString(realSecName, "output", "ERROR", outputLP, 50, HASALLCODES_INI_PATH);

				CString tmpStr;
				tmpStr.Format(_T("%s"), sLP);
				bool assert = HasAllCodes(tmpStr.GetBuffer(0), kLP);
				if (assert == 1)
				{
					Assert::AreEqual("true", outputLP);
				}
				else
				{
					Assert::AreEqual("false", outputLP);
				}
			}
		}

	};
}