#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "07_AddBinary.h"

#define ADDBINARY_INI_PATH "../code/config/07_AddBinary.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod07_AddBinary)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, ADDBINARY_INI_PATH);
			//Assert::AreEqual(secNum, 4);

			LPTSTR input1Str = (LPTSTR)malloc(20);
			LPTSTR input2Str = (LPTSTR)malloc(20);
			LPTSTR outputStr = (LPTSTR)malloc(20);
			LPCSTR realSecName;
			CString secTag;
			string tmpStrAll;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				GetPrivateProfileString(realSecName, "Input1", "ERROR", input1Str, 20, ADDBINARY_INI_PATH);
				GetPrivateProfileString(realSecName, "Input2", "ERROR", input2Str, 20, ADDBINARY_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputStr, 20, ADDBINARY_INI_PATH);

				tmpStrAll = AddBinary(input1Str, input2Str);
				CString tmp = tmpStrAll.c_str();
				Assert::AreEqual(tmp, outputStr);
			}

		}

	};
}