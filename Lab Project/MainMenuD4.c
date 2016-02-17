/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show Menu D4 question.
void displayMenuD4(void)
{
	printHeader("D4. Rainfall database manager - Import/Export database.");
	puts("Please select an option:");
	puts("1. Import database.");
	puts("2. Export database.");
	puts("3. Sync database with internet server.");
	puts("4. Open database directory.");
	puts("5. Go back to Rainfall database manager menu.");
	printHash();
}

// A function to show menu D4.
void showMenuD4(void)
{
	int menuOptions;
	char tempString[CMD_MAX + 1] = "start explorer.exe select,\"";

	stringConcat(tempString, getcwd('\0', 0), "\\Database\"", NULL);

	displayMenuD4();

	do
	{
		menuOptions = scanInt();

		switch (menuOptions)
		{
			case 1:
				showMenuD4_1();
				displayMenuD4();
				break;

			case 2:
				showMenuD4_2();
				displayMenuD4();
				break;

			case 3:
				showMenuD4_3();
				displayMenuD4();
				break;

			case 4:
				// In case directory doesn't exist, we create first.
				mkdir("Database");
				system(tempString);
				break;

			case 5:
				break;

			default:
				puts("\tInvalid option. Please try again!");
		}
	} while (menuOptions != 5);
}