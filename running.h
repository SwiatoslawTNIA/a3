//---------------------------------------------------------------------------------------------------------------------
// running.h
//
// This is a header file, where all the prototypes for the module running (the second part
// of the program) are defined.
//
// Group: running
//
// Author: 7939
//---------------------------------------------------------------------------------------------------------------------
//
#include "a3.h"
int runningGame(Player Player1, Player Player2);
void printHeader(void);
void printPlayerStatus(Player PlayerN);
int chooseCard(Player PlayerN);
int checkStringQuit(char *string);
char *readString(void);
int checkStringNumbers(char *string, Card **pt_to_pt_card);
int runningGameChoosingPhase(Player Player1, Player Player2);
int playerChooses(Player PlayerN, int arr_to_store[]);
void printChoosingPhaseOver(void);
void createLinkedList(Player PlayerN);