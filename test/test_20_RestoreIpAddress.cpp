#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "20_RestoreIpAddress.h"
#include "test_Function.h"

#define RESTOREIPADDRESS_INI_PATH "../code/config/20_RestoreIpAddress.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod20_RestoreIpAddress)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, RESTOREIPADDRESS_INI_PATH);
			//Assert::AreEqual(secNum, 1);

			LPTSTR inputLP = (LPTSTR)malloc(200);
			LPTSTR outputLP = (LPTSTR)malloc(200);

			CString secTag;
			LPCSTR realSecName;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input", "ERROR", inputLP, 200, RESTOREIPADDRESS_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputLP, 200, RESTOREIPADDRESS_INI_PATH);

				CString tmpInputStr, tmpOutputStr;
				tmpInputStr.Format(_T("%s"), inputLP);
				vector<string> outputVec = RestoreIpAddresses(tmpInputStr.GetBuffer(0));
				if (outputVec.size() == 0)
				{
					continue;
				}
				else
				{
					for (int i = 0; i < outputVec.size(); i++)
					{
						tmpOutputStr += "\"";
						tmpOutputStr += outputVec[i].c_str();
						tmpOutputStr += "\",";
					}
				}
				tmpOutputStr = tmpOutputStr.Left(tmpOutputStr.GetLength() - 2);
				tmpOutputStr = tmpOutputStr.Right(tmpOutputStr.GetLength() - 1);
				Assert::AreEqual(outputLP, tmpOutputStr);
			}
		}

	};
}