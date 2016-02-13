/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Initializes a new instance of the List<T> class that is empty and has the default initial capacity.
void* listInit(int capacity, int typeSize)
{
	void* tempArray = calloc(capacity, typeSize);

	if (tempArray == NULL)
	{
		perror("> ERROR: ");
		return NULL;
	}
	else
		return tempArray;
}

// Sets the total number of elements the internal data structure can hold without resizing.
void* listSet(void* list, int capacity, int typeSize)
{
	void* tempArray = realloc(list, capacity * typeSize);

	if (tempArray == NULL)
	{
		perror("> ERROR: ");
		return NULL;
	}
	else
		return tempArray;
}

// Dispose the list.
void listDispose(void* list)
{
	free(list);
}