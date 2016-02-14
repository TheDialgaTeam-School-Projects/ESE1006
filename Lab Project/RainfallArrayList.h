/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

#ifndef _INC_RainfallArrayList
#define _INC_RainfallArrayList

// List<float> rainfallArrayList;
struct List_float rainfallArrayList;

// A function to setup rainfallArrayList.
void rainfallArrayListSetup(void);

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallArrayListGetCapacity(void);

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallArrayListSetCapacity(int newCapacity);

// Gets the number of elements contained in the List<float>.
int rainfallArrayListCount(int nameRefIndex, int yearIndex, int monthIndex);

// Gets the element at the specified index.
float rainfallArrayListGetItem(int nameRefIndex, int yearIndex, int monthIndex, int dayIndex);

// Sets the element at the specified index.
void rainfallArrayListSetItem(int nameRefIndex, int yearIndex, int monthIndex, int dayIndex, float item);
#pragma endregion

#pragma region Methods
// Adds an object to the end of the List<float>.
void rainfallArrayListAdd(void);

// Inserts an element into the List<float> at the specified index.
void rainfallArrayListInsert(int nameRefIndex);

// Removes all elements from the List<float>.
void rainfallArrayListClear(void);

// Removes the element at the specified index of the List<float>.
void rainfallArrayListRemoveAt(int nameRefIndex);
#pragma endregion
#endif