/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show Main Menu question.
void displayMenu(void)
{
	printHeader("Rainfall Viewer 1 - Main Menu");
	puts("Please select an option.");
	puts("For options A to C, additional category is not supported.\n");
	puts("A. Display the average rainfall of a selected month.");
	puts("B. Display the maximum rainfalls among all the months.");
	puts("C. Display the month with the lowest average rainfall and the value for all months.");
	puts("D. Rainfall database manager. (Require Password upon first session)");
	puts("Q. Exit.");
	printHash();
}

// A function to show Main Menu.
void showMainMenu(void)
{
	char menuOptions;

	displayMenu();

	do
	{
		menuOptions = scanChar();

		switch (menuOptions)
		{
			case 'A':
			case 'a':
				showMenuA();
				displayMenu();
				break;

			case 'B':
			case 'b':
				showMenuB();
				displayMenu();
				break;

			case 'C':
			case 'c':
				showMenuC();
				displayMenu();
				break;

			case 'D':
			case 'd':
				showMenuD();
				displayMenu();
				break;

			case 'Q':
			case 'q':
				break;

			default:
				puts("\tInvalid option. Please try again!");
		}
	} while (menuOptions != 'Q' && menuOptions != 'q');
}