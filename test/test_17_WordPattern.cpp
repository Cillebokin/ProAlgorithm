#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "17_WordPattern.h"
#include "test_Function.h"

#define WORDPATTERN_INI_PATH "../code/config/17_WordPattern.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod17_WordPattern)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, WORDPATTERN_INI_PATH);
			//Assert::AreEqual(secNum, 4);

			LPTSTR patternLP = (LPTSTR)malloc(50);
			LPTSTR strLP = (LPTSTR)malloc(50);
			LPTSTR outputLP = (LPTSTR)malloc(50);

			CString secTag;
			LPCSTR realSecName;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Pattern", "ERROR", patternLP, 50, WORDPATTERN_INI_PATH);
				GetPrivateProfileString(realSecName, "Str", "ERROR", strLP, 50, WORDPATTERN_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputLP, 50, WORDPATTERN_INI_PATH);
			
				CString patternCstr, strCstr;
				patternCstr.Format(_T("%s"), patternLP);
				strCstr.Format(_T("%s"), strLP);
				bool assert = WordPattern(patternCstr.GetBuffer(0), strCstr.GetBuffer(0));
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