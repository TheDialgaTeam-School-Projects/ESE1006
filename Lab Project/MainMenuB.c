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
	int expectedRainfallArrayCount;

	float expectedRainfall;
	float highestRainfall = 0;

	printHeader("B. Display the maximum rainfalls among all the months.");

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(0, 2014 - START_YEAR, i) == true)
		{
			expectedRainfallArrayCount = rainfallArrayListCount(0, 2014 - START_YEAR, i);

			// Algorithm to get the highest rainfall value and its day.
			for (j = 0; j < expectedRainfallArrayCount; j++)
			{
				expectedRainfall = rainfallArrayListGetItem(0, 2014 - START_YEAR, i, j);
				
				if (highestRainfall < expectedRainfall)
				{
					highestDay = j + 1;
					highestRainfall = expectedRainfall;
				}
			}

			printf("The maximum rainfall for %s is %.1f mm on %d %s.\n", getMonthName(i + 1), highestRainfall, highestDay, getMonthName(i + 1));

			highestRainfall = 0;
			highestDay = 0;
		}
	}

	pause();
}
