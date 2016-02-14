/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D1.
void showMenuD1(void)
{
	int i;
	int menuOptions;
	int numberOfMenu = 0;
	int expectedCount = rainfallCategoryListCount();

MainMenu:
	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the category list from options 1 to %d that you want to display.\n", expectedCount);

	for (i = 0; i < expectedCount; i++)
	{
		printf("%d. %s\n", numberOfMenu + 1, rainfallCategoryListGetItem(i));
		numberOfMenu++;
	}

	numberOfMenu++;
	printf("%d. Go back to Rainfall database manager menu.\n", numberOfMenu);
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
			showMenuD1Year(menuOptions - 1);
			numberOfMenu = 0;
			goto MainMenu;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}

// A function to show menu D1.
void showMenuD1Year(int categoryIndex)
{
	int i;
	int j;
	int menuOptions;
	int expectedCount = 0;
	int numberOfMenu = 0;
	int yearRefIndex[END_YEAR - START_YEAR + 1];


	for (i = 0; i < END_YEAR - START_YEAR + 1; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (rainfallActiveListGetItem(categoryIndex, i, j) == true)
			{
				expectedCount += 1;
				break;
			}
		}
	}

MainMenu1:
	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the year from options 1 to %d that you want to display.\n", expectedCount);

	for (i = 0; i < END_YEAR - START_YEAR + 1; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (rainfallActiveListGetItem(categoryIndex, i, j) == true)
			{
				printf("%d. %d\n", numberOfMenu + 1, i + START_YEAR);
				yearRefIndex[numberOfMenu] = i;
				numberOfMenu++;
				break;
			}
		}
	}

	numberOfMenu++;
	printf("%d. Go back to category list selection.\n", numberOfMenu);
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
			showMenuD1Month(categoryIndex, yearRefIndex[menuOptions - 1]);
			numberOfMenu = 0;
			goto MainMenu1;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}

// A function to show menu D1.
void showMenuD1Month(int categoryIndex, int yearIndex)
{
	int i;
	int menuOptions;
	int selectedMonth;
	int expectedCount = rainfallActiveListCount(categoryIndex, yearIndex);
	int numberOfMenu = 0;
	int monthRefIndex[12];

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