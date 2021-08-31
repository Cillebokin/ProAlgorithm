#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "18_FindMinFibonacciNumbers.h"
#include "test_Function.h"

#define FINDMINFIBONACCINUMBERS_INI_PATH "../code/config/18_FindMinFibonacciNumbers.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod18_FindMinFibonacciNumbers)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, FINDMINFIBONACCINUMBERS_INI_PATH);
			Assert::AreEqual(6, secNum);

			int inputNum;
			int outputNum;

			CString secTag;
			LPCSTR realSecName;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				inputNum = GetPrivateProfileInt(realSecName, "Input", -2147483648, FINDMINFIBONACCINUMBERS_INI_PATH);
				outputNum = GetPrivateProfileInt(realSecName, "Output", -2147483648, FINDMINFIBONACCINUMBERS_INI_PATH);

				int assertNum = FindMinFibonacciNumbers(inputNum);

				Assert::AreEqual(assertNum, outputNum);

			}
			
		}

	};
}