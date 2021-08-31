#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "02_ReverseBits.h"

#define REVERSEBITS_INI_PATH "../code/config/02_ReverseBits.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod02_ReverseBits)
		{
			// TODO:  在此输入测试代码
			
			int secNum = GetPrivateProfileInt("Number", "num", -1, REVERSEBITS_INI_PATH);

			CString strBefore, strAfter, secTag;
			unsigned int uintBefore;
			unsigned int uintAfter;
			unsigned int uintNum;
			LPCTSTR realSecName;
			LPTSTR lpStrBefore = (LPTSTR)malloc(20);
			LPTSTR lpStrAfter = (LPTSTR)malloc(20);

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), 0);
				realSecName = "Example" + secTag;
				GetPrivateProfileString(realSecName, "Input", "ERROR", lpStrBefore, 20, REVERSEBITS_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", lpStrAfter, 20, REVERSEBITS_INI_PATH);
				//Assert::AreEqual("43261596", lpStrBefore);


				uintBefore = (unsigned int)_ttoi64(lpStrBefore);
				uintAfter = (unsigned int)_ttoi64(lpStrAfter);

				uintNum = ReverseBits(uintBefore);
				Assert::AreEqual(uintNum, uintAfter);
			}
		}

	};
}