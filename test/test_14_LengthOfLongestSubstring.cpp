#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "14_LengthOfLongestSubstring.h"
#include "test_Function.h"

#define LENGTHOFLONGESTSUBSTRING_INI_PATH "../code/config/14_LengthOfLongestSubstring.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod14_LengthOfLongestSubstring)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, LENGTHOFLONGESTSUBSTRING_INI_PATH);
			//Assert::AreEqual(6,secNum);

			LPTSTR inputLP = (LPTSTR)malloc(50);
			int outputLP;

			LPCSTR realSecName;
			CString secTag;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input", "ERROR", inputLP, 50, LENGTHOFLONGESTSUBSTRING_INI_PATH);
				outputLP = GetPrivateProfileInt(realSecName, "Output", -1, LENGTHOFLONGESTSUBSTRING_INI_PATH);

				CString tmp = CString(inputLP);
				string tmpStr = tmp.GetBuffer(0);

				int num = LengthOfLongestSubstring(tmpStr);
				Assert::AreEqual(num, outputLP);
			}

		}

	};
}