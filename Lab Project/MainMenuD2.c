/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D2.
void displayMenuD2(int* menuCount)
{
	int i;
	int expectedRainfallCategoryCount = rainfallCategoryListCount();

	printHeader("D2. Rainfall database manager - Manage Rainfall data.");
	printf("Please select the category list from options 1 to %d that you want to change.\n", expectedRainfallCategoryCount);

	*menuCount = 1;

	for (i = 0; i < expectedRainfallCategoryCount; i++)
	{
		printf("%d. %s\n", *menuCount, rainfallCategoryListGetItem(i));
		*menuCount++;
	}

	printf("%d. Go back to Rainfall database manager menu.\n", *menuCount);
	printHash();
}

// A function to show menu D2.
void displayMenuD2Year(void)
{
	printHeader("D2. Rainfall database manager - Manage Rainfall data.");
	printf("Please select the year from %d to %d that you want to change.\n", START_YEAR, END_YEAR);

	puts("1. Go back to category list selection.");
	printHash();
}

// A function to show menu D2.
void displayMenuD2Month(int yearIndex, int monthIndex)
{
	int month;

	printHeader("D2. Rainfall database manager - Manage Rainfall data.");
	puts("Please select the month from 1 to 12 that you want to change.");

	for (month = 0; month < 12; month++)
	{
		printf("%d. %s\n", month + 1, getMonthName(month));
	}

	puts("13. Go back to category list selection.");
	printHash();
}

// A function to show menu D2.
void showMenuD2(void)
{
	int menuCount;
	int menuOptions;

	displayMenuD2(&menuCount);

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			showMenuD2Year(menuOptions - 1);
			displayMenuD2(&menuCount);
		}
		else
			break;
	} while (menuOptions != menuCount);
}

// A function to show menu D2.
void showMenuD2Year(int categoryIndex)
{
	int menuOptions;

	displayMenuD2Year();

	do
	{
		menuOptions = scanInt();

		if (menuOptions != 1 && (menuOptions < START_YEAR || menuOptions > END_YEAR))
			puts("\tInvalid option. Please try again!");
		else if (menuOptions != 1)
		{
			showMenuD2Month(categoryIndex, menuOptions - START_YEAR);
			displayMenuD2Year();
		}
		else
			break;
	} while (menuOptions != 1);
}

// A function to show menu D2.
void showMenuD2Month(int categoryIndex, int yearIndex)
{
	int menuOptions;
	int day;
	int input;
	bool validInput;

	do
	{
		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > 13)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions != 13)
		{
			puts("Please insert the amount of rainfall per day. -1 to stop.\n");
			printf("Rainfalls at %s:\n", getMonthName(menuOptions));

			for (day = 0; day < 31; day++)
			{
				validInput = false;

				if (day < getDayCount(START_YEAR + yearIndex, menuOptions))
				{
					do
					{
						printf("Day %d: ", day + 1);
						input = scanFloat();

						if (input < 0 && input != -1)
							puts("\tInvalid value. Please try again.");
						else
						{
							rainfallArrayListSetItem(categoryIndex, yearIndex, menuOptions - 1, i, input);
							validInput = true;
						}
					} while (!validInput);
				}
				else
				{
					rainfallArrayListSetItem(categoryIndex, yearIndex, menuOptions - 1, i, -1);
				}

				if (input == -1)
				{
					break;
				}
			}

			rainfallActiveListSetItem(categoryIndex, yearIndex, menuOptions - 1, rainfallArrayListGetItem(categoryIndex, yearIndex, menuOptions - 1, 0) == -1 ? false : true);
			printf("Successfully changed the rainfall value of %s!\n\n", getMonthName(menuOptions));
		}
		else
		{
			break;
		}
	} while (menuOptions != 13);
}

///*
//	Name: Yong Jian Ming
//	Admin No: 1501545F
//	Class: PE27
//*/
//
//#include "Modules.h"
//
//// A function to show menu D2.
//void showMenuD2(void)
//{
//	int i;
//	int numberOfMenu;
//	int menuOptions;
//	int nameRefIndex;
//	int monthRef[12];
//	int selectedMonth;
//
//	bool validInput;
//	float input;
//
//MainMenu:
//	printHeader("D2. Rainfall database manager - Manage Rainfall data.");
//	printf("Please select the Category List from options 1 to %d that you want to change.\n", rainfallCategoryListCount());
//
//	numberOfMenu = 1;
//
//	for (i = 0; i < rainfallCategoryListCount(); i++)
//	{
//		printf("%d. %s\n", numberOfMenu, rainfallCategoryListGetItem(i));
//		numberOfMenu++;
//	}
//
//	printf("%d. Go back to Rainfall database manager menu.\n", numberOfMenu);
//	printHash();
//
//	do
//	{
//		menuOptions = scanInt();
//
//		if (menuOptions > numberOfMenu || menuOptions < 1)
//		{
//			puts("\tInvalid option. Please try again!");
//		}
//		else if (menuOptions < numberOfMenu)
//		{
//			nameRefIndex = menuOptions - 1;
//			numberOfMenu = 1;
//
//			printHeader("D2. Rainfall database manager - Manage Rainfall data.");
//			printf("Please select the month from options 1 to %d that you want to change.\n", rainfallActiveListDayCount(nameRefIndex));
//
//			for (i = 0; i < 12; i++)
//			{
//				printf("%d. %s\n", numberOfMenu, getMonthName(i + 1));
//				monthRef[numberOfMenu - 1] = i + 1;
//				numberOfMenu++;
//			}
//
//			printf("%d. Go back to category selection.\n", numberOfMenu);
//			printHash();
//
//			do
//			{
//				menuOptions = scanInt();
//
//				if (menuOptions > 13 || menuOptions < 1)
//				{
//					puts("\tInvalid option. Please try again!");
//				}
//				else if (menuOptions < 13)
//				{
//					selectedMonth = menuOptions;
//
//					puts("Please insert the amount of rainfall per day. If that day doesn't exist on that month put -1 to stop.\n");
//					printf("Rainfalls at %s:\n", getMonthName(selectedMonth));
//
//					for (i = 0; i < 31; i++)
//					{
//						validInput = false;
//
//						do
//						{
//							printf("Day %d: ", i + 1);
//							input = scanFloat();
//
//							if (input < 0 && input != -1.0)
//							{
//								puts("\tInvalid value. Please try again.");
//							}
//							else
//							{
//								rainfallArrayListSetItem(nameRefIndex, selectedMonth - 1, i, input);
//								validInput = 1;
//							}
//						} while (!validInput && input != -1);
//
//						if (input == -1)
//						{
//							break;
//						}
//					}
//
//					rainfallActiveListSetItem(nameRefIndex, selectedMonth - 1, rainfallArrayListGetItem(nameRefIndex, selectedMonth - 1, 0) == -1 ? false : true);
//					printf("\n");
//				}
//				else
//				{
//					break;
//				}
//			} while (menuOptions != 13);
//
//			goto MainMenu;
//		}
//		else
//		{
//			break;
//		}
//	} while (menuOptions != numberOfMenu);
//}