/*
	Name: Yong Jian Ming
	Admin No: 1501545F
	Class: PE27
*/

#pragma once
#pragma warning (disable : 4305 )
#pragma warning (disable : 4996 )

#ifndef _INC_MODULES
#define _INC_MODULES

// Include Basic Library that will be used in this project.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>

#include "CustomTypes.h"
#include "DateTime.h"
#include "Functions.h"
#include "Scanf.h"
#include "String.h"

#include "List.h"

#include "Menus.h"

// Define Database Password. Alphanumeric char only.
#define SYSTEM_PASSWORD "123"

// Command Prompt Max String Buffer.
#define CMD_MAX 8191

// Get Current working directory. No trailing slash at the end.
#define WORKING_DIR getcwd('\0', 0)
#endif