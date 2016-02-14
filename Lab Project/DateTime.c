/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#include "Modules.h"

// Get the name of the month.
string getMonthName(int month)
{
	switch (month)
	{
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		default:
			return NULL;
	}
}

// Get if the year is a leap year.
bool isLeapYear(int year)
{
	// Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100,
	// but these centurial years are leap years if they are exactly divisible by 400. For example, the years 1700, 1800,
	// and 1900 are not leap years, but the year 2000 is.

	if ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0)
		return true;
	else
		return false;
}

// Get number of days in the defined month and year.
int getDayCount(int year, int month)
{
	switch (month)
	{
		case 1:
			return 31;
		case 2:
			return isLeapYear(year) == true ? 29 : 28;
		case 3:
			return 31;
		case 4:
			return 30;
		case 5:
			return 31;
		case 6:
			return 30;
		case 7:
			return 31;
		case 8:
			return 31;
		case 9:
			return 30;
		case 10:
			return 31;
		case 11:
			return 30;
		case 12:
			return 31;
		default:
			return 31;
	}
}