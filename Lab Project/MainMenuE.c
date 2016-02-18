/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu E.
void displayMenuE(int* menuCount)
{
	int i;
	int expectedRainfallCategoryListCount = rainfallCategoryListCount();

	printHeader("E. Display the highest and lowest average rainfall.");
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

// A function to show menu E.
void displayMenuEYear(int* menuCount, int categoryIndex, int* yearRefIndex)
{
	int year;
	int expectedRainfallYearListCount = rainfallYearListCount(categoryIndex);

	printHeader("E. Display the highest and lowest average rainfall.");
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

// A function to show menu E.
void showMenuE(void)
{
	int menuCount;
	int menuOptions;

	displayMenuE(&menuCount);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuEYear(menuOptions - 1);
			displayMenuE(&menuCount);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu E.
void showMenuEYear(int categoryIndex)
{
	int menuCount;
	int yearRefIndex[END_YEAR - START_YEAR + 1];
	int menuOptions;

	displayMenuEYear(&menuCount, categoryIndex, yearRefIndex);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuEMonth(categoryIndex, yearRefIndex[menuOptions - 1]);
			displayMenuEYear(&menuCount, categoryIndex, yearRefIndex);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu E.
void showMenuEMonth(int categoryIndex, int yearIndex)
{
	int month;
	int day;
	int expectedRainfallDayListCount;
	
	float expectedRainfall;
	float highestRainfall = 0;
	int highestDay;

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

			printf("The highest rainfall for %s is %.1f mm on %d %s.\n", getMonthName(month + 1), highestRainfall, highestDay, getMonthName(month + 1));

			highestRainfall = 0;
			highestDay = 0;
		}
	}

	pause();
}