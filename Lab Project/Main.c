/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Main Entry Point.
void main(void)
{
	// Setup List<categoryList> rainfallCategoryList
	rainfallCategoryListSetup();

	// Change the console colour.
	system("color 17");

	// Change the console title.
	system("title CPPS Project - Rainfall Viewer 1");

	showMainMenu();
}