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
	int numberOfMenu;
	int menuOptions;
	int nameRefIndex;
	int monthRef[12];
	int selectedMonth;
	
MainMenu:
	printHeader("D1. Rainfall database manager - View Rainfall database.");
	printf("Please select the Category List from options 1 to %d that you want to display.\n", rainfallCategoryListCount());

	numberOfMenu = 1;

	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		printf("%d. %s\n", numberOfMenu, rainfallCategoryListGetItem(i));
		numberOfMenu++;
	}
	
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
			nameRefIndex = menuOptions - 1;
			numberOfMenu = 1;

			printHeader("D1. Rainfall database manager - View Rainfall database.");
			printf("Please select the month from options 1 to %d that you want to display.\n", rainfallActiveListCount(nameRefIndex));

			for (i = 0; i < rainfallActiveListCount(nameRefIndex); i++)
			{
				if (rainfallActiveListGetItem(nameRefIndex, i) == true)
				{
					printf("%d. %s\n", numberOfMenu, getMonthName(i + 1));
					monthRef[numberOfMenu - 1] = i + 1;
					numberOfMenu++;
				}
			}

			printf("%d. Go back to category selection.\n", numberOfMenu);
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

					printf("Rainfalls at %s:\n", getMonthName(selectedMonth));

					for (i = 0; i < rainfallArrayListCount(nameRefIndex, selectedMonth - 1); i++)
					{
						printf("%7.1f", rainfallArrayListGetItem(nameRefIndex, selectedMonth - 1, i));

						if ((i == 10 - 1 || i == 20 - 1 || i == 30 - 1) && i != rainfallArrayListCount(nameRefIndex, selectedMonth - 1) - 1)
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

			goto MainMenu;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}