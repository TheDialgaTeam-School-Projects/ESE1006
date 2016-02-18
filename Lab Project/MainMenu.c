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
	puts("Please select an option.\n");

	puts("For options A to C, additional category is not supported.");
	puts("A. Display the average rainfall of a selected month.");
	puts("B. Display the maximum rainfalls among all the months.");
	puts("C. Display the month with the lowest average rainfall and the values for all months.\n");

	puts("D. Rainfall database manager. (Require Password for first session)\n");

	puts("For options E to F, additional features are supported.");
	puts("E. Display the maximum rainfall among all the months.");
	puts("F. Display the month with the lowest/highest average rainfall and the average for all months.\n");

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

			case 'E':
			case 'e':
				showMenuE();
				displayMenu();

			case 'F':
			case 'f':
				showMenuF();
				displayMenu();

			case 'Q':
			case 'q':
				break;

			default:
				puts("\tInvalid option. Please try again!");
		}
	} while (menuOptions != 'Q' && menuOptions != 'q');
}