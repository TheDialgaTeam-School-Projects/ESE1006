/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Whether the session is validated.
bool sessionValidated = false;

// A function to validate the session.
void validateSession(void)
{
	int i;
	int wrongAttempt;
	
	string currentPassword;

	if (!sessionValidated)
	{
		wrongAttempt = 0;

		do
		{
			puts("Session is not validated, please enter the password:");
			currentPassword = scanString(2);
			sessionValidated = true;

			for (i = 0; i < strlen(SYSTEM_PASSWORD); i++)
			{
				if (currentPassword[i] != SYSTEM_PASSWORD[i] || strlen(currentPassword) != strlen(SYSTEM_PASSWORD))
				{
					puts("\nWrong Password. Please try again.\n");
					sessionValidated = false;
					break;
				}
			}

			if (!sessionValidated && wrongAttempt < 4)
			{
				wrongAttempt++;
			}
			else
			{
				break;
			}
		} while (!sessionValidated);
	}
}

// A function to show main menu question.
void displayMenuD(void)
{
	printHeader("D. Rainfall database manager.");
	puts("Please select an option.");
	puts("1. View Rainfall database.");
	puts("2. Manage Rainfall data.");
	puts("3. Manage Rainfall category.");
	puts("4. Import/Export database.");
	puts("5. Go back to main menu.");
	printHash();
}

// A function to show menu D.
void showMenuD(void)
{
	int menuOptions;

	printHeader("D. Rainfall database manager.");
	validateSession();

	if (sessionValidated)
	{
		displayMenuD();

		do
		{
			menuOptions = scanInt();

			switch (menuOptions)
			{
				case 1:
					showMenuD1();
					displayMenuD();
					break;

				case 2:
					showMenuD2();
					displayMenuD();
					break;

				case 3:
					showMenuD3();
					displayMenuD();
					break;

				case 4:
					showMenuD4();
					displayMenuD();
					break;

				case 5:
					break;

				default:
					puts("\tInvalid option. Please try again!");
			}
		} while (menuOptions != 5);
	}
	else
	{
		puts("Too many wrong attempts. Please try again later.");
		pause();
	}
}