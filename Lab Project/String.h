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

// Dispose the string.
void stringDispose(string item);
#endif