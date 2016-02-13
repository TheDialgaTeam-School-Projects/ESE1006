/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function that will clear everything on the console.
void clear(void)
{
	system("cls");
}

// A function that will pause the code until a key have been pressed.
void pause(void)
{
	system("pause");
}

// A function to print a line of hash.
void printHash(void)
{
	puts("##################################################");
}

// A function to print the header.
void printHeader(string stringToDisplay)
{
	clear();
	printHash();
	puts(stringToDisplay);
	printHash();
}