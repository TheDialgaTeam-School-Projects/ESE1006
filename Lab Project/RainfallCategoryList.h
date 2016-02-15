/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

#ifndef _INC_RainfallCategoryList
#define _INC_RainfallCategoryList

// List<string> rainfallCategoryList;
// struct List_string rainfallCategoryList;

// A function to setup rainfallCategoryList.
void rainfallCategoryListSetup(void);

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallCategoryListGetCapacity(void);

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallCategoryListSetCapacity(int newCapacity);

// Gets the number of elements contained in the List<string>.
int rainfallCategoryListCount(void);

// Gets the element at the specified index.
// Require dispose to be done after use.
string rainfallCategoryListGetItem(int index);

// Sets the element at the specified index.
void rainfallCategoryListSetItem(int index, string item);
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<string>.
void rainfallCategoryListAdd(string item);

// Removes all elements from the List<string>.
void rainfallCategoryListClear(void);

// Removes the element at the specified index of the List<string>.
void rainfallCategoryListRemoveAt(int index);
#pragma endregion
#endif