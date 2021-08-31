#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>

#include "03_MoveZeroes.h"
#include "test_Function.h"

#define MOVEZEROES_INI_PATH "../code/config/03_MoveZeroes.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod03_MoveZeroes)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, MOVEZEROES_INI_PATH);
			//Assert::AreEqual(secNum, 4);
			
			CString secTag;
			LPCTSTR realSecName;
			LPTSTR inputNum = (LPTSTR)malloc(20);
			LPTSTR outputNum = (LPTSTR)malloc(20);
			vector<int> inputVec;
			vector<int>::iterator inputIt;
			vector<int> outputVec;
			vector<int>::iterator outputIt;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;
				GetPrivateProfileString(realSecName, "Input", "ERROR", inputNum, 20, MOVEZEROES_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputNum, 20, MOVEZEROES_INI_PATH);
				//Assert::AreEqual(inputNum, "12030");
				//Assert::AreEqual(outputNum, "12300");

				SplitVectorString(inputVec, inputNum);
				MoveZeroes(inputVec);

				SplitVectorString(outputVec, outputNum);


				for (inputIt = inputVec.begin(), outputIt = outputVec.begin(); inputIt != inputVec.end(); inputIt++, outputIt++)
				{
					Assert::AreEqual(*inputIt, *outputIt);
				}
				inputVec.clear();
				outputVec.clear();
			}
		}
	};
}