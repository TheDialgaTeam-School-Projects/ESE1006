/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

#ifndef _INC_RainfallYearList
#define _INC_RainfallYearList

// List<int> rainfallYearList;
struct List_int rainfallYearList;

// A function to setup rainfallYearList.
void rainfallYearListSetup(void);

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallYearListGetCapacity(void);

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallYearListSetCapacity(int newCapacity);
#pragma endregion
#endif