/*
Name: Yong Jian Ming
Admin No: 1501545F
Class: PE27
*/

#include "Modules.h"

// A function to show menu C.
void showMenuC(void)
{
	int i;
	int j;
	int lowestMonth = 0;
	float lowestRainfall = INT_MAX;

	float averageRainfall[12];
	float total;

	printHeader("C. Display the month with the lowest average rainfall and the value for all months.");

	for (i = 0; i < 12; i++)
	{
		total = 0;

		if (rainfallActiveListGetItem(0, i) == true)
		{
			for (j = 0; j < rainfallArrayListCount(0, i); j++)
			{
				total += rainfallArrayListGetItem(0, i, j);
			}

			averageRainfall[i] = total / rainfallArrayListCount(0, i);

			if (lowestRainfall > averageRainfall[i])
			{
				lowestRainfall = averageRainfall[i];
				lowestMonth = i + 1;
			}
		}
		else
		{
			averageRainfall[i] = -1;
		}
	}

	printf("Average rainfall for the year:\n");
	for (i = 0; i < 12; i++)
	{
		if (averageRainfall[i] != -1)
		{
			printf("%10s %.1fmm\n", getMonthName(i + 1), averageRainfall[i]);
		}
	}

	printf("\nThe month with the lowest average rainfall is %s (%.1fmm).\n", getMonthName(lowestMonth), lowestRainfall);

	pause();
}