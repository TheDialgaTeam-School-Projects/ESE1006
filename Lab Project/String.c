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

// Returns the nth index of the splited string after spliting the seperator in the original string.
// Require dispose to be done after use.
string stringGetSplit(string item, int index, char seperator)
{
	int i;
	int expectedIndex = index;
	int expectedCapacity = strlen(item) + 1;
	int currentIndex = 0;
	int currentAppendIndex = 0;
	
	string tempString = stringInit(CMD_MAX + 1);

	if (stringGetSplitCount(item, seperator) == 1)
	{
		stringDispose(tempString);
		return item;
	}
	else if (expectedIndex >= stringGetSplitCount(item, seperator))
	{
		expectedIndex = stringGetSplitCount(item, seperator) - 1;
	}
	
	for (i = 0; i < expectedCapacity; i++)
	{
		if (item[i] == '\0' || currentIndex > expectedIndex)
			break;
		else if (item[i] == seperator)
			currentIndex++;
		else if (currentIndex == expectedIndex)
		{
			tempString[currentAppendIndex] = item[i];
			currentAppendIndex++;
		}
	}

	tempString[currentAppendIndex] = '\0';

	return tempString;
}

// Returns the number of elements in a List<string>.
int stringGetSplitCount(string item, char seperator)
{
	int i;
	int expectedCapacity = strlen(item) + 1;
	int returnCount = 1;

	for (i = 0; i < expectedCapacity; i++)
	{
		if (item[i] == seperator)
			returnCount++;
	}

	return item[0] == '\0' ? 0 : returnCount;
}

// Dispose the string.
void stringDispose(string item)
{
	free(item);
}