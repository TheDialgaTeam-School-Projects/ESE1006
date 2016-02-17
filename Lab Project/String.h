/*
Name: Yong Jian Ming
Admin No: 1501545F
Class: PE27
*/

#pragma once

// Prototype Header file for String.c

#ifndef _INC_String
#define _INC_String

// Create a new instance of String.
string stringInit(int capacity);

// Creates a new instance of String with the same value as a specified String.
string stringCopy(string item, ...);

// Concatenates one or more instances of String, or the String representations of the values of one or more instances of Object.
string stringConcat(string item, ...);

// Returns the nth index of the splited string after spliting the seperator in the original string.
// Require dispose to be done after use.
string stringGetSplit(string item, int index, char seperator);

// Returns the number of elements in a List<string>.
int stringGetSplitCount(string item, char seperator);

// Convert Integer to String
// Require dispose after use.
string intToString(int value, bool leadingZero);

// Convert string to integer.
int stringToInt(string value);

// Convert string to float.
float stringToFloat(string value);

// Dispose the string.
void stringDispose(string item);
#endif