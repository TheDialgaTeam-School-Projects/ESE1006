/*
Name: Yong Jian Ming
Admin No: 1501545F
Class: PE27
*/

#include "Modules.h"

// A function to show menu C.
void showMenuC(void)
{
	int categoryIndex = 0;
	int yearIndex = 2014 - START_YEAR;

	int month;
	int day;
	int expectedRainfallDayListCount;
	int lowestMonth = 0;

	float total;
	float averageRainfall[12];
	float lowestRainfall = INT_MAX;

	printHeader("C. Display the month with the lowest average rainfall and the value for all months.");

	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		total = 0;
		expectedRainfallDayListCount = rainfallDayListCount(categoryIndex, yearIndex, month);

		if (expectedRainfallDayListCount > 0)
		{
			for (day = 0; day < expectedRainfallDayListCount; day++)
			{
				total += rainfallDayListGetItem(categoryIndex, yearIndex, month, day);
			}

			averageRainfall[month] = total / expectedRainfallDayListCount;

			if (lowestRainfall > averageRainfall[month])
			{
				lowestRainfall = averageRainfall[month];
				lowestMonth = month + 1;
			}
		}
		else
		{
			averageRainfall[month] = -1;
		}
	}

	printf("Average rainfall for the year:\n");
	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		if (averageRainfall[month] != -1)
		{
			printf("%10s %.1f mm\n", getMonthName(month + 1), averageRainfall[month]);
		}
	}

	printf("\nThe month with the lowest average rainfall is %s (%.1f mm).\n", getMonthName(lowestMonth), lowestRainfall);

	pause();
}