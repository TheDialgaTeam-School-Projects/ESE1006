/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu F.
void displayMenuF(int* menuCount)
{
	int i;
	int expectedRainfallCategoryListCount = rainfallCategoryListCount();

	printHeader("Display the month with the lowest/highest average rainfall and the values for all months.");
	printf("Please select the category list from options 1 to %d that you want to display.\n", expectedRainfallCategoryListCount);

	*menuCount = 1;

	for (i = 0; i < expectedRainfallCategoryListCount; i++)
	{
		printf("%d. %s\n", *menuCount, rainfallCategoryListGetItem(i));
		*menuCount = *menuCount + 1;
	}

	printf("%d. Go back to main menu.\n", *menuCount);
	printHash();
}

// A function to show menu F.
void displayMenuFYear(int* menuCount, int categoryIndex, int* yearRefIndex)
{
	int year;
	int expectedRainfallYearListCount = rainfallYearListCount(categoryIndex);

	printHeader("F. Display the month with the lowest/highest average rainfall and the values for all months.");
	printf("Please select the year from options 1 to %d that you want to display.\n", expectedRainfallYearListCount);

	*menuCount = 1;

	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		if (rainfallMonthListCount(categoryIndex, year) > 0)
		{
			printf("%d. %d\n", *menuCount, year + START_YEAR);
			yearRefIndex[*menuCount - 1] = year;
			*menuCount = *menuCount + 1;
		}
	}

	printf("%d. Go back to category list selection.\n", *menuCount);
	printHash();
}

// A function to show menu F.
void showMenuF(void)
{
	int menuCount;
	int menuOptions;

	displayMenuF(&menuCount);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuFYear(menuOptions - 1);
			displayMenuF(&menuCount);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu F.
void showMenuFYear(int categoryIndex)
{
	int menuCount;
	int yearRefIndex[END_YEAR - START_YEAR + 1];
	int menuOptions;

	displayMenuFYear(&menuCount, categoryIndex, yearRefIndex);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuFMonth(categoryIndex, yearRefIndex[menuOptions - 1]);
			displayMenuFYear(&menuCount, categoryIndex, yearRefIndex);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu F.
void showMenuFMonth(int categoryIndex, int yearIndex)
{
	int month;
	int day;
	int expectedRainfallDayListCount;

	float total;
	float averageRainfall[12];

	float highestRainfall = 0;
	int highestMonth;

	float lowestRainfall = INT_MAX;
	int lowestMonth;

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

			if (highestRainfall < averageRainfall[month])
			{
				highestRainfall = averageRainfall[month];
				highestMonth = month + 1;
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
	printf("The month with the highest average rainfall is %s (%.1f mm).\n", getMonthName(highestMonth), highestRainfall);

	pause();
}