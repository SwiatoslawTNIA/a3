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
  int number = 0, index = 0;
  char color;
  //create a pointer to an array of pointers to pointers to type Card
  Card **cards_array = (Card **)malloc(sizeof(Card*));
  while(fscanf(file_p, "%d_%c", &number, &color) == 2)
  {    
    if(index >= 1)
    {
      cards_array = realloc(cards_array, (index + 1 )* sizeof(Card*));//dynamically allocated space for the size
      printf("|%lu|", (index + 1)* sizeof(Card));
      if(cards_array == NULL)
      {
        free_cards_array(cards_array);
        return NULL;
      }  
    }
    Card *new_card = createCard(number, color);
    *(cards_array + index++) = new_card;
    printf("Card.color = %c, card_number = %d\n", cards_array[index - 1]->color,
    cards_array[index - 1]->number); 
    getc(file_p);
  }
  fclose(file_p);
  return cards_array;
}//---------------------------------------------------------------------------------------------------------------------
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
  while(cards_array[i] != NULL)
  {
    free(cards_array[i++]);
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
