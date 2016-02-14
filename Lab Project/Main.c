/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Main Entry Point.
void main(void)
{
	// Setup List<string> RainfallNameList
	rainfallCategoryListSetup();

	// Setup List<float> RainfallArrayList
	rainfallArrayListSetup();

	// Setup List<bool> RainfallActiveList
	rainfallActiveListSetup();

	// Setup Default values.
	rainfallCategoryListClear();
	rainfallArrayListClear();
	rainfallActiveListClear();

	// Change the console colour to a more friendly readable colour.
	system("color 17");

	// Change the console title for some fancyness :P.
	system("title CPPS Project - Rainfall Viewer 1");

	showMainMenu();
}