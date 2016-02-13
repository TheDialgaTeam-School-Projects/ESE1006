/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.2.
void showMenuD3_2(void)
{
	int i;
	int numberOfMenu;
	int menuOptions;

	do
	{
		printHeader("D3.2. Rainfall database manager - Rename a Rainfall category.");
		printf("Please select the Category List from options 1 to %d that you want to rename.\n", rainfallCategoryListCount());

		numberOfMenu = 1;

		for (i = 0; i < rainfallCategoryListCount(); i++)
		{
			printf("%d. %s\n", numberOfMenu, rainfallCategoryListGetItem(i));
			numberOfMenu++;
		}

		printf("%d. Go back to Rainfall database manager menu.\n", numberOfMenu);
		printHash();

		numberOfMenu += 1;

		menuOptions = scanInt();

		if (menuOptions > numberOfMenu || menuOptions < 1)
		{
			puts("\tInvalid option. Please try again!");
		}
		else if (menuOptions < numberOfMenu - 1)
		{
			puts("Please enter the name of the category:");
			
			rainfallCategoryListSetItem(menuOptions - 1, scanString(1));

			puts("Successfully renamed the selected category!");
		}
		else
		{
			break;
		}

		pause();
	} while (menuOptions != numberOfMenu);
}