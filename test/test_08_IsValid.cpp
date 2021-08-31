#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "08_IsValid.h"

#define ISVALID_INI_PATH "../code/config/08_IsValid.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod08_IsValid)
		{
			int secNum = GetPrivateProfileInt("Number", "num", -1, ISVALID_INI_PATH);
			//Assert::AreEqual(secNum, 5);

			LPTSTR inputStr = (LPTSTR)malloc(20);
			int outputStr;
			LPCSTR realSecName;
			CString secTag;
			bool assertValid;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				GetPrivateProfileString(realSecName, "Input", "ERROR", inputStr, 20, ISVALID_INI_PATH);
				outputStr = GetPrivateProfileInt(realSecName, "Output", 0, ISVALID_INI_PATH);

				assertValid = IsValid(inputStr);
				if (assertValid)
					Assert::AreEqual(outputStr, 1);
				else
					Assert::AreEqual(outputStr, 0);

			}
		}

	};
}