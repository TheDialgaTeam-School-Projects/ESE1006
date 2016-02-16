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
	string expectedCategory;

	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the category list from options 1 to %d that you want to display.\n", expectedRainfallCategoryListCount);

	*menuCount = 1;

	for (i = 0; i < expectedRainfallCategoryListCount; i++)
	{
		expectedCategory = rainfallCategoryListGetItem(i);
		printf("%d. %s\n", *menuCount, expectedCategory);
		stringDispose(expectedCategory);
		*menuCount++;
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

	for (year = 0; year < rainfallYearListCapacity(); year++)
	{
		if (rainfallMonthListCount(categoryIndex, year) > 0)
		{
			printf("%d. %d\n", *menuCount, year + START_YEAR);
			yearRefIndex[*menuCount - 1] = year;
			*menuCount++;
		}
	}

	printf("%d. Go back to category list selection.\n", *menuCount);
	printHash();
}

// A function to show menu D1.
void displayMenuD1Month(int* menuCount, int categoryIndex, int yearIndex, int* MonthRefIndex)
{
	int month;
	int expectedRainfallMonthListCount = rainfallMonthListCount(categoryIndex, yearIndex);

	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the month from options 1 to %d that you want to display.\n", expectedRainfallMonthListCount);

	*menuCount = 1;

	for (month = 0; month < rainfallMonthListCapacity(); month++)
	{
		if (rainfallDayListCount(categoryIndex, yearIndex, month) > 0)
		{
			printf("%d. %d\n", *menuCount, getMonthName(month + 1));
			monthRefIndex[*menuCount - 1] = month;
			*menuCount++;
		}
	}

	printf("%d. Go back to category list selection.\n", *menuCount);
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

	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the month from options 1 to %d that you want to display.\n", expectedCount);

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(categoryIndex, yearIndex, i) == true)
		{
			printf("%d. %s\n", numberOfMenu + 1, getMonthName(i + 1));
			monthRefIndex[numberOfMenu] = i;
			numberOfMenu++;
		}
	}

	numberOfMenu++;
	printf("%d. Go back to year selection.\n", numberOfMenu);
	printHash();

	do
	{
		menuOptions = scanInt();

		if (menuOptions > numberOfMenu || menuOptions < 1)
		{
			puts("\tInvalid option. Please try again!");
		}
		else if (menuOptions < numberOfMenu)
		{
			selectedMonth = monthRefIndex[menuOptions - 1];

			printf("Rainfalls at %s:\n", getMonthName(selectedMonth + 1));

			for (i = 0; i < rainfallArrayListCount(categoryIndex, yearIndex, selectedMonth); i++)
			{
				printf("%7.1f", rainfallArrayListGetItem(categoryIndex, yearIndex, selectedMonth, i));

				if ((i == 10 - 1 || i == 20 - 1 || i == 30 - 1) && i != rainfallArrayListCount(categoryIndex, yearIndex, selectedMonth) - 1)
				{
					printf("\n");
				}
			}

			printf("\n");
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}
