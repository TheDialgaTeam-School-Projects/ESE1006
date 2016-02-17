/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D4.1.
void showMenuD4_1(void)
{
	FILE* file;
	char filename[CMD_MAX + 1];

	string tempCategoryName;
	string tempLineText = stringInit(CMD_MAX + 1);
	string tempGetSplit;

	int tempYear;
	int tempMonth;
	int tempDay;
	float tempValue;

	bool isCategoryAdded = false;
	bool isFirstLine = false;

	printHeader("D4.1. Rainfall database manager - Import database.");

	if (mkdir("Database") == 0)
		printf("> Created a folder at: %s%s\n", WORKING_DIR, "\\Database");
	else
		puts("> Directory existed, skipping.");

	// Get filename.
	stringCopy(filename, "Database\\Database.csv", NULL);

	// Open the file, give read permission.
	file = fopen(filename, "r");

	// Reset Variable
	isFirstLine = false;
	isCategoryAdded = false;

	if (file == NULL)
	{
		puts("> Unable to find the requested file. Skipping.");
	}
	else
	{
		do
		{
			tempLineText = fgets(tempLineText, INT_MAX, file);

			if (tempLineText == NULL)
				break;
			else
			{
				if (!isFirstLine)
				{
					isFirstLine = true;
					continue;
				}

				if (!isCategoryAdded)
				{
					tempCategoryName = stringGetSplit(tempLineText, 0, ',');
					rainfallCategoryListAdd(tempCategoryName);
					stringDispose(tempCategoryName);
					isCategoryAdded = true;
				}

				tempGetSplit = stringGetSplit(tempLineText, 1, ',');
				tempYear = stringToInt(tempGetSplit);
				stringDispose(tempGetSplit);

				tempGetSplit = stringGetSplit(tempLineText, 2, ',');
				tempMonth = stringToInt(tempGetSplit);
				stringDispose(tempGetSplit);

				tempGetSplit = stringGetSplit(tempLineText, 3, ',');
				tempDay = stringToInt(tempGetSplit);
				stringDispose(tempGetSplit);

				tempGetSplit = stringGetSplit(tempLineText, 4, ',');
				tempValue = stringToFloat(tempGetSplit);
				stringDispose(tempGetSplit);

				rainfallDayListSetItem(rainfallCategoryListCount() - 1, tempYear - START_YEAR, tempMonth - 1, tempDay - 1, tempValue);

				if (getDayCount(tempYear, tempMonth) == tempDay)
					break;
			}
		} while (tempLineText != NULL);
	}

	fclose(file);
	puts("> Database imported!");
	system("pause");
}