/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// List<categoryList> rainfallCategoryList
struct categoryList rainfallCategoryList;

// A function to setup rainfallCategoryList.
void rainfallCategoryListSetup(void)
{
	rainfallCategoryList.rainfallCategoryList = calloc(1, sizeof(*rainfallCategoryList.rainfallCategoryList));
	rainfallCategoryList.capacity = 1;

	if (rainfallCategoryList.rainfallCategoryList == NULL)
		puts("> ERROR: Unable to allocate memory. Expect crashes or glitches!");

	rainfallCategoryListClear();
}

#pragma region rainfallCategoryList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallCategoryListGetCapacity(void)
{
	return rainfallCategoryList.capacity;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallCategoryListSetCapacity(int newCapacity)
{
	if (newCapacity != rainfallCategoryList.capacity)
	{
		rainfallCategoryList.rainfallCategoryList = realloc(rainfallCategoryList.rainfallCategoryList, newCapacity * sizeof(struct rainfallCategory));
		rainfallCategoryList.capacity = newCapacity;

		if (rainfallCategoryList.rainfallCategoryList == NULL)
			puts("> ERROR: Unable to allocate memory. Expect crashes or glitches!");
	}
}

// Gets the number of elements contained in the List<rainfallCategory>.
int rainfallCategoryListCount(void)
{
	return rainfallCategoryList.capacity;
}

// Gets the element at the specified index.
string rainfallCategoryListGetItem(int categoryIndex)
{
	if (categoryIndex < rainfallCategoryList.capacity)
		return rainfallCategoryList.rainfallCategoryList[categoryIndex].name;
	else
		return rainfallCategoryList.rainfallCategoryList[rainfallCategoryList.capacity - 1].name;
}

// Sets the element at the specified index.
void rainfallCategoryListSetItem(int categoryIndex, string item)
{
	int year, month, day;

	while (rainfallCategoryList.capacity < categoryIndex + 1)
	{
		rainfallCategoryListSetCapacity(rainfallCategoryList.capacity + 1);

		for (year = 0; year < rainfallYearListGetCapacity(); year++)
		{
			for (month = 0; month < rainfallMonthListGetCapacity(); month++)
			{
				for (day = 0; day < rainfallDayListGetCapacity(); day++)
				{
					rainfallCategoryList.rainfallCategoryList[rainfallCategoryList.capacity - 1].item[year][month][day] = -1;
				}
			}
		}
	}

	stringCopy(rainfallCategoryList.rainfallCategoryList[categoryIndex].name, item);
}
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<rainfallCategory>.
void rainfallCategoryListAdd(string item)
{
	int year, month, day;
	int expectedRainfallCategoryListCapacity = rainfallCategoryListGetCapacity() + 1;

	rainfallCategoryListSetCapacity(expectedRainfallCategoryListCapacity);
	stringCopy(rainfallCategoryList.rainfallCategoryList[expectedRainfallCategoryListCapacity - 1].name, item, NULL);

	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		for (month = 0; month < rainfallMonthListGetCapacity(); month++)
		{
			for (day = 0; day < rainfallDayListGetCapacity(); day++)
			{
				rainfallCategoryList.rainfallCategoryList[rainfallCategoryList.capacity - 1].item[year][month][day] = -1;
			}
		}
	}
}

// Inserts an element into the List<rainfallCategory> at the specified index.
void rainfallCategoryListInsert(int categoryIndex, string item)
{
	int i, year, month, day;
	int expectedRainfallCategoryListCount = rainfallCategoryListCount() + 1;

	struct rainfallCategory* tempList = calloc(expectedRainfallCategoryListCount, sizeof(struct rainfallCategory));

	if (tempList == NULL)
		puts("> ERROR: Unable to allocate memory. Expect crashes or glitches!");

	// Prepend Category List.
	// Original Index: 0 1 2 3 < Insert From 1.
	// New Index: 0 1 # 3 4
	for (i = 0; i <= categoryIndex; i++)
	{
		// Copy Name.
		stringCopy(tempList[i].name, rainfallCategoryList.rainfallCategoryList[i].name, NULL);

		// Copy Item.
		for (year = 0; year < rainfallYearListGetCapacity(); year++)
		{
			for (month = 0; month < rainfallMonthListGetCapacity(); month++)
			{
				for (day = 0; day < rainfallDayListGetCapacity(); day++)
				{
					tempList[i].item[year][month][day] = rainfallCategoryList.rainfallCategoryList[i].item[year][month][day];
				}
			}
		}
	}

	// Append New Category List.
	stringCopy(tempList[categoryIndex + 1].name, item, NULL);

	// Init New Item.
	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		for (month = 0; month < rainfallMonthListGetCapacity(); month++)
		{
			for (day = 0; day < rainfallDayListGetCapacity(); day++)
			{
				tempList[categoryIndex + 1].item[year][month][day] = -1;
			}
		}
	}

	// Append Rest of the Index.
	// Original Index: 0 1 2 3 < Insert From 1.
	// New Index: 0 1 # 2 3
	for (i = categoryIndex + 2; i < expectedRainfallCategoryListCount; i++)
	{
		// Copy Name.
		stringCopy(tempList[i].name, rainfallCategoryList.rainfallCategoryList[i - 1].name, NULL);

		// Copy Item.
		for (year = 0; year < rainfallYearListGetCapacity(); year++)
		{
			for (month = 0; month < rainfallMonthListGetCapacity(); month++)
			{
				for (day = 0; day < rainfallDayListGetCapacity(); day++)
				{
					tempList[i].item[year][month][day] = rainfallCategoryList.rainfallCategoryList[i - 1].item[year][month][day];
				}
			}
		}
	}

	free(rainfallCategoryList.rainfallCategoryList);
	rainfallCategoryList.rainfallCategoryList = tempList;
	rainfallCategoryList.capacity = expectedRainfallCategoryListCount;
}

// Removes all elements from the List<rainfallCategory>.
void rainfallCategoryListClear(void)
{
	int year, month, day;

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

	rainfallCategoryListSetCapacity(1);
	stringCopy(rainfallCategoryList.rainfallCategoryList[0].name, "Default", NULL);

	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		for (month = 0; month < rainfallMonthListGetCapacity(); month++)
		{
			for (day = 0; day < rainfallDayListGetCapacity(); day++)
			{
				if (year == 2014 - START_YEAR)
					rainfallCategoryList.rainfallCategoryList[0].item[year][month][day] = tempArray[month][day];
				else
					rainfallCategoryList.rainfallCategoryList[0].item[year][month][day] = -1;
			}
		}
	}
}

// Removes the element at the specified index of the List<rainfallCategory>.
void rainfallCategoryListRemoveAt(int categoryIndex)
{
	int i, year, month, day;
	int expectedRainfallCategoryListCount = rainfallCategoryListCount() - 1;

	struct rainfallCategory* tempList;

	if (expectedRainfallCategoryListCount == 0)
		rainfallCategoryListClear();
	else
	{
		tempList = calloc(expectedRainfallCategoryListCount, sizeof(struct rainfallCategory));

		if (tempList == NULL)
			puts("> ERROR: Unable to allocate memory. Expect crashes or glitches!");

		for (i = 0; i < rainfallCategoryList.capacity; i++)
		{
			if (i != categoryIndex)
			{
				// Copy Name.
				stringCopy(tempList[i].name, rainfallCategoryList.rainfallCategoryList[i].name, NULL);

				// Copy Item.
				for (year = 0; year < rainfallYearListGetCapacity(); year++)
				{
					for (month = 0; month < rainfallMonthListGetCapacity(); month++)
					{
						for (day = 0; day < rainfallDayListGetCapacity(); day++)
						{
							tempList[i].item[year][month][day] = rainfallCategoryList.rainfallCategoryList[i].item[year][month][day];
						}
					}
				}
			}
		}

		free(rainfallCategoryList.rainfallCategoryList);
		rainfallCategoryList.rainfallCategoryList = tempList;
		rainfallCategoryList.capacity = expectedRainfallCategoryListCount;
	}
}
#pragma endregion
#pragma endregion

#pragma region rainfallYearList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallYearListGetCapacity(void)
{
	return END_YEAR - START_YEAR + 1;
}

// Gets the number of elements contained in the List<rainfallCategory.item>.
int rainfallYearListCount(int categoryIndex)
{
	int year;
	int returnCount = 0;

	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		if (rainfallMonthListCount(categoryIndex, year) > 0)
		{
			returnCount++;
		}
	}

	return returnCount;
}
#pragma endregion
#pragma endregion

#pragma region rainfallMonthList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallMonthListGetCapacity(void)
{
	return 12;
}

// Gets the number of elements contained in the List<rainfallCategory.item>
int rainfallMonthListCount(int categoryIndex, int yearIndex)
{
	int month;
	int returnCount = 0;

	for (month = 0; month < rainfallMonthListGetCapacity(); month++)
	{
		if (rainfallDayListCount(categoryIndex, yearIndex, month) > 0)
		{
			returnCount++;
		}
	}

	return returnCount;
}
#pragma endregion
#pragma endregion

#pragma region rainfallDayList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallDayListGetCapacity(void)
{
	return 31;
}

// Gets the number of elements contained in the List<rainfallCategory.item>
int rainfallDayListCount(int categoryIndex, int yearIndex, int monthIndex)
{
	int returnCount = 0;

	while (rainfallDayListGetItem(categoryIndex, yearIndex, monthIndex, returnCount) >= 0 && returnCount < getDayCount(yearIndex - START_YEAR, monthIndex + 1))
	{
		returnCount++;
	}

	return returnCount;
}

// Gets the element at the specified index.
float rainfallDayListGetItem(int categoryIndex, int yearIndex, int monthIndex, int dayIndex)
{
	return rainfallCategoryList.rainfallCategoryList[categoryIndex].item[yearIndex][monthIndex][dayIndex];
}

// Sets the element at the specified index.
void rainfallDayListSetItem(int categoryIndex, int yearIndex, int monthIndex, int dayIndex, float item)
{
	rainfallCategoryList.rainfallCategoryList[categoryIndex].item[yearIndex][monthIndex][dayIndex] = item;
}
#pragma endregion
#pragma endregion