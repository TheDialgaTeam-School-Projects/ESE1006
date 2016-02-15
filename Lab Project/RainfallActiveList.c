/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Prototype of List<bool> in c#
// Expected Item[Year][Month]

// List<bool> rainfallActiveList;
struct List_bool rainfallActiveList;

// A function to setup rainfallArrayList.
void rainfallActiveListSetup(void)
{
	rainfallActiveList.Item = listInit(12, sizeof(bool));
	rainfallActiveList.Capacity = 12;
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
	rainfallActiveList.Item = listSet(rainfallActiveList.Item, newCapacity, sizeof(bool));
	rainfallActiveList.Capacity = newCapacity;
}

// Gets the number of elements contained in the List<bool>.
int rainfallActiveListDayCount(int nameRefIndex, int yearIndex)
{
	int i;
	int returnCount = 0;

	for (i = 0; i < 12; i++)
	{
		if (rainfallActiveListGetItem(nameRefIndex, yearIndex, i) == true)
		{
			returnCount++;
		}
	}

	return returnCount;
}

// Gets the number of elements contained in the List<bool>.
int rainfallActiveListYearCount(int nameRefIndex)
{
	int i;
	int j;
	int returnCount = 0;

	for (i = 0; i < END_YEAR - START_YEAR + 1; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (rainfallActiveListGetItem(nameRefIndex, i, j) == true)
			{
				returnCount += 1;
				break;
			}
		}
	}

	return returnCount;
}

// Gets the element at the specified index.
bool rainfallActiveListGetItem(int nameRefIndex, int yearIndex, int monthIndex)
{
	return rainfallActiveList.Item[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12) + (yearIndex * 12) + monthIndex];
}

// Sets the element at the specified index.
void rainfallActiveListSetItem(int nameRefIndex, int yearIndex, int monthIndex, bool item)
{
	while ((nameRefIndex * (END_YEAR - START_YEAR + 1) * 12) + (yearIndex * 12) + monthIndex > rainfallActiveListGetCapacity())
		rainfallActiveListAdd();

	rainfallActiveList.Item[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12) + (yearIndex * 12) + monthIndex] = item;
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<bool>.
void rainfallActiveListAdd(void)
{
	int i;
	int j;

	rainfallActiveListSetCapacity(rainfallActiveListGetCapacity() + (END_YEAR - START_YEAR + 1) * 12);

	for (i = 0; i < (END_YEAR - START_YEAR + 1); i++)
	{
		for (j = 0; j < 31; j++)
		{
			rainfallActiveListSetItem(rainfallCategoryListCount() - 1, i, j, false);
		}
	}
}

// Inserts an element into the List<bool> at the specified index.
void rainfallActiveListInsert(int nameRefIndex)
{
	int i;
	int j;
	int k;
	int expectedCapacity = rainfallArrayListGetCapacity() + (END_YEAR - START_YEAR + 1) * 12;

	bool* tempBool = listInit(expectedCapacity, sizeof(bool));

	// Prepend any list in nameRefIndex
	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				if (i < nameRefIndex)
					tempBool[(i * (END_YEAR - START_YEAR + 1) * 12) + (j * 12) + k] = rainfallActiveListGetItem(i, j, k);
				else
					break;
			}
		}
	}

	// Append new index.
	for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
	{
		for (k = 0; k < 12; k++)
		{
			tempBool[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12) + (j * 12) + k] = false;
		}
	}

	// Append Rest of the index.
	for (i = nameRefIndex; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				tempBool[((i + 1) * (END_YEAR - START_YEAR + 1) * 12) + (j * 12) + k] = rainfallActiveListGetItem(i, j, k);
			}
		}
	}

	listDispose(rainfallActiveList.Item);
	rainfallActiveList.Item = tempBool;
	rainfallActiveList.Capacity = expectedCapacity;
}

// Removes all elements from the List<bool>.
void rainfallActiveListClear(void)
{
	int i;

	rainfallActiveListSetCapacity((END_YEAR - START_YEAR + 1) * 12);

	// Setup Default Array / Active List.
	// By Default 2014 > All month active.
	for (i = 0; i < 12; i++)
	{
		rainfallActiveListSetItem(0, 2014 - START_YEAR, i, true);
	}
}

// Removes the element at the specified index of the List<bool>.
void rainfallActiveListRemoveAt(int nameRefIndex)
{
	int i;
	int j;
	int k;
	int expectedCount = rainfallActiveListGetCapacity() - (END_YEAR - START_YEAR + 1) * 12;
	int expectedCapacity;
	int appendIndex = 0;

	bool* tempBool;

	if (expectedCount == (END_YEAR - START_YEAR + 1) * 12)
	{
		rainfallArrayListClear();
		return;
	}
	else
		expectedCapacity = expectedCount;

	tempBool = listInit(expectedCapacity, sizeof(bool));

	for (i = 0; i < rainfallActiveListGetCapacity(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				if (i != nameRefIndex)
				{
					tempBool[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12) + (j * 12) + k] = rainfallActiveListGetItem(i, j, k);
				}
			}
		}
	}

	listDispose(rainfallActiveList.Item);
	rainfallActiveList.Item = tempBool;
	rainfallActiveList.Capacity = expectedCapacity;
}
#pragma endregion