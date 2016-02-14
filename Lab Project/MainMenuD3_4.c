/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// A function to show menu D3.4.
void showMenuD3_4(void)
{
	printHeader("D3.4. Rainfall database manager - Reset to factory default.");

	rainfallCategoryListClear();
	rainfallArrayListClear();
	rainfallActiveListClear();

	puts("Successfully reset to factory default!");
	pause();
}