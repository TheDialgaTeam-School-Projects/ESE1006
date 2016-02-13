/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show Menu D3 question.
void displayMenuD3(void)
{
	printHeader("D3. Rainfall database manager - Manage Rainfall category.");
	puts("Please select an option:");
	puts("1. Add a Rainfall category.");
	puts("2. Rename a Rainfall category.");
	puts("3. Remove a Rainfall category.");
	puts("4. Reset to factory default.");
	puts("5. Go back to Rainfall database manager menu.");
	printHash();
}

// A function to show menu D3.
void showMenuD3(void)
{
	int menuOptions;

	displayMenuD3();

	do
	{
		menuOptions = scanInt();

		switch (menuOptions)
		{
			case 1:
				showMenuD3_1();
				displayMenuD3();
				break;

			case 2:
				showMenuD3_2();
				displayMenuD3();
				break;

			case 3:
				showMenuD3_3();
				displayMenuD3();
				break;

			case 4:
				showMenuD3_4();
				displayMenuD3();
				break;

			case 5:
				break;

			default:
				puts("\tInvalid option. Please try again!");
		}
	} while (menuOptions != 5);
}