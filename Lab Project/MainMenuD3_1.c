/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.1.
void showMenuD3_1(void)
{
	int i;
	int numberOfMenu;
	int menuOptions;

	string tempString;

	do
	{
		printHeader("D3.1. Rainfall database manager - Add a Rainfall category.");
		printf("Please select the Category List from options 1 to %d that you want to add into.\n", rainfallCategoryListCount());

		numberOfMenu = 1;

		for (i = 0; i < rainfallCategoryListCount(); i++)
		{
			printf("%d. %s\n", numberOfMenu, rainfallCategoryListGetItem(i));
			numberOfMenu++;
		}

		printf("%d. - Add a new entry here -.\n", numberOfMenu);
		printf("%d. Go back to Rainfall database manager menu.\n", numberOfMenu + 1);
		printHash();

		numberOfMenu += 2;

		menuOptions = scanInt();

		if (menuOptions > numberOfMenu || menuOptions < 1)
		{
			puts("\tInvalid option. Please try again!");
		}
		else if (menuOptions < numberOfMenu - 2)
		{
			puts("Please enter the name of the category:");

			tempString = stringConcat(rainfallCategoryListGetItem(menuOptions - 1), "|", scanString(1), NULL);

			rainfallCategoryListSetItem(menuOptions - 1, tempString);
			rainfallArrayListInsert(menuOptions);
			rainfallActiveListInsert(menuOptions);
			
			puts("Successfully added into the category list!");
		}
		else if (menuOptions == numberOfMenu - 2)
		{
			puts("Please enter the name of the category:");

			rainfallNameListAdd(scanString(1));
			rainfallArrayListAdd();
			rainfallActiveListAdd();

			puts("Successfully added into the category list!");
		}
		else
		{
			break;
		}

		pause();
	} while (menuOptions != numberOfMenu);
}