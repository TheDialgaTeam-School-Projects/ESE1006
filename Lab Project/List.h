/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

#ifndef _INC_List
#define _INC_List

// Prototype List<string>
struct List_string
{
	string Item;
};

// Prototype List<int>
struct List_int
{
	int* Item;
	int Capacity;
};

// Prototype List<float>
struct List_float
{
	float* Item;
	int Capacity;
};

// Prototype List<bool>
struct List_bool
{
	bool* Item;
	int Capacity;
};

// Initializes a new instance of the List<T> class that is empty and has the default initial capacity.
void* listInit(int capacity, int typeSize);

// Sets the total number of elements the internal data structure can hold without resizing.
void* listSet(void* list, int capacity, int typeSize);

// Dispose the list.
void listDispose(void* list);
#endif