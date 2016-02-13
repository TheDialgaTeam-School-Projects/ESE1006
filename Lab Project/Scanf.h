/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once

// Prototype Header file for Scanf.c

#ifndef _INC_Scanf
#define _INC_Scanf

// A function to get keyboard input.
// This function will validate the input before returning as char.
char scanChar(void);

// A function to get keyboard input.
// This function will validate the input before returning as int.
int scanInt(void);

// A function to get keyboard input.
// This function will validate the input before returning as string.
// Require dispose to be done after use.
string scanString(int Type);

// A function to get keyboard input.
// This function will validate the input before returning as float.
float scanFloat(void);
#endif