#include "../include/06_ExcelSheetColumnTitle.h"


string ExcelSheetColumnTitle(int n)
{
	if (n <= 0)
		return "";
	else
	{
		string columnTitle;
		string tmpStr;
		/*if (n < 1 || n > 16384)
		return "";*/

		int mod;
		while (n > 0)
		{
			n = n - 1;
			mod = (n) % 26;

			mod += 65;

			tmpStr = mod;
			columnTitle = tmpStr + columnTitle;

			n = (n) / 26;
		}

		return  columnTitle;
	}
	
}