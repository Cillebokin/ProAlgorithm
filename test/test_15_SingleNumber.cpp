#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "15_SingleNumber.h"
#include "test_Function.h"

#define SINGLENUMBER_INI_PATH "../code/config/15_SingleNumber.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod15_SingleNumber)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, SINGLENUMBER_INI_PATH);
			//Assert::AreEqual(4,secNum);

			LPTSTR inputLP = (LPTSTR)malloc(50);
			int outputLp;

			LPCSTR realSecName;
			CString secTag;

			vector<int> digits;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input", "ERROR", inputLP, 50, SINGLENUMBER_INI_PATH);
				outputLp = GetPrivateProfileInt(realSecName, "Output", -2147483648, SINGLENUMBER_INI_PATH);
				SplitVectorStringPlus(digits, inputLP);

				int assertNum = SingleNumber(digits);

				Assert::AreEqual(assertNum, outputLp);
				digits.clear();
			}
		}

	};
}