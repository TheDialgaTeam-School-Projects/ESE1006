/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.1.
void showMenuD3_1(void)
{
	int menuCount;
	int i;
	int menuOptions;
	string input;

	do
	{
		printHeader("D3.1. Rainfall database manager - Add a Rainfall category.");
		printf("Please select the Category List from options 1 to %d that you want to add into.\n", rainfallCategoryListCount());

		menuCount = 1;

		for (i = 0; i < rainfallCategoryListCount(); i++)
		{
			printf("%d. %s\n", menuCount, rainfallCategoryListGetItem(i));
			menuCount++;
		}

		printf("%d. - Add a new entry here -.\n", menuCount);
		printf("%d. Go back to Rainfall database manager menu.\n", menuCount + 1);
		printHash();

		menuCount++;

		menuOptions = scanInt();

		if (menuOptions < 1 || menuOptions > menuCount)
			puts("\tInvalid option. Please try again!");
		else if (menuOptions < menuCount - 1)
		{
			puts("Please enter the name of the category:");

			input = scanString(1);
			rainfallCategoryListInsert(menuOptions - 1, input);
			stringDispose(input);
			
			puts("Successfully added into the category list!");
		}
		else if (menuOptions == menuCount - 1)
		{
			puts("Please enter the name of the category:");

			input = scanString(1);
			rainfallCategoryListAdd(input);
			stringDispose(input);

			puts("Successfully added into the category list!");
		}
		else
			break;

		pause();
	} while (menuOptions != menuCount);
}