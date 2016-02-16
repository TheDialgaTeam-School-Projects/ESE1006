/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.2.
void showMenuD3_2(void)
{
	int expectedRainfallCategoryListCount = rainfallCategoryListCount();
	int menuCount;
	int i;
	int menuOptions;

	do
	{
		printHeader("D3.2. Rainfall database manager - Rename a Rainfall category.");
		printf("Please select the Category List from options 1 to %d that you want to rename.\n", expectedRainfallCategoryListCount);

		menuCount = 1;

		for (i = 0; i < expectedRainfallCategoryListCount; i++)
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
			puts("Please enter the name of the category:");
			
			rainfallCategoryListSetItem(menuOptions - 1, scanString(1));

			puts("Successfully renamed the selected category!");
		}
		else
			break;

		pause();
	} while (menuOptions != menuCount);
}