//---------------------------------------------------------------------------------------------------------------------
// start.c
//
// The parsing of the input, the distribution of the input, welcoming message
//
// Group: all
//
// Author: 7393
//---------------------------------------------------------------------------------------------------------------------
//
#include "start.h"
size_t LENGTH = 0;
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below parses the file on different cards, dynamically allocating the memory for each
/// card and returning a pointer to an array of structs on a heap.
///
/// @param file_name is the name of the file to be parsed.
///
/// @return the pointer to an array of structs of type Card on the heap.
//
Card **parseFile(char *file_name)
{
  FILE *file_p = fopen(file_name, "r");//the file can be opened, because it was checked beforehand,so:
  rewind(file_p);//reset the file position to 0
  while(!isdigit(getc(file_p)))
    ;
  getc(file_p);//get  the enter after the number 2;
  int number = 0;
  char color;
  //create a pointer to an array of pointers to pointers to type Card
  Card **cards_array = (Card **)malloc(sizeof(Card*));
  while(fscanf(file_p, "%d_%c", &number, &color) == 2)
  {    
    if(LENGTH > 0)
    {
      Card **temp = realloc(cards_array, (LENGTH + 1) * sizeof(Card *));
      if(temp == NULL)
      {
        fclose(file_p);
        freeCardsArray(cards_array);
        return NULL;
      }  
      //free the cards array and then reallocate the new space to it:
      cards_array = temp;
    }
    cards_array[LENGTH++] = createCard(number, color);
    getc(file_p);
  }
  fclose(file_p);
  printWelcomeMessage();
  return cards_array;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function prints the welcoming message
///
///
/// @return void
//
void printWelcomeMessage(void)
{
  printf("Welcome to SyntaxSakura (2 players are playing)!\n"
  "\n");
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function frees the memory for a pointer to pointers to an array of structs
///
/// @param cards_array is a pointer to a pointer to a struct of type Card
///
/// @return void
//
void freeCardsArray(Card **cards_array)
{
  int i = 0;
  while(i < LENGTH)
  {
    free(cards_array[i]);
    cards_array[i] = NULL;
    i++;
  }

  free(cards_array);
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function frees the memory for a pointer to pointers to an array of structs
///
/// @param cards_array is a pointer to a pointer to a struct of type Card
/// @param cards_number is a number of cards to be freed
///
/// @return void
//
void freePlayerCards(Card **cards_array, int cards_number)
{
  int i = 0;
  while(i < cards_number)
  {
    free(cards_array[i]);
    cards_array[i] = NULL;
    i++;
  }

  free(cards_array);
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below creates a struct Card and returns it, assigning the structure the values
/// passed as args
///
/// @param number is the number arg of each struct
/// @param color is the color arg of each struct
///
/// @return a new Card structure(not the most effective solution)
//
Card *createCard(int number, char color)
{
  Card *new_card = malloc(sizeof(Card));
  new_card->color = color;
  new_card->number = number;
  new_card->card_type = HAND_CARD;
  new_card->row = 0;
  new_card->prev_Node = NULL;
  return new_card;
}
//distribute the cards:
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below creates a Player struct based on the index, if the index is 0 -
/// the first player is created, if the index is 1, the second player is created.
///
/// @param array_cards is the pointer to pointer to card, that is stored on the heap
/// @param index determines if that is the player 1 or player 2
///
/// @return a new Player struct
//
Player distribute(Card** array_cards, int index)
{//each player must have precisely 10 cards:
  int card_number = 0;
  if(index == 0)//this is the player 1
  {
    Player New_player = {NULL,NULL,10, 0, 0};
    //create a linked list:
    Card **pt_to_pt_card =(Card **)malloc(sizeof(Card*)*10);
    if(pt_to_pt_card == NULL)
    {
      return New_player;
    }
    for(int i = 0; card_number < 10; i += 2, card_number++)
    {
      //create new struct:
      Card *new_Card = createCard(array_cards[i]->number, array_cards[i]->color);
      if(new_Card == NULL)
      {
        freePlayerCards(pt_to_pt_card, card_number);
        return New_player;
      }
      pt_to_pt_card[card_number] = new_Card;
    }
    New_player.hand_cards = pt_to_pt_card;
    sortCards(New_player);
    return New_player;
  }
  else
  {//player 2:
    Player New_player = {NULL, NULL,10, 0, 1};
    Card **pt_to_pt_card =(Card **)malloc(sizeof(Card*)*10);
    if(pt_to_pt_card == NULL)
    {
      return New_player;
    }
    for(int i = 1;card_number < 10; i += 2, card_number++)
    {
      //create new struct:
      Card *new_Card = createCard(array_cards[i]->number, array_cards[i]->color);
      if(new_Card == NULL)
      {
        freePlayerCards(pt_to_pt_card, card_number);
        return New_player;
      }
      pt_to_pt_card[card_number] = new_Card;
    }
    New_player.hand_cards = pt_to_pt_card;
    sortCards(New_player);
    return New_player;
  }
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below sort the Player struct, by sorting the pointers to the memory, 
/// not the structs themselves
///
/// @param player is the pointer to Player structs that contains Card pointers
///
/// @return void
//
void sortCards(Player player)
{
  //instead of sorting the structs, we will sort the pointers to those structs:
  for(int i = 0; i < 9; ++i)
  {
    for(int j = 0; j < 9;++j)
    {
      if(player.hand_cards[j]->number > player.hand_cards[j + 1]->number)
      {
        Card *temp_card_p = player.hand_cards[j];
        player.hand_cards[j] = player.hand_cards[j + 1];
        player.hand_cards[j + 1] = temp_card_p;
      }
    }
  }
}