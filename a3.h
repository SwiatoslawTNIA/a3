//---------------------------------------------------------------------------------------------------------------------
// a3.h
//
// This is a header file, where all the main functions of the group start are declared,
//
// Group: start
//
// Author: 7939
//---------------------------------------------------------------------------------------------------------------------
//

//because a3.h is included in start.h and error.h , those in turn are included in the main
//file, this file will be included at least 3 times, so it must be ensured, that the values
//are defined only once:
#ifndef ADDED_CARD

#define ADDED_CARD
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct 
{
  char color;
  int number;
} Card;

#endif

