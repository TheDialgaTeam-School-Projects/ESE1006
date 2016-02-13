/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu B.
void showMenuB(void)
{
	int i;
	int j;
	int highestDay;
	float highestRainfall = 0;

	printHeader("B. Display the maximum rainfalls among all the months.");

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(0, i) == true)
		{
			// Algorithm to get the highest rainfall value and its day.
			for (j = 0; j < rainfallArrayListCount(0, i); j++)
			{
				if (highestRainfall < rainfallArrayListGetItem(0, i, j))
				{
					highestDay = j + 1;
					highestRainfall = rainfallArrayListGetItem(0, i, j);
				}
			}

			printf("The maximum rainfall for %s is %.1fmm on %d %s.\n", getMonthName(i + 1), highestRainfall, highestDay, getMonthName(i + 1));

			highestRainfall = 0;
			highestDay = 0;
		}
	}

	pause();
}