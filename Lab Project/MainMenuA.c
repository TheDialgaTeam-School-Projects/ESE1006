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
	int numberOfMenu = 1;
	int monthRef[12];

	int menuOptions;
	int selectedMonth;

	float total = 0;
	float average;

	printHeader("A. Display the average rainfall of a selected month.");
	printf("Please select the month from options 1 to %d that you want to display.\n", rainfallActiveListCount(0));

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(0, i) == true)
		{
			printf("%d. %s\n", numberOfMenu, getMonthName(i + 1));
			monthRef[numberOfMenu - 1] = i + 1;
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
			selectedMonth = monthRef[menuOptions - 1];

			for (i = 0; i < rainfallArrayListCount(0, selectedMonth - 1); i++)
			{
				total += rainfallArrayListGetItem(0, selectedMonth - 1, i);
			}

			average = total / rainfallArrayListCount(0, selectedMonth - 1);
			printf("The average rainfall for %s is %.1fmm.\n", getMonthName(selectedMonth), average);

			total = 0;
			average = 0;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}