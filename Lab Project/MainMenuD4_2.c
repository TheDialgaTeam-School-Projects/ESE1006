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
	char filename[CMD_MAX];

	int i;
	int j;
	int k;

	printHeader("D4.2. Rainfall database manager - Export database.");

	if (mkdir("Database") == 0)
		printf("> Created a folder at: %s%s\n", WORKING_DIR, "\\Database");
	else
		puts("> Directory existed, skipping.");

	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		// Get filename.
		strcpy(filename, "Database\\");
		strcat(filename, rainfallCategoryListGetItem(i));
		strcat(filename, ".csv");

		// Create a file. Give writing permission.
		file = fopen(filename, "w+");
		
		fputs("Category,Month,Day,Daily Rainfall Total (mm)\n", file);
		fflush(file);

		printf("> Exporting database (%d / %d) %.2f%%\n", i + 1, rainfallCategoryListCount(), (i + 1) / rainfallCategoryListCount() * 100.0);

		for (j = 0; j < 12; j++)
		{
			for (k = 0; k < 31; k++)
			{
				if (rainfallArrayListGetItem(i,0, j, k) != -1)
				{
					fprintf(file, "%s,%d,%d,%.1f\n", rainfallCategoryListGetItem(i), j + 1, k + 1, rainfallArrayListGetItem(i,0, j, k));
					fflush(file);
				}
			}
		}
		
		fclose(file);
	}

	printf("> Database exported at: %s%s\n", WORKING_DIR, "\\Database");
	pause();
}