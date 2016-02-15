/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu B.
void showMenuB(void)
{
	int categoryIndex = 0;
	int yearIndex = 2014 - START_YEAR;

	int month;
	int day;
	int expectedRainfallDayListCount;
	int highestDay;
	
	float expectedRainfall;
	float highestRainfall = 0;

	printHeader("B. Display the maximum rainfalls among all the months.");

	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		expectedRainfallDayListCount = rainfallDayListCount(categoryIndex, yearIndex, month);

		if (expectedRainfallDayListCount > 0)
		{
			// Algorithm to get the highest rainfall value and its day.
			for (day = 0; day < expectedRainfallDayListCount; day++)
			{
				expectedRainfall = rainfallDayListGetItem(categoryIndex, yearIndex, month, day);
				
				if (highestRainfall < expectedRainfall)
				{
					highestDay = day + 1;
					highestRainfall = expectedRainfall;
				}
			}

			printf("The maximum rainfall for %s is %.1f mm on %d %s.\n", getMonthName(month + 1), highestRainfall, highestDay, getMonthName(month + 1));

			highestRainfall = 0;
			highestDay = 0;
		}
	}

	pause();
}
