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
        free_cards_array(cards_array);
        return NULL;
      }  
      //free the cards array and then reallocate the new space to it:
      cards_array = temp;
      printf("|%lu|", (LENGTH + 1)* sizeof(Card));
    }
    cards_array[LENGTH++] = createCard(number, color);
    printf("Card.color = %c, card_number = %d\n", cards_array[LENGTH - 1]->color,
    cards_array[LENGTH - 1]->number); 
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
void free_cards_array(Card **cards_array)
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
  return new_card;
}
