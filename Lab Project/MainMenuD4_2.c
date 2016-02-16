/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D4.2.
void showMenuD4_2(void)
{
	FILE* file;
	char filename[CMD_MAX + 1];

	int i;
	int year;
	int month;
	int day;
	float expectedRainfall;

	printHeader("D4.2. Rainfall database manager - Export database.");

	if (mkdir("Database") == 0)
		printf("> Created a folder at: %s%s\n", WORKING_DIR, "\\Database");
	else
		puts("> Directory existed, skipping.");

	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		// Get filename.
		stringCopy(filename, "Database\\", rainfallCategoryListGetItem(i), ".csv", NULL);

		// Create a file. Give writing permission.
		file = fopen(filename, "w+");
		
		fputs("Category,Year,Month,Day,Daily Rainfall Total (mm)\n", file);
		fflush(file);

		printf("> Exporting database (%d / %d) %.2f%%\n", i + 1, rainfallCategoryListCount(), (i + 1) / rainfallCategoryListCount() * 100.0);

		for (year = 0; year < rainfallYearListGetCapacity(); year++)
		{
			for (month = 0; month < rainfallMonthListGetCapacity(); month++)
			{
				for (day = 0; day < rainfallDayListGetCapacity(); day++)
				{
					expectedRainfall = rainfallDayListGetItem(i, year, month, day);

					if (expectedRainfall != -1)
					{
						fprintf(file, "%s,%d,%d,%d,%.1f\n", rainfallCategoryListGetItem(i), START_YEAR + year, month + 1, day + 1, expectedRainfall);
						fflush(file);
					}
				}
			}
		}
		
		fclose(file);
	}

	printf("> Database exported at: %s%s\n", WORKING_DIR, "\\Database");
	pause();
}