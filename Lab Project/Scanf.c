/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma warning (disable : 4244 )

#include "Modules.h"

/*
	Alternative solution to solve annoying scanf problems.

	char scanChar(void) => Accept A-Z, a-z
	int scanInt(void) => Accept 0-9, -
	string scanString(int Type) => Accept Anything
	float scanFloat(void) => Accept 0-9, -, .
*/

// A function to get keyboard input.
// This function will validate the input before returning as char.
char scanChar(void)
{
	int i;
	bool canReturn;
	char getValue[CMD_MAX + 1];

	do
	{
		for (i = 0; i < sizeof(getValue); i++)
		{
			getValue[i] = '\0';
		}

		canReturn = true;

		printf("> ");
		scanf("%[^\n]", &getValue);
		fflush(stdin);

		for (i = 0; i < sizeof(getValue); i++)
		{
			if (i > 0 && getValue[i] == '\0')
				break;
			else if (i > 0 || !isalpha(getValue[i]))
			{
				puts("\tInvalid input. Only A-Z or a-z is allowed. Please try again!");
				canReturn = false;
				break;
			}
		}
	} while (!canReturn);

	return getValue[0];
}

// A function to get keyboard input.
// This function will validate the input before returning as int.
int scanInt(void)
{
	int i;
	int returnValue;

	bool canReturn;
	bool isNegative;

	char getValue[CMD_MAX + 1];

	do
	{
		for (i = 0; i < sizeof(getValue); i++)
		{
			getValue[i] = '\0';
		}

		returnValue = 0;
		canReturn = true;
		isNegative = false;

		printf("> ");
		scanf("%[^\n]", &getValue);
		fflush(stdin);

		for (i = 0; i < sizeof(getValue); i++)
		{
			if (i > 0 && getValue[i] == '\0')
				break;
			else if (i == 0 && getValue[i] == '-')
				isNegative = true;
			else if ((i > 0 && getValue[i] == '-') || (!isdigit(getValue[i]) && getValue[i] != '-'))
			{
				puts("\tInvalid input. Only 0-9 is allowed. Please try again!");
				canReturn = false;
				break;
			}
			else
				returnValue += returnValue < 1 ? getValue[i] - '0' : returnValue * 10 + getValue[i] - '0' - returnValue;
		}
	} while (!canReturn);

	return isNegative ? returnValue * -1 : returnValue;
}

// A function to get keyboard input.
// This function will validate the input before returning as string.
// Require dispose to be done after use.
string scanString(int Type)
{
	int appendIndex = 0;
	char currentInputChar;
	string tempString = stringInit(CMD_MAX + 1);

	if (Type == 0)
	{
		// Default scanf.
		scanf("%s", tempString);
		fflush(stdin);
	}
	else if (Type == 1)
	{
		// Scan only one line.
		scanf("%[^\n]", tempString);
		fflush(stdin);
	}
	else if (Type == 2)
	{
		// Password.
		do
		{
			currentInputChar = getch();

			if (isalnum(currentInputChar))
			{
				printf("*");
				tempString[appendIndex] = currentInputChar;
				appendIndex++;
			}
			else if (currentInputChar == '\r' || currentInputChar == '\n')
				break;
		} while (appendIndex < CMD_MAX);

		tempString[appendIndex] = '\0';
	}

	return tempString;
}

// A function to get keyboard input.
// This function will validate the input before returning as float.
float scanFloat(void)
{
	int i;
	int decimalAppendIndex;

	bool canReturn;
	bool isDecimal;
	bool isNegative;

	float returnValue;

	char getValue[CMD_MAX + 1];

	do
	{
		for (i = 0; i < sizeof(getValue); i++)
		{
			getValue[i] = '\0';
		}

		decimalAppendIndex = 0;
		returnValue = 0;
		canReturn = true;
		isDecimal = false;
		isNegative = false;

		printf("> ");
		scanf("%[^\n]", &getValue);
		fflush(stdin);

		for (i = 0; i < sizeof(getValue); i++)
		{
			if (i > 0 && getValue[i] == '\0')
				break;
			else if (i == 0 && getValue[i] == '-')
				isNegative = true;
			else if ((i > 0 && getValue[i] == '-') || (i > 0 && getValue[i] == '.' && isDecimal) || (!isdigit(getValue[i]) && getValue[i] != '-' && getValue[i] != '.'))
			{
				puts("\tInvalid input. Only 0-9, \".\", \"-\" is allowed. Please try again!");
				canReturn = false;
				break;
			}
			else if (getValue[i] == '.')
				isDecimal = true;
			else if (!isDecimal)
				returnValue += returnValue < 1 ? getValue[i] - '0' : returnValue * 10 + getValue[i] - '0' - returnValue;
			else if (isDecimal)
			{
				returnValue += (getValue[i] - '0') / pow(10, decimalAppendIndex + 1);
				decimalAppendIndex++;
			}

		}
	} while (!canReturn);

	return isNegative ? returnValue * -1 : returnValue;
}