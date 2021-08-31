#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "06_ExcelSheetColumnTitle.h"

#define EXCELSHEETCOLUMNTITLE_INI_PATH "../code/config/06_ExcelSheetColumnTitle.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod06_ExcelSheetColumnTitle)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, EXCELSHEETCOLUMNTITLE_INI_PATH);
			CString secTag;
			LPCSTR realSecName;
			int inputNum;
			CString outputNum;
			string numStr;
			CString tmpNumStr;
			LPSTR assertNumStr;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				inputNum = GetPrivateProfileInt(realSecName, "Input", 0, EXCELSHEETCOLUMNTITLE_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputNum.GetBuffer(), 8, EXCELSHEETCOLUMNTITLE_INI_PATH);
				//Assert::AreEqual(outputNum, "");

				numStr = ExcelSheetColumnTitle(inputNum);
				tmpNumStr.Format("%s", numStr.c_str());
				assertNumStr = (LPSTR)(LPCSTR)tmpNumStr;
				Assert::AreEqual(assertNumStr, outputNum);

			}
		}

	};
}