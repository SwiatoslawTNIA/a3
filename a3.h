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
enum TYPE {HAND_CARD, CHOSEN_CARD, ROW_CARD};
typedef struct Node
{
  char color;
  int number;
  struct Node *prev_Node;
  enum TYPE card_type;
  int row;
} Card;
typedef struct 
{
  Card **hand_cards;
  Card **chosen_cards;
  int hand_cards_n;
  int chosen_cards_n;
  int id;
} Player;
#endif

