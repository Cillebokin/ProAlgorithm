#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "04_HammingWeight.h"

#define HAMMINGWEIGHT_INI_PATH "../code/config/04_HammingWeight.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod04_HammingWeight)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, HAMMINGWEIGHT_INI_PATH);
			//Assert::AreEqual(secNum, 4);

			int inputNum, outputNum;
			CString secTag;
			LPCSTR realSecName;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				inputNum = GetPrivateProfileInt(realSecName, "Input", 0, HAMMINGWEIGHT_INI_PATH);
				outputNum = GetPrivateProfileInt(realSecName, "Output", 0, HAMMINGWEIGHT_INI_PATH);

				int num = HammingWeight((unsigned int)inputNum);
				Assert::AreEqual(num, outputNum);
			}

		}

	};
}