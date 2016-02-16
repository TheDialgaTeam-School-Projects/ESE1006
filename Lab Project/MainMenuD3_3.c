/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.3.
void showMenuD3_3(void)
{
	int menuCount;
	int i;
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

		menuCount = 1;

		for (i = 0; i < rainfallCategoryListCount(); i++)
		{
			printf("%d. %s\n", menuCount, rainfallCategoryListGetItem(i));
			menuCount++;
		}

		printf("%d. Go back to Rainfall database manager menu.\n", menuCount);
		printHash();

		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount)
		{
			rainfallCategoryListRemoveAt(menuOptions - 1);

			puts("Successfully removed the selected category!");
		}
		else
			break;

		pause();
	} while (menuOptions != menuCount);
}