/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// List<int> rainfallYearList;
struct List_int rainfallYearList;

// A function to setup rainfallYearList.
void rainfallYearListSetup(void)
{
	rainfallYearList.Item = listInit(1, sizeof(int));
	rainfallYearList.Capacity = 1;
}

#pragma region Properties
// Gets the total number of elements the internal data structure can hold without resizing.
int rainfallYearListGetCapacity(void)
{
	return rainfallYearList.Capacity;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void rainfallYearListSetCapacity(int newCapacity)
{
	rainfallYearList.Item = listSet(rainfallYearList.Item, newCapacity, sizeof(int));
	rainfallYearList.Capacity = newCapacity;
}

// Gets the number of elements contained in the List<int>.
int rainfallYearListCount(int nameRefIndex, int yearIndex)
{

}

// Gets the element at the specified index.
int rainfallYearListGetItem(int nameRefIndex, int yearIndex)
{
	
}
#pragma endregion