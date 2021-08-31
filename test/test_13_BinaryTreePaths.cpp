#include "stdafx.h"
#include "CppUnitTest.h"

#include <windows.h>
#include <atlstr.h>
#include <vector>
#include <queue>

#include "13_BinaryTreePaths.h"
#include "test_Function.h"

#define BINARYTREEPATHS_INI_PATH "../code/config/13_BinaryTreePaths.ini"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod13_BinaryTreePaths)
		{
			// TODO:  在此输入测试代码
			int secNum = GetPrivateProfileInt("Number", "num", -1, BINARYTREEPATHS_INI_PATH);
			//Assert::AreEqual(2, secNum);

			LPTSTR inputLP = (LPTSTR)malloc(50);
			LPTSTR outputLP = (LPTSTR)malloc(50);

			CString secTag;
			LPCSTR realSecName;

			std::vector<std::string> digits;
			std::vector<std::string> paths;

			for (int i = 0; i < secNum; i++)
			{
				secTag.Format(_T("%d"), i);
				realSecName = "Example" + secTag;

				GetPrivateProfileString(realSecName, "Input", "ERROR", inputLP, 50,BINARYTREEPATHS_INI_PATH);
				GetPrivateProfileString(realSecName, "Output", "ERROR", outputLP, 50, BINARYTREEPATHS_INI_PATH);
			
				//Assert::AreEqual("1,2,null,3", inputLP);
				//Assert::AreEqual("1->2->3", outputLP);

				CString tmpOutputCstr;
				tmpOutputCstr.Format(_T("%s"), outputLP);
				tmpOutputCstr = "\"" + tmpOutputCstr + "\"";
				outputLP = (LPTSTR)(LPCTSTR)tmpOutputCstr;
				//Assert::AreEqual(outputLP, "\"1->2->3\"");

				CreateFloorBinaryTreePreWork(digits, inputLP);
				TreeNode* T = CreateFloorBinaryTree2(digits, 0);

				paths = BinaryTreePaths(T);

				CString outputAll;
				CString tmpOutput;
				for (int i = 0; i < paths.size(); i++)
				{
					tmpOutput = "\"";
					tmpOutput += paths[i].c_str();
					tmpOutput += "\"";
					tmpOutput += ",";
					outputAll += tmpOutput;
				}
				outputAll = outputAll.Left(outputAll.GetLength() - 1);
				LPTSTR outputAllLP = (LPTSTR)(LPCTSTR)outputAll;

				Assert::AreEqual(outputLP, outputAll);

				paths.clear();
				digits.clear();
				FreeBinaryTree(T);
			}
		}
	};
}