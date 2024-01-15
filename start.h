//---------------------------------------------------------------------------------------------------------------------
// start.h
//
// The header file of the start.c file, in which all the prototypes and necessary enums, structs and typedefs
//
// Group: all
//
// Author: 7393
//---------------------------------------------------------------------------------------------------------------------
//
#ifndef INCLUDED
#define INCLUDED
#include "a3.h"
#endif

Card **parseFile(char *file_name);
Card *createCard(int number, char color);
void free_cards_array(Card **cards_array);
void printWelcomeMessage(void);