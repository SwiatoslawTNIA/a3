//---------------------------------------------------------------------------------------------------------------------
// a3.c
//
// The main part of the program, where all four modules are combined: start, running, finishing, error
//
// Group: all
//
// Author: 7393
//---------------------------------------------------------------------------------------------------------------------
//
#include "a3.h"
#include "error.h"
#include "start.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below starts the execution of the program
///
/// @param argc is the number of arguments passed when executing the while
/// @param argv is an array of pointers to string literals, that represent the args, that are
/// passed when executing the program
///
/// @return the execution code
//
int PLAYERS = 0;

int main(int argc, char *argv[])
{
  int RETURN_VALUE = checkInputParam(argc, argv); 
  printError(RETURN_VALUE, argv[1]);
  if(RETURN_VALUE == 0)
  {
    Card **pt_to_pt_to_card = parseFile(argv[1]);
    RETURN_VALUE = checkCard(pt_to_pt_to_card);
    Player Player1 = distribute(pt_to_pt_to_card, 0);
    RETURN_VALUE = checkPlayerCards(Player1.cards_array_p);
    if(RETURN_VALUE == 4)
    {
      freeCardsArray(pt_to_pt_to_card);
      return RETURN_VALUE;
    }
    Player Player2 = distribute(pt_to_pt_to_card, 1);
    RETURN_VALUE = checkPlayerCards(Player2.cards_array_p);
    if(RETURN_VALUE == 4)
    {
      freePlayerCards(Player1.cards_array_p, 10);
      freeCardsArray(pt_to_pt_to_card);
      return RETURN_VALUE;
    }//if there was enough memory for everything:








    freePlayerCards(Player1.cards_array_p, 10);
    freePlayerCards(Player2.cards_array_p, 10);
    freeCardsArray(pt_to_pt_to_card);
  }
  return RETURN_VALUE;
}