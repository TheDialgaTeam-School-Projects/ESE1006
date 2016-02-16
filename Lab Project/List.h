/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27

*/

#pragma once

#ifndef _INC_List
#define _INC_List

// Command Prompt Max String Buffer.
#define CMD_MAX 8191

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

// List<categoryList>
struct categoryList rainfallCategoryList;

// A function to setup rainfallCategoryList.
void rainfallCategoryListSetup(void);

#pragma region rainfallCategoryList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallCategoryListGetCapacity(void);

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallCategoryListSetCapacity(int newCapacity);

// Gets the number of elements contained in the List<rainfallCategory>.
int rainfallCategoryListCount(void);

// Gets the element at the specified index.
string rainfallCategoryListGetItem(int categoryIndex);

// Sets the element at the specified index.
void rainfallCategoryListSetItem(int categoryIndex, string item);
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<rainfallCategory>.
void rainfallCategoryListAdd(string item);

// Inserts an element into the List<rainfallCategory> at the specified index.
void rainfallCategoryListInsert(int categoryIndex, string item);

// Removes all elements from the List<rainfallCategory>.
void rainfallCategoryListClear(void);

// Removes the element at the specified index of the List<rainfallCategory>.
void rainfallCategoryListRemoveAt(int categoryIndex);
#pragma endregion
#pragma endregion

#pragma region rainfallYearList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallYearListGetCapacity(void);

// Gets the number of elements contained in the List<rainfallCategory.item>.
int rainfallYearListCount(int categoryIndex);
#pragma endregion
#pragma endregion

#pragma region rainfallMonthList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallMonthListGetCapacity(void);

// Gets the number of elements contained in the List<rainfallCategory.item>
int rainfallMonthListCount(int categoryIndex, int yearIndex);
#pragma endregion
#pragma endregion

#pragma region rainfallDayList
#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallDayListGetCapacity(void);

// Gets the number of elements contained in the List<rainfallCategory.item>
int rainfallDayListCount(int categoryIndex, int yearIndex, int monthIndex);

// Gets the element at the specified index.
float rainfallDayListGetItem(int categoryIndex, int yearIndex, int monthIndex, int dayIndex);

// Sets the element at the specified index.
void rainfallDayListSetItem(int categoryIndex, int yearIndex, int monthIndex, int dayIndex, float item);
#pragma endregion
#pragma endregion

#endif