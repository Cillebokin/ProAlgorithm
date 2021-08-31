#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "05_IsPalindrome.h"

#define ISPALINDROME_INI_PATH "../code/config/05_IsPalindrome.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod05_IsPalindrome)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, ISPALINDROME_INI_PATH);
			//Assert::AreEqual(secNum, 4);
			CString secTag;
			LPCSTR realSecName;
			int inputNum, outputNum, num;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				inputNum = GetPrivateProfileInt(realSecName, "Input", 0, ISPALINDROME_INI_PATH);
				outputNum = GetPrivateProfileInt(realSecName, "Output", 0, ISPALINDROME_INI_PATH);

				bool assertNum = IsPalindrome(inputNum);
				if (assertNum == true)
					num = 1;
				else
					num = 0;
				Assert::AreEqual(outputNum, num);
			}
		}

	};
}