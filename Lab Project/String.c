/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma warning (disable : 4244 )

#include "Modules.h"

// Create a new instance of String.
string stringInit(int capacity)
{
	string tempString = calloc(capacity, sizeof(char));

	if (tempString == NULL)
	{
		perror("> ERROR");
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
		if (item[i] == '\0' || item[i] == '\n' || currentIndex > expectedIndex)
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

// Convert Integer to String
// Require dispose after use.
string intToString(int value, bool leadingZero)
{
	string tempString = stringInit(CMD_MAX + 1);
	string returnString = stringInit(CMD_MAX + 1);
	
	sprintf(tempString, "%d", value);

	if (value < 10 && leadingZero)
		returnString = stringCopy(returnString, "0", tempString, NULL);
	else
		returnString = stringCopy(returnString, tempString, NULL);

	stringDispose(tempString);

	return returnString;
}

// Convert string to integer.
int stringToInt(string value)
{
	int i;
	int returnValue;
	int expectedLength = strlen(value);

	bool canReturn;
	bool isNegative;

	do
	{
		returnValue = 0;
		canReturn = true;
		isNegative = false;

		for (i = 0; i < expectedLength; i++)
		{
			if (i > 0 && value[i] == '\0')
				break;
			else if (i == 0 && value[i] == '-')
				isNegative = true;
			else if ((i > 0 && value[i] == '-') || (!isdigit(value[i]) && value[i] != '-'))
			{
				return -1;
			}
			else
				returnValue += returnValue < 1 ? value[i] - '0' : returnValue * 10 + value[i] - '0' - returnValue;
		}
	} while (!canReturn);

	return isNegative ? returnValue * -1 : returnValue;
}

// Convert string to float.
float stringToFloat(string value)
{
	int i;
	int decimalAppendIndex;
	int expectedLength = strlen(value);

	bool canReturn;
	bool isDecimal;
	bool isNegative;

	float returnValue;

	do
	{
		decimalAppendIndex = 0;
		returnValue = 0;
		canReturn = true;
		isDecimal = false;
		isNegative = false;

		for (i = 0; i < expectedLength; i++)
		{
			if (i > 0 && value[i] == '\0')
				break;
			else if (i == 0 && value[i] == '-')
				isNegative = true;
			else if (value[i] == '\n' || value[i] == '—')
				continue;
			else if ((i > 0 && value[i] == '-') || (i > 0 && value[i] == '.' && isDecimal) || (!isdigit(value[i]) && value[i] != '-' && value[i] != '.'))
			{
				return 0;
			}
			else if (value[i] == '.')
				isDecimal = true;
			else if (!isDecimal)
				returnValue += returnValue < 1 ? value[i] - '0' : returnValue * 10 + value[i] - '0' - returnValue;
			else if (isDecimal)
			{
				returnValue += (value[i] - '0') / pow(10, decimalAppendIndex + 1);
				decimalAppendIndex++;
			}
		}
	} while (!canReturn);

	return isNegative ? returnValue * -1 : returnValue;
}

// Determines whether two String objects have the same value.
bool stringEquals(string item, string item2)
{
	int i = 0;

	while (item[i] != '\0' && item2[i] != '\0')
	{
		if (item[i] != item2[i])
			return false;

		i++;
	}

	return true;
}

// Dispose the string.
void stringDispose(string item)
{
	free(item);
}