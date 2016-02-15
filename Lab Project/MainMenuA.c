/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show Menu A.
void displayMenuA(int* menuCount, int categoryIndex, int yearIndex, int* monthRefIndex)
{
	int month;

	printHeader("A. Display the average rainfall of a selected month.");
	printf("Please select the month from options 1 to %d that you want to display.\n", rainfallMonthListCount(categoryIndex, yearIndex));

	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		if (rainfallDayListCount(categoryIndex, yearIndex, month) > 0)
		{
			printf("%d. %s\n", *menuCount, getMonthName(month + 1));
			monthRefIndex[*menuCount - 1] = month;
			*menuCount++;
		}
	}

	printf("%d. Go back to main menu.\n", *menuCount);
	printHash();
}

// A function to show Menu A.
void showMenuA(void)
{
	int menuCount = 1;
	int categoryIndex = 0;
	int yearIndex = 2014 - START_YEAR;
	int monthRefIndex[12];

	int menuOptions;
	int selectedMonth;
	int expectedRainfallDayListCount;
	int day;

	float total;
	float average;

	displayMenuA(&menuCount, categoryIndex, yearIndex, monthRefIndex);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			selectedMonth = monthRefIndex[menuOptions - 1];
			expectedRainfallDayListCount = rainfallDayListCount(categoryIndex, yearIndex, selectedMonth);

			total = 0;

			for (day = 0; day < expectedRainfallDayListCount; day++)
			{
				total += rainfallDayListGetItem(categoryIndex, yearIndex, selectedMonth, day);
			}

			average = total / expectedRainfallDayListCount;
			printf("The average rainfall for %s is %.1f mm.\n", getMonthName(selectedMonth + 1), average);
		}
		else
			break;
	} while (menuOptions != menuCount);
}
