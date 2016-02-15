/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Create a new instance of String.
string stringInit(int capacity)
{
	string tempString = calloc(capacity, sizeof(char));

	if (tempString == NULL)
	{
		perror("> ERROR: ");
		return NULL;
	}
	else
		return tempString;
}

// Creates a new instance of String with the same value as a specified String.
string stringCopy(string item, ...)
{
	va_list ap;
	int argumentCount = 0;
	string tempArgument;
	bool valid = true;

	va_start(ap, item);

	do
	{
		tempArgument = va_arg(ap, string);

		if (tempArgument == NULL)
			valid = false;
		else if (argumentCount == 0)
		{
			strcpy(item, tempArgument);
			argumentCount++;
		}
		else
		{
			strcat(item, tempArgument);
			argumentCount++;
		}
	} while (valid);

	va_end(ap);

	return item;
}

// Concatenates one or more instances of String, or the String representations of the values of one or more instances of Object.
string stringConcat(string item, ...)
{
	va_list ap;
	string tempArgument;
	bool valid = true;

	va_start(ap, item);

	do
	{
		tempArgument = va_arg(ap, string);

		if (tempArgument == NULL)
			valid = false;
		else
		{
			strcat(item, tempArgument);
		}
	} while (valid);

	va_end(ap);

	return item;
}

// Dispose the string.
void stringDispose(string item)
{
	free(item);
}