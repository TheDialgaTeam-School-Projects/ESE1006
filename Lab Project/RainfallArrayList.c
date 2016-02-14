/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Prototype of List<float> in c#
// Expected Item[Year][Month][Day]

// List<float> rainfallArrayList;
struct List_float rainfallArrayList;

// A function to setup rainfallArrayList.
void rainfallArrayListSetup(void)
{
	rainfallArrayList.Item = listInit((END_YEAR - START_YEAR + 1) * 12 * 31, sizeof(float));
	rainfallArrayList.Capacity = (END_YEAR - START_YEAR + 1) * 12 * 31;
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
	rainfallArrayList.Item = listSet(rainfallArrayList.Item, newCapacity, sizeof(float));
	rainfallArrayList.Capacity = newCapacity;
}

// Gets the number of elements contained in the List<float>.
int rainfallArrayListCount(int nameRefIndex, int yearIndex, int monthIndex)
{
	int i = 0;
	int returnCount = 0;

	while (rainfallArrayListGetItem(nameRefIndex, yearIndex, monthIndex, i) >= 0 && i < 31)
	{
		returnCount++;
		i++;
	}

	return returnCount;
}

// Gets the element at the specified index.
float rainfallArrayListGetItem(int nameRefIndex, int yearIndex, int monthIndex, int dayIndex)
{
	return rainfallArrayList.Item[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12 * 31) + (yearIndex * 12 * 31) + (monthIndex * 31) + dayIndex];
}

// Sets the element at the specified index.
void rainfallArrayListSetItem(int nameRefIndex, int yearIndex, int monthIndex, int dayIndex, float item)
{
	while ((nameRefIndex * (END_YEAR - START_YEAR + 1) * 12 * 31) + (yearIndex * 12 * 31) + (monthIndex * 31) + dayIndex > rainfallArrayListGetCapacity())
		rainfallArrayListSetCapacity(rainfallArrayListGetCapacity() + (END_YEAR - START_YEAR + 1) * 12 * 31);

	rainfallArrayList.Item[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12 * 31) + (yearIndex * 12 * 31) + (monthIndex * 31) + dayIndex] = item;
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<float>.
void rainfallArrayListAdd(void)
{
	int i;
	int j;
	int k;

	rainfallArrayListSetCapacity(rainfallArrayListGetCapacity() + (END_YEAR - START_YEAR + 1) * 12 * 31);

	for (i = 0; i < (END_YEAR - START_YEAR + 1); i++)
	{
		for (j = 0; j < 12; j++)
		{
			for (k = 0; k < 31; k++)
			{
				rainfallArrayListSetItem(rainfallCategoryListCount() - 1, i, j, k, -1.0);
			}
		}
	}
}

// Inserts an element into the List<float> at the specified index.
void rainfallArrayListInsert(int nameRefIndex)
{
	int i;
	int j;
	int k;
	int l;
	int expectedCapacity = rainfallArrayListGetCapacity() + (END_YEAR - START_YEAR + 1) * 12 * 31;

	float* tempFloat = listInit(expectedCapacity, sizeof(float));

	// Prepend any list in nameRefIndex
	for (i = 0; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				for (l = 0; l < 31; l++)
				{
					if (i < nameRefIndex)
						tempFloat[(i * (END_YEAR - START_YEAR + 1) * 12 * 31) + (j * 12 * 31) + (k * 31) + l] = rainfallArrayListGetItem(i, j, k, l);
					else
						break;
				}
			}
		}
	}

	// Append new index.
	for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
	{
		for (k = 0; k < 12; k++)
		{
			for (l = 0; l < 31; l++)
			{
				tempFloat[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12 * 31) + (j * 12 * 31) + (k * 31) + l] = false;
			}
		}
	}

	// Append Rest of the index.
	for (i = nameRefIndex; i < rainfallCategoryListCount(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				for (l = 0; l < 31; l++)
				{
					tempFloat[((i + 1) * (END_YEAR - START_YEAR + 1) * 12 * 31) + (j * 12 * 31) + (k * 31) + l] = rainfallArrayListGetItem(i, j, k, l);
				}
			}
		}
	}

	listDispose(rainfallArrayList.Item);
	rainfallArrayList.Item = tempFloat;
	rainfallArrayList.Capacity = expectedCapacity;
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

	rainfallArrayListSetCapacity((END_YEAR - START_YEAR + 1) * 12 * 31);

	// Setup Default Array / Active List.
	// Year 2014 > Every Month
	for (i = 0; i < 12; i++)
	{
		for (j = 0; j < 31; j++)
		{
			rainfallArrayListSetItem(0, 2014 - START_YEAR, i, j, tempArray[i][j]);
		}
	}
}

// Removes the element at the specified index of the List<float>.
void rainfallArrayListRemoveAt(int nameRefIndex)
{
	int i;
	int j;
	int k;
	int l;
	int expectedCount = rainfallArrayListGetCapacity() - (END_YEAR - START_YEAR + 1) * 12 * 31;
	int expectedCapacity;
	int appendIndex = 0;

	float* tempFloat;

	if (expectedCount == (END_YEAR - START_YEAR + 1) * 12 * 31)
	{
		rainfallArrayListClear();
		return;
	}
	else
		expectedCapacity = expectedCount;

	tempFloat = listInit(expectedCapacity, sizeof(float));

	for (i = 0; i < rainfallActiveListGetCapacity(); i++)
	{
		for (j = 0; j < (END_YEAR - START_YEAR + 1); j++)
		{
			for (k = 0; k < 12; k++)
			{
				for (l = 0; l < 31; l++)
				{
					if (i != nameRefIndex)
					{
						tempFloat[(nameRefIndex * (END_YEAR - START_YEAR + 1) * 12 * 31) + (j * 12 * 31) + (k * 31) + l] = rainfallArrayListGetItem(i, j, k, l);
					}
				}
			}
		}
	}

	listDispose(rainfallArrayList.Item);
	rainfallArrayList.Item = tempFloat;
	rainfallArrayList.Capacity = expectedCapacity;
}
#pragma endregion