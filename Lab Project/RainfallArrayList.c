/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Prototype of List<float> in c#

// List<float> rainfallArrayList;
struct List_float rainfallArrayList;

// A function to setup rainfallArrayList.
void rainfallArrayListSetup(void)
{
	rainfallArrayList.Item = calloc(12 * 31, sizeof(float));
	rainfallArrayList.Capacity = 12 * 31;

	if (rainfallArrayList.Item == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}
}

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallArrayListGetCapacity(void)
{
	return rainfallArrayList.Capacity;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallArrayListSetCapacity(int newCapacity)
{
	rainfallArrayList.Item = realloc(rainfallArrayList.Item, newCapacity * sizeof(float));
	rainfallArrayList.Capacity = newCapacity;

	if (rainfallArrayList.Item == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}
}

// Gets the number of elements contained in the List<float>.
int rainfallArrayListCount(int nameRefIndex, int monthIndex)
{
	int i = 0;
	int returnCount = 0;

	while (rainfallArrayListGetItem(nameRefIndex, monthIndex, i) >= 0 && i < 31)
	{
		returnCount++;
		i++;
	}

	return returnCount;
}

// Gets the element at the specified index.
float rainfallArrayListGetItem(int nameRefIndex, int monthIndex, int dayIndex)
{
	return rainfallArrayList.Item[dayIndex + (monthIndex + nameRefIndex * 12) * 31];
}

// Sets the element at the specified index.
void rainfallArrayListSetItem(int nameRefIndex, int monthIndex, int dayIndex, float item)
{
	while (rainfallArrayListGetCapacity() < dayIndex + (monthIndex + nameRefIndex * 12) * 31)
		rainfallArrayListSetCapacity(rainfallArrayListGetCapacity() + 12 * 31);

	rainfallArrayList.Item[dayIndex + (monthIndex + nameRefIndex * 12) * 31] = item;
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<float>.
void rainfallArrayListAdd(void)
{
	int i;
	int j;

	rainfallArrayListSetCapacity(rainfallArrayListGetCapacity() + 12 * 31);

	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 31; j++)
		{
			rainfallArrayListSetItem(rainfallCategoryListCount() - 1, i, j, -1.0);
		}
	}
}

// Inserts an element into the List<float> at the specified index.
void rainfallArrayListInsert(int nameRefIndex)
{
	int i;
	int j;
	int k;

	float* tempFloat;

	rainfallArrayListSetCapacity(rainfallArrayListGetCapacity() + 12 * 31);

	tempFloat = rainfallArrayList.Item;

	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < 12; j++)
		{
			for (k = 0; k < 31; k++)
			{
				if (i != nameRefIndex)
					tempFloat[k + (j + i * 12) * 31] = rainfallArrayListGetItem(i, j, k);
				else
					tempFloat[k + (j + i * 12) * 31] = -1;
			}
		}
	}

	rainfallArrayList.Item = tempFloat;
}

// Removes all elements from the List<float>.
void rainfallArrayListClear(void)
{
	int i;
	int j;
	float tempArray[12][31] =
	{
		{ 0.0, 0.0, 0.0, 0.0, 18.4, 31.2, 0.0, 0.0, 2.0, 0.0, 5.6, 18.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
		{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, -1.0, -1.0 },
		{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 52.6, 5.4, 0.4, 0.0, 2.0, 5.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4, 0.0, 0.0 },
		{ 2.0, 0.0, 0.0, 0.0, 23.6, 0.0, 10.0, 6.6, 1.8, 0.0, 2.8, 8.0, 0.0, 0.0, 0.0, 0.2, 28.8, 0.0, 0.0, 0.2, 5.2, 0.0, 0.0, 2.2, 0.0, 0.0, 0.2, 0.2, 4.8, 13.4, -1.0 },
		{ 0.4, 0.0, 0.0, 1.4, 0.0, 0.2, 18.4, 10.6, 1.4, 0.0, 0.0, 0.4, 0.0, 1.6, 12.2, 20.2, 0.0, 22.4, 8.0, 2.4, 0.0, 2.0, 3.0, 0.0, 0.0, 0.0, 0.8, 2.6, 17.8, 0.0, 0.0 },
		{ 18.0, 0.0, 0.0, 6.6, 8.5, 4.2, 0.0, 0.0, 0.0, 1.6, 0.0, 4.4, 0.0, 18.8, 0.0, 0.0, 0.0, 2.4, 3.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.4, -1.0 },
		{ 0.0, 0.0, 0.2, 19.4, 0.8, 2.2, 3.6, 12.6, 12.6, 0.2, 26.8, 0.0, 0.0, 0.0, 0.0, 0.0, 7.8, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 27.8, 0.0, 29.0, 4.0, 1.0 },
		{ 0.0, 11.8, 0.0, 1.2, 7.4, 0.4, 9.2, 2.0, 0.0, 0.0, 0.0, 1.4, 2.4, 41.2, 0.6, 0.0, 0.0, 10.4, 0.0, 12.0, 1.6, 0.0, 0.8, 0.0, 7.2, 44.2, 8.4, 38.8, 39.4, 0.0, 0.6 },
		{ 0.0, 0.0, 9.2, 0.0, 0.0, 0.0, 0.8, 0.0, 1.0, 3.2, 1.4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 34.6, 0.6, 0.0, 0.0, 9.4, 23.4, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0 },
		{ 0.0, 0.0, 0.0, 6.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 32.6, 2.4, 2.8, 0.0, 0.0, 4.6, 6.0, 0.0, 0.0, 0.0, 0.0, 32.8, 3.2, 0.0, 11.6, 17.4 },
		{ 4.4, 0.0, 0.0, 0.0, 20.6, 12.4, 10.4, 50.4, 4.4, 1.4, 5.0, 0.4, 64.6, 0.0, 13.6, 8.0, 0.2, 7.6, 0.0, 0.0, 0.2, 1.6, 3.2, 1.6, 0.2, 39.4, 0.0, 0.6, 0.6, 0.0, -1.0 },
		{ 26.4, 0.0, 0.0, 18.8, 0.0, 27.4, 35.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 5.0, 17.6, 0.0, 15.6, 0.4, 0.4, 0.6, 0.2, 0.6, 37.6, 47.0, 10.6, 0.2, 2.0, 0.0, 0.0 }
	};

	rainfallArrayListSetCapacity(12 * 31);

	// Setup Default Array / Active List.
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 31; j++)
		{
			rainfallArrayListSetItem(0, i, j, tempArray[i][j]);
		}
	}
}

// Removes the element at the specified index of the List<float>.
void rainfallArrayListRemoveAt(int index)
{
	int i;
	int expectedCount = rainfallArrayListGetCapacity() - 12 * 31;
	int expectedCapacity;
	int appendIndex = 0;

	float* tempFloat;

	if (expectedCount == 12 * 31)
	{
		rainfallArrayListClear();
		return;
	}
	else
		expectedCapacity = rainfallArrayListGetCapacity() - 12 * 31;

	tempFloat = calloc(expectedCapacity, sizeof(float));

	if (tempFloat == '\0')
	{
		puts("ERROR: Unable to allocate memory. Expect glitches or crashes at code execution.");
	}

	for (i = 0; i < rainfallArrayListGetCapacity(); i++)
	{
		if (i < index * 12 * 31 || i > (index + 1) * 12 * 31)
		{
			tempFloat[appendIndex] = rainfallArrayList.Item[i];
			appendIndex++;
		}
	}

	rainfallArrayListSetCapacity(expectedCapacity);
	rainfallArrayList.Item = tempFloat;

	free(tempFloat);
}
#pragma endregion