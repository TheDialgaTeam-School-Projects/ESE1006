/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

// Prototype Header file for DateTime.c

#ifndef _INC_DateTime
#define _INC_DateTime

#include "CustomTypes.h"

// Start of the year value.
#define START_YEAR 1900

// End of the year value.
#define END_YEAR 2038

// Get the name of the month.
string getMonthName(int month);

// Get if the year is a leap year.
bool isLeapYear(int year);

// Get number of days in the defined month and year.
int getDayCount(int year, int month);
#endif