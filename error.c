//---------------------------------------------------------------------------------------------------------------------
// error.c
//
// The functions that are responsible for the error logic
//
// Group: error
//
// Author: 7393
//---------------------------------------------------------------------------------------------------------------------
//
#include "error.h"
// 4
// Error: Out of memory\n
// The program was not able to allocate new memory

// Please enter a valid command!\n
// The command does not exist

// Please enter the correct number of parameters!\n
// The command was called with too many or too few parameters

// Please enter a valid row number!\n
// The entered row number is below 1 or above 3

// Please enter the number of a card in your hand cards!\n
// The player's hand cards do not contain this card

// Please enter the number of a card in your chosen cards!\n
// The player's chosen cards do not contain this card

// This card cannot extend the chosen row!\n
// The chosen card cannot extend the chosen row

// Warning: Results not written to file!\n 
// The results could not be appended to the config file

//---------------------------------------------------------------------------------------------------------------------
///
/// The function below does the primary test, if the file exists, if the number of parameters was 
///correct and if the magic number is the same
///
/// @param argn is the amount of arguments accepted by the main function
/// @param argv pointer to an array of pointers, the [1] elements of which is the 
///
/// @return the value (0-3) based on the correctness of the input
//
int checkInputParam(int argn, char *argv[])
{
  if(argn < 2)
  {
    return 1;
  }else
  {
    //try to open the file:
    FILE *file_p = fopen(argv[1], "r");
    if(file_p == NULL)
    {
      return 2;
    }
     //check for the magic number:
    char *str = malloc(sizeof(char)* 120);
    char *str_c = str;
    char c;
    while((c = getc(file_p)) != '\n' && c != EOF)
    {
      *str_c++ = c;
    }
    *str_c = '\0';
    if(strcmp(str, "ESP") != 0)
    {
      free(str);
      return 3;
    }
    free(str);
  }
  return 0;
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below prints the error message
///
/// @param number is the error number
/// @param file_name is the name of the file passed as an arg.
///
/// @return void
//
void printError(int number, char *file_name)
{
  switch(number)
  {
    case(1):
    {
      fprintf(stderr, "Usage: ./a3 <config file>\n");
      break;
    };
    case(2):
    {
      fprintf(stderr, "Error: Cannot open the file: %s\n", file_name);
      break;
    };
    case(3):
    {
      fprintf(stderr, "Error: Invalid file: %s\n", file_name);
      break;
    };
    default: break;
  }
}
//---------------------------------------------------------------------------------------------------------------------
///
/// The function below checks for the validity of the output of the parseFile function
///
/// @param pt_to_pt_to_card is a pointer to pointer to type Card.
///
/// @return 4 if the output is invalid, otherwise 0;
//
int checkCard(Card **pt_to_pt_to_card)
{
  if (pt_to_pt_to_card == NULL)
  {
    fprintf(stderr, "Error: Out of memory\n");
    return 4;
  }
  return 0;
}
