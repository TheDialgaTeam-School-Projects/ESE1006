/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// List<string> rainfallCategoryList;
struct List_string rainfallCategoryList;

// A function to setup rainfallCategoryList.
void rainfallCategoryListSetup(void)
{
	rainfallCategoryList.Item = listInit(1, sizeof(char));
}

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallCategoryListGetCapacity(void)
{
	return strlen(rainfallCategoryList.Item) + 1;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallCategoryListSetCapacity(int newCapacity)
{
	rainfallCategoryList.Item = listSet(rainfallCategoryList.Item, newCapacity, sizeof(char));
}

// Gets the number of elements contained in the List<string>.
int rainfallCategoryListCount(void)
{
	return stringGetSplitCount(rainfallCategoryList.Item, '|');
}

// Gets the element at the specified index.
// Require dispose to be done after use.
string rainfallCategoryListGetItem(int index)
{
	return stringGetSplit(rainfallCategoryList.Item, index, '|');
}

// Sets the element at the specified index.
void rainfallCategoryListSetItem(int index, string item)
{
	int i;
	int expectedCapacity;

	string tempString;
	string tempGetItem;

	if (index < rainfallCategoryListCount())
	{
		tempGetItem = rainfallCategoryListGetItem(index);
		expectedCapacity = rainfallCategoryListGetCapacity() + (strlen(item) - strlen(tempGetItem));
		stringDispose(tempGetItem);
	}
	else
		expectedCapacity = rainfallCategoryListGetCapacity() + (index + 1 - rainfallCategoryListCount()) + strlen(item);

	tempString = stringInit(expectedCapacity);

	// Prepend string that isn't met with the index.
	for (i = 0; i < index; i++)
	{
		if (i == 0)
		{
			tempGetItem = rainfallCategoryListGetItem(i);
			tempString = stringCopy(tempString, tempGetItem, NULL);
			stringDispose(tempGetItem);
		}
		else
		{
			tempGetItem = rainfallCategoryListGetItem(i);
			tempString = stringConcat(tempString, "|", tempGetItem, NULL);
			stringDispose(tempGetItem);
		}
	}

	// Append new string.
	if (index > 0)
		tempString = stringConcat(tempString, "|", item, NULL);
	else
		tempString = stringCopy(tempString, item, NULL);
		
	// Append the rest of the index if applicable.
	for (i = index + 1; i < rainfallCategoryListCount(); i++)
	{
		tempGetItem = rainfallCategoryListGetItem(i);
		tempString = stringConcat(tempString, "|", tempGetItem, NULL);
		stringDispose(tempGetItem);
	}

	listDispose(rainfallCategoryList.Item);
	rainfallCategoryList.Item = tempString;
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<string>.
void rainfallCategoryListAdd(string item)
{
	int expectedCount = rainfallCategoryListCount() + 1;
	int expectedCapacity;

	if (rainfallCategoryListCount() == 0)
		expectedCapacity = rainfallCategoryListGetCapacity() + strlen(item);
	else
		expectedCapacity = rainfallCategoryListGetCapacity() + 1 + strlen(item);

	rainfallCategoryListSetCapacity(expectedCapacity);

	if (expectedCount == 1)
		rainfallCategoryList.Item = stringCopy(rainfallCategoryList.Item, item, NULL);
	else
		rainfallCategoryList.Item = stringConcat(rainfallCategoryList.Item, "|", item, NULL);
}

// Removes all elements from the List<string>.
void rainfallCategoryListClear(void)
{
	rainfallCategoryListSetCapacity(1);
	rainfallCategoryList.Item[0] = '\0';

	// Setup Default Category.
	rainfallCategoryListAdd("Default");
}

// Removes the element at the specified index of the List<string>.
void rainfallCategoryListRemoveAt(int index)
{
	int i;
	int expectedCount = rainfallCategoryListCount() - 1;
	int expectedCapacity;
	
	string tempString;
	string tempGetItem;

	if (expectedCount == 0)
	{
		rainfallCategoryListClear();
		return;
	}
	else
	{
		tempGetItem = rainfallCategoryListGetItem(index);
		expectedCapacity = rainfallCategoryListGetCapacity() - 1 - strlen(tempGetItem);
		stringDispose(tempGetItem);
	}
		
	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		if (i == 0 && i != index)
		{
			tempGetItem = rainfallCategoryListGetItem(i);
			tempString = stringCopy(tempString, tempGetItem, NULL);
			stringDispose(tempGetItem);
		}
		else
		{
			if (i == 1 && index == 0)
			{
				tempGetItem = rainfallCategoryListGetItem(i);
				tempString = stringCopy(tempString, tempGetItem, NULL);
				stringDispose(tempGetItem);
			}
			else if (i != index)
			{
				tempGetItem = rainfallCategoryListGetItem(i);
				tempString = stringConcat(tempString, "|", tempGetItem, NULL);
				stringDispose(tempGetItem);
			}
		}
	}

	listDispose(rainfallCategoryList.Item);
	rainfallCategoryList.Item = tempString;
}
#pragma endregion