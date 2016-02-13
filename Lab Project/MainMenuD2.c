/*
Name: Yong Jian Ming
Admin No: 1501545F
Class: PE27
*/

#include "Modules.h"

// A function to show menu D2.
void showMenuD2(void)
{
	int i;
	int numberOfMenu;
	int menuOptions;
	int nameRefIndex;
	int monthRef[12];
	int selectedMonth;

	bool validInput;
	float input;

MainMenu:
	printHeader("D2. Rainfall database manager - Manage Rainfall data.");
	printf("Please select the Category List from options 1 to %d that you want to change.\n", rainfallCategoryListCount());

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

			printHeader("D2. Rainfall database manager - Manage Rainfall data.");
			printf("Please select the month from options 1 to %d that you want to change.\n", rainfallActiveListCount(nameRefIndex));

			for (i = 0; i < 12; i++)
			{
				printf("%d. %s\n", numberOfMenu, getMonthName(i + 1));
				monthRef[numberOfMenu - 1] = i + 1;
				numberOfMenu++;
			}

			printf("%d. Go back to category selection.\n", numberOfMenu);
			printHash();

			do
			{
				menuOptions = scanInt();

				if (menuOptions > 13 || menuOptions < 1)
				{
					puts("\tInvalid option. Please try again!");
				}
				else if (menuOptions < 13)
				{
					selectedMonth = menuOptions;

					puts("Please insert the amount of rainfall per day. If that day doesn't exist on that month put -1 to stop.\n");
					printf("Rainfalls at %s:\n", getMonthName(selectedMonth));

					for (i = 0; i < 31; i++)
					{
						validInput = false;

						do
						{
							printf("Day %d: ", i + 1);
							input = scanFloat();

							if (input < 0 && input != -1.0)
							{
								puts("\tInvalid value. Please try again.");
							}
							else
							{
								rainfallArrayListSetItem(nameRefIndex, selectedMonth - 1, i, input);
								validInput = 1;
							}
						} while (!validInput && input != -1);

						if (input == -1)
						{
							break;
						}
					}

					rainfallActiveListSetItem(nameRefIndex, selectedMonth - 1, rainfallArrayListGetItem(nameRefIndex, selectedMonth - 1, 0) == -1 ? false : true);
					printf("\n");
				}
				else
				{
					break;
				}
			} while (menuOptions != 13);

			goto MainMenu;
		}
		else
		{
			break;
		}
	} while (menuOptions != numberOfMenu);
}