#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "16_WordBreak.h"
#include "test_Function.h"

#define WORDBREAK_INI_PATH "../code/config/16_WordBreak.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod16_WordBreak)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, WORDBREAK_INI_PATH);
			//Assert::AreEqual(4, secNum);

			LPTSTR input1LP = (LPTSTR)malloc(50);
			LPTSTR input2LP = (LPTSTR)malloc(50);
			LPTSTR outputLP = (LPTSTR)malloc(50);

			CString secTag;
			LPCSTR realSecName;

			vector<string> wordDict;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input1", "ERROR", input1LP, 50, WORDBREAK_INI_PATH);
				GetPrivateProfileString(realSecName, "Input2", "ERROR", input2LP, 50, WORDBREAK_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputLP, 50, WORDBREAK_INI_PATH);

				SplitVectorStringPlus(wordDict, input2LP);
				CString tmpStr;
				tmpStr.Format(_T("%s"), input1LP);
				bool assert = WordBreak(tmpStr.GetBuffer(0), wordDict);

				if (assert == 0)
				{
					Assert::AreEqual("false", outputLP);
				}
				else
				{
					Assert::AreEqual("true", outputLP);
				}
				wordDict.clear();
			}
		}

	};
}