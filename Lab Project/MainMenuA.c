/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show Menu A.
void showMenuA(void)
{
	int i;
	int menuOptions;
	int expectedCount;
	int selectedMonth;
	int monthRefIndex[12];
	int monthRefAppendIndex = 0;
	int numberOfMenu = 1;

	float total = 0;
	float average;

	printHeader("A. Display the average rainfall of a selected month.");
	printf("Please select the month from options 1 to %d that you want to display.\n", rainfallActiveListCount(0, 2014 - START_YEAR));

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(0, 2014 - START_YEAR, i) == true)
		{
			printf("%d. %s\n", numberOfMenu, getMonthName(i + 1));
			monthRefIndex[monthRefAppendIndex] = i;
			monthRefAppendIndex++;
			numberOfMenu++;
		}
	}

	printf("%d. Go back to main menu.\n", numberOfMenu);
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
			expectedCount = rainfallArrayListCount(0, 2014 - START_YEAR, selectedMonth);

			for (i = 0; i < expectedCount; i++)
			{
				total += rainfallArrayListGetItem(0, 2014 - START_YEAR, selectedMonth, i);
			}

			average = total / expectedCount;
			printf("The average rainfall for %s is %.1f mm.\n", getMonthName(selectedMonth + 1), average);

			total = 0;
			average = 0;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}