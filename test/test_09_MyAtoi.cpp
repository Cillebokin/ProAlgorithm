#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "09_MyAtoi.h"
#include "test_Function.h"

#define MYATOI_INI_PATH "../code/config/09_MyAtoi.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod09_MyAtoi)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, MYATOI_INI_PATH);
			//Assert::AreEqual(secNum, 4);

			LPTSTR inputLP = (LPTSTR)malloc(40);
			int outputLP;
			LPCSTR realSecName;
			CString secTag;
			int atoiNum;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input", "ERROR", inputLP, 40, MYATOI_INI_PATH);
				outputLP = GetPrivateProfileInt(realSecName, "Output", 0, MYATOI_INI_PATH);

				atoiNum = MyAtoi(inputLP);
				Assert::AreEqual(atoiNum, outputLP);
			}

		}

	};
}