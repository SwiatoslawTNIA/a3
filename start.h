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
void freePlayerCards(Card **cards_array, int cards_number);
Player distribute(Card** aray_cards, int index);
Card **parseFile(char *file_name);
Card *createCard(int number, char color);
void freeCardsArray(Card **cards_array);
void printWelcomeMessage(void);