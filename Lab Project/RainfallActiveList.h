/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

#ifndef _INC_RainfallActiveList
#define _INC_RainfallActiveList

#include "CustomTypes.h"

// List<bool> rainfallActiveList;
struct List_bool rainfallActiveList;

// A function to setup rainfallArrayList.
void rainfallActiveListSetup(void);

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallActiveListGetCapacity(void);

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallActiveListSetCapacity(int newCapacity);

// Gets the number of elements contained in the List<bool>.
int rainfallActiveListCount(int nameRefIndex);

// Gets the element at the specified index.
bool rainfallActiveListGetItem(int nameRefIndex, int monthIndex);

// Sets the element at the specified index.
void rainfallActiveListSetItem(int nameRefIndex, int monthIndex, bool item);
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<bool>.
void rainfallActiveListAdd(void);

// Inserts an element into the List<bool> at the specified index.
void rainfallActiveListInsert(int nameRefIndex);

// Removes all elements from the List<bool>.
void rainfallActiveListClear(void);

// Removes the element at the specified index of the List<bool>.
void rainfallActiveListRemoveAt(int index);
#pragma endregion
#endif