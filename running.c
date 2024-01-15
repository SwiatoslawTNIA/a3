//---------------------------------------------------------------------------------------------------------------------
// running.c
//
// The functions that are responsible for the running phase of the program
//
// Group: running
//
// Author: 7393
//---------------------------------------------------------------------------------------------------------------------
//
#include "running.h"
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below is the function responsible for the logic of the running phase of the
/// program
///
/// @param Player1 the struct Player1
/// @param argv is the struct Player2
///
/// @return the execution code
//
int runningGame(Player Player1, Player Player2)
{
  printPlayerStatus(Player1);
  printPlayerStatus(Player2);







  printHeader();
  return 0;
}
void chooseCard(Player PlayerN)// we will need access to cards, and id
{
  printf("Please choose a first card to keep:\nP%d > ", PlayerN.id);

}

//---------------------------------------------------------------------------------------------------------------------
///
/// The function below prints the header "CARD CHOOSING PHASE"
///
/// @return void
//
void printHeader(void)
{
  printf("-------------------\nCARD CHOOSING PHASE\n-------------------\n");
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below prints the player status
///
/// @param PlayerN is a sturct of type Player, that contains all the data necessary
/// for printing the status of the Player
///
/// @return void
//
void printPlayerStatus(Player PlayerN)
{
  printf("Player %d:\n hand cards:", PlayerN.id + 1);
  for(int i = 0; i < PlayerN.hand_cards_n;++i)
  {
    if(PlayerN.hand_cards[i]->card_type == HAND_CARD)
    {
      printf(" %d_%c", PlayerN.hand_cards[i]->number, PlayerN.hand_cards[i]->color);
    }
  }
  printf("\n chosen cards:");
  //print the chosen cards:
  for(int i = 0; i < PlayerN.chosen_cards_n;++i)
  {
    if(PlayerN.hand_cards[i]->card_type == CHOSEN_CARD)
    {
      printf(" %d_%c", PlayerN.hand_cards[i]->number, PlayerN.hand_cards[i]->color);
    }
  }
  printf("\n");
  //print rows:
  printf("\n");
}
