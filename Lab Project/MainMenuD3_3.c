/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.3.
void showMenuD3_3(void)
{
	int i;
	int numberOfMenu;
	int menuOptions;

	do
	{
		printHeader("D3.3. Rainfall database manager - Remove a Rainfall category.");

		if (rainfallCategoryListCount() == 1)
		{
			puts("Not enough rainfall category to remove.\nFor safety reason, you are not allowed to remove the last category.");
			pause();
			break;
		}

		printf("Please select the Category List from options 1 to %d that you want to remove.\n", rainfallCategoryListCount());

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
			rainfallNameListRemoveAt(menuOptions - 1);
			rainfallArrayListRemoveAt(menuOptions - 1);
			rainfallActiveListRemoveAt(menuOptions - 1);

			puts("Successfully removed the selected category!");
		}
		else
		{
			break;
		}

		pause();
	} while (menuOptions != numberOfMenu);
}