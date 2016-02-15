/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Prototype List<categoryList>.
struct categoryList
{
	// Prototype List<rainfallCategory>.
	struct rainfallCategory* rainfallCategoryList;

	// Size of capacity.
	int capacity;
};

// Prototype List<rainfallCategory>
struct rainfallCategory
{
	// Name of the category.
	char name[CMD_MAX + 1];

	// Rainfall value.
	float item[END_YEAR - START_YEAR + 1][12][31];
};

// List<categoryList> rainfallCategoryList
struct categoryList rainfallCategoryList;

// A function to setup rainfallCategoryList.
void rainfallCategoryListSetup(void)
{
	rainfallCategoryList.rainfallCategoryList = malloc(1 * sizeof(struct rainfallCategory));
	rainfallCategoryList.capacity = 1;

	if (rainfallCategoryList.rainfallCategoryList == NULL)
		perror("> ERROR: ");

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
	rainfallCategoryList.rainfallCategoryList = realloc(newCapacity, sizeof(struct rainfallCategory));
	rainfallCategoryList.capacity = newCapacity;

	if (rainfallCategoryList.rainfallCategoryList = NULL)
		perror("> ERROR: ");
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
void rainfallCategoryListAdd(string categoryIndex)
{
	int year, month, day;

	rainfallCategoryListSetCapacity(rainfallCategoryList.capacity + 1);
	stringCopy(rainfallCategoryList.rainfallCategoryList[rainfallCategoryList.capacity - 1].name, categoryIndex, NULL);

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

	struct rainfallCategory* tempList = malloc(expectedRainfallCategoryListCount * sizeof(struct rainfallCategory));

	if (tempList == NULL)
		perror("> ERROR: ");

	// Prepend Category List.
	for (i = 0; i < categoryIndex; i++)
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
	stringCopy(tempList[categoryIndex].name, item, NULL);

	// Init New Item.
	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		for (month = 0; month < rainfallMonthListGetCapacity(); month++)
		{
			for (day = 0; day < rainfallDayListGetCapacity(); day++)
			{
				tempList[categoryIndex].item[year][month][day] = -1;
			}
		}
	}

	// Append Rest of the Index.
	for (i = categoryIndex; i < expectedRainfallCategoryListCount - 1; i++)
	{
		// Copy Name.
		stringCopy(tempList[i + 1].name, rainfallCategoryList.rainfallCategoryList[i].name, NULL);

		// Copy Item.
		for (year = 0; year < rainfallYearListGetCapacity(); year++)
		{
			for (month = 0; month < rainfallMonthListGetCapacity(); month++)
			{
				for (day = 0; day < rainfallDayListGetCapacity(); day++)
				{
					tempList[i + 1].item[year][month][day] = rainfallCategoryList.rainfallCategoryList[i].item[year][month][day];
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

	rainfallCategoryListSetCapacity(1);
	stringCopy(rainfallCategoryList.rainfallCategoryList[0].name, "Default", NULL);

	for (year = 0; year < rainfallYearListGetCapacity(); year++)
	{
		for (month = 0; month < rainfallMonthListGetCapacity(); month++)
		{
			for (day = 0; day < rainfallDayListGetCapacity(); day++)
			{
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
		tempList = malloc(expectedRainfallCategoryListCount * sizeof(struct rainfallCategory));

		if (tempList == NULL)
			perror("> ERROR: ");

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

	while (rainfallCategoryList.rainfallCategoryList[categoryIndex].item[yearIndex][monthIndex][returnCount] >= 0 && returnCount < getDayCount(yearIndex - START_YEAR, monthIndex + 1))
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
#pragma endregion
#pragma endregion