/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Prototype of List<bool> in c#

// List<bool> rainfallActiveList;
struct List_bool rainfallActiveList;

// A function to setup rainfallArrayList.
void rainfallActiveListSetup(void)
{
	rainfallActiveList.Item = calloc(12, sizeof(bool));
	rainfallActiveList.Capacity = 12;

	if (rainfallActiveList.Item == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}
}

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallActiveListGetCapacity(void)
{
	return rainfallActiveList.Capacity;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallActiveListSetCapacity(int newCapacity)
{
	rainfallActiveList.Item = realloc(rainfallArrayList.Item, newCapacity * sizeof(bool));
	rainfallActiveList.Capacity = newCapacity;

	if (rainfallActiveList.Item == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}
}

// Gets the number of elements contained in the List<bool>.
int rainfallActiveListCount(int nameRefIndex)
{
	int i;
	int returnCount = 0;

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(nameRefIndex, i) == true)
		{
			returnCount++;
		}
	}
	return returnCount;
}

// Gets the element at the specified index.
bool rainfallActiveListGetItem(int nameRefIndex, int monthIndex)
{
	return rainfallActiveList.Item[monthIndex + nameRefIndex * 12];
}

// Sets the element at the specified index.
void rainfallActiveListSetItem(int nameRefIndex, int monthIndex, bool item)
{
	while (rainfallActiveListGetCapacity() < monthIndex + nameRefIndex * 12)
		rainfallActiveListAdd();

	rainfallActiveList.Item[monthIndex + nameRefIndex * 12] = item;
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<bool>.
void rainfallActiveListAdd(void)
{
	int i;

	rainfallActiveListSetCapacity(rainfallActiveListGetCapacity() + 12);

	for (i = 0; i < 12; i++)
	{
		rainfallActiveListSetItem(rainfallCategoryListCount() - 1, i, false);
	}
}

// Inserts an element into the List<bool> at the specified index.
void rainfallActiveListInsert(int nameRefIndex)
{
	int i;
	int j;

	bool* tempBool;

	rainfallActiveListSetCapacity(rainfallArrayListGetCapacity() + 12 * 31);

	tempBool = rainfallActiveList.Item;

	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (i != nameRefIndex)
				tempBool[j + i * 12] = rainfallActiveListGetItem(i, j);
			else
				tempBool[j + i * 12] = false;
		}
	}
}

// Removes all elements from the List<bool>.
void rainfallActiveListClear(void)
{
	int i;

	rainfallActiveListSetCapacity(12);

	// Setup Default Array / Active List.
	for (i = 0; i < 12; i++)
	{
		rainfallActiveListSetItem(0, i, true);
	}
}

// Removes the element at the specified index of the List<bool>.
void rainfallActiveListRemoveAt(int index)
{
	int i;
	int expectedCount = rainfallActiveListGetCapacity() - 12;
	int expectedCapacity;
	int appendIndex = 0;

	bool* tempBool;

	if (expectedCount == 12)
	{
		rainfallArrayListClear();
		return;
	}
	else
		expectedCapacity = rainfallActiveListGetCapacity() - 12;

	tempBool = calloc(expectedCapacity, sizeof(bool));

	if (tempBool == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}

	for (i = 0; i < rainfallActiveListGetCapacity(); i++)
	{
		if (i < index * 12 || i >(index + 1) * 12)
		{
			tempBool[appendIndex] = rainfallActiveList.Item[i];
			appendIndex++;
		}
	}

	rainfallActiveListSetCapacity(expectedCapacity);
	rainfallActiveList.Item = tempBool;

	free(tempBool);
}
#pragma endregion