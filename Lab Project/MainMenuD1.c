/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D1.
void displayMenuD1(int* menuCount)
{
	int i;
	int expectedRainfallCategoryListCount = rainfallCategoryListCount();

	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the category list from options 1 to %d that you want to display.\n", expectedRainfallCategoryListCount);

	*menuCount = 1;

	for (i = 0; i < expectedRainfallCategoryListCount; i++)
	{
		printf("%d. %s\n", *menuCount, rainfallCategoryListGetItem(i));
		*menuCount = *menuCount + 1;
	}

	printf("%d. Go back to Rainfall database manager menu.\n", *menuCount);
	printHash();
}

// A function to show menu D1.
void displayMenuD1Year(int* menuCount, int categoryIndex, int* yearRefIndex)
{
	int year;
	int expectedRainfallYearListCount = rainfallYearListCount(categoryIndex);

	printHeader("D1. Rainfall database manager - View Rainfall database.");
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

// A function to show menu D1.
void displayMenuD1Month(int* menuCount, int categoryIndex, int yearIndex, int* monthRefIndex)
{
	int month;
	int expectedRainfallMonthListCount = rainfallMonthListCount(categoryIndex, yearIndex);

	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the month from options 1 to %d that you want to display.\n", expectedRainfallMonthListCount);

	*menuCount = 1;

	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		if (rainfallDayListCount(categoryIndex, yearIndex, month) > 0)
		{
			printf("%d. %s\n", *menuCount, getMonthName(month + 1));
			monthRefIndex[*menuCount - 1] = month;
			*menuCount = *menuCount + 1;
		}
	}

	printf("%d. Go back to year selection.\n", *menuCount);
	printHash();
}

// A function to show menu D1.
void showMenuD1(void)
{
	int menuCount;
	int menuOptions;

	displayMenuD1(&menuCount);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuD1Year(menuOptions - 1);
			displayMenuD1(&menuCount);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu D1.
void showMenuD1Year(int categoryIndex)
{
	int menuCount;
	int yearRefIndex[END_YEAR - START_YEAR + 1];
	int menuOptions;

	displayMenuD1Year(&menuCount, categoryIndex, yearRefIndex);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuD1Month(categoryIndex, yearRefIndex[menuOptions - 1]);
			displayMenuD1Year(&menuCount, categoryIndex, yearRefIndex);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu D1.
void showMenuD1Month(int categoryIndex, int yearIndex)
{
	int menuCount;
	int monthRefIndex[12];
	int menuOptions;
	int monthIndex;
	int day;
	int expectedRainfallDayListCount;

	displayMenuD1Month(&menuCount, categoryIndex, yearIndex, monthRefIndex);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			monthIndex = monthRefIndex[menuOptions - 1];
			expectedRainfallDayListCount = rainfallDayListCount(categoryIndex, yearIndex, monthIndex);

			printf("Rainfalls at %s:\n", getMonthName(monthIndex + 1));

			for (day = 0; day < expectedRainfallDayListCount; day++)
			{
				printf("%7.1f", rainfallDayListGetItem(categoryIndex, yearIndex, monthIndex, day));

				if ((day == 10 - 1 || day == 20 - 1 || day == 30 - 1) && day != expectedRainfallDayListCount - 1)
				{
					printf("\n");
				}
			}

			printf("\n");
		}
		else
			break;
	} while (menuOptions != menuCount);
}