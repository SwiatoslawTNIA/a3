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
#define BASE 10
//first two cards are reserved for the first player, second 2 for the 
//second player
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
  printHeader();
  int result = runningGameChoosingPhase(Player1, Player2);
  if(result == -2 || result == -3)
    return result;
  
  return result;
  //to mave adjustments
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below uses the playerchooses function with error handling to 
/// store 4 cards selected by the user in an array chosen_cards
///
/// @param PlayerN is a pointer to struct of type Player
/// @param pt_to_pt_card is a pointer to pointer to card on the heap;
///
/// @return -2 if quit, -3 if out of memory, 0 by default
//
int runningGameChoosingPhase(Player Player1, Player Player2)
{//Player 1:

  int chosen_cards[4];
  printPlayerStatus(Player1);
  
  int resp_1 = playerChooses(Player1, chosen_cards);
  if(resp_1 == -2 || resp_1 == -3)
    return resp_1;

  printPlayerStatus(Player2);
  int resp_2 = playerChooses(Player2, &chosen_cards[2]);
  if(resp_2 == -2 || resp_2 == -3)
    return resp_2;
  
  printf("The chosen cards are:");
  for(int i = 0; i < 4; ++i)
  {
    printf(" %d", chosen_cards[i]);
  }
  return 0;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below uses the chooseCard function with error handling to 
/// store 2 cards from one player in an array defined in runningGameChoosingPhase()
///
/// @param PlayerN is a pointer to struct of type Player
/// @param pt_to_pt_card is a pointer to pointer to card on the heap;
///
/// @return -2 if quit, -3 if out of memory, 0 by default
//
int playerChooses(Player PlayerN, int arr_to_store[])
{
  printf("Please choose a first card to keep:\nP%d > ", PlayerN.id);
  int card_number = 0;
  while((card_number = chooseCard(PlayerN)) <= 0)
  {
    if(card_number == -2)
      return -2;
    else if(card_number == -3)
    {
      fprintf(stderr, "Error: Out of memory\n");
      return -3;
    }
  }
  printf("The chosen card number is: %d\n", card_number);
  arr_to_store[0] = card_number;
  printf("Please choose a second card to keep:\nP%d > ", PlayerN.id);
  while((card_number = chooseCard(PlayerN)) <= 0)
  {
    if(card_number == -2)
      return -2;
    else if(card_number == -3)
    {
      fprintf(stderr, "Error: Out of memory\n");
      return -3;
    }
  }
  printf("The chosen card number is: %d\n", card_number);
  arr_to_store[1] = card_number;
  return 0;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below checks if the input contains a number, that is in one of the hand cards
///
///
/// @param string is a pointer to the string on the heap, entered by the user.
/// @param pt_to_pt_card is a pointer to pointer to card on the heap;
///
/// @return -1 if the card_number was not found,-2 if quit,-3 if out of memory ,
/// or the card number chosen
//
int chooseCard(Player PlayerN)// we will need access to cards, and id
{
  int card_number = -1;

  char *answer = readString();//1.Check for the quit command:
  if(answer == NULL)
  {
    return -3;
  }
  int result_quit = checkStringQuit(answer);//returns 1 if the command is not quit
  int result_num = checkStringNumbers(answer,PlayerN.hand_cards);

  if(result_quit == 0)
  {
    free(answer);
    return -2;//quit
  }
  else if(result_quit == -4)
  {
    fprintf(stderr, "Please enter the correct number of parameters!\n");
  }
  else //the command is not quit
  {
    if(result_num == -5)
    {
      sscanf(answer, "%d", &card_number);
    }else
    {
      fprintf(stderr, "Please enter the number of a card in your hand cards!\n");
    } 
  }
  free(answer);
  return card_number;//this function has to return 1, so we can track the correct execution
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below checks if the input contains a number, that is in one of the hand cards
///
///
/// @param string is a pointer to the string on the heap, entered by the user.
/// @param pt_to_pt_card is a pointer to pointer to card on the heap;
///
/// @return if found returns -5, -3 if not found
//
int checkStringNumbers(char *string, Card **pt_to_pt_card)
{
  int number = 0;
  if(sscanf(string, "%d", &number) == 1)
  {

    bool found = false;
    for(int i = 0; i < 10;++i)//move through each of the cards of the current player:
    {
      if(pt_to_pt_card[i]->card_type == HAND_CARD)
      {
        if(number == pt_to_pt_card[i]->number)
        {
          found = true;
        }
      }
    }
    if(found == true)
      return -5;
    else 
      return -3;
  }
  return -3;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below checks if the quit command was entered
///
/// @param string is a pointer to the string on the heap, entered by the user.
///
/// @return 0 if user entered quit without params, -4 if quit is entered with params, 
/// -1 otherwise
//
int checkStringQuit(char *string)
{
  const char *str = "quit";
  bool same = true;
  for(int i = 0; str[i] != '\0';++i)
  {
    if(str[i] != string[i])
    {
      same = false;
      break;
    }
  }
  if(same == true && strlen(string) == 4)
  {
   return 0;
  }else if(same == true)
  {//they are the same but the string has additional parameters:

    return -4;
  }
  return -1;//if they are not the same, 1 will be returned
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below reads a string dynamically allocating memory for it
///
/// @return a char pointer to the string located on the heap.
//
char *readString(void)
{
  //user input must be read using realloc:
  char *string = malloc(sizeof(char)*BASE);
  char c;
  int counter = 0;
  while((c = getchar()) != '\n' && c != EOF)
  {
    if(counter % 10 == 0 && counter != 0)
    {
      string = realloc(string, sizeof(char)*BASE*(counter / 10 + 1));
    }
    string[counter++] = c;
  }
  string[counter] = '\0';
  return string;
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
  printf("Player %d:\n hand cards:", PlayerN.id);
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
