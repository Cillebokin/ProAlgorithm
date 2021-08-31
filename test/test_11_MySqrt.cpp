#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "11_MySqrt.h"
#include "test_Function.h"

#define MYSQRT_INI_PATH "../code/config/11_MySqrt.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod11_MySqrt)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, MYSQRT_INI_PATH);
			//Assert::AreEqual(secNum, 6);
			
			int inputNum;
			int outputNum;
			LPCSTR realSecName;
			CString secTag;
			int sqrtNum;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				inputNum = GetPrivateProfileInt(realSecName, "Input", -123, MYSQRT_INI_PATH);
				outputNum = GetPrivateProfileInt(realSecName, "Output", -123, MYSQRT_INI_PATH);

				sqrtNum = MySqrt(inputNum);
				Assert::AreEqual(sqrtNum, outputNum);
			}
		}

	};
}