#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/boardgame.h"

BoardGame* createBoardGame(char *name, char *brandName, double price)
{
  BoardGame *game = NULL;
  game = malloc(sizeof(game));
  game -> name = malloc(strlen(name)+1);
  game -> brandName = malloc(strlen(brandName)+1);
  strcpy(game -> name, name);
  strcpy(game -> brandName, brandName);
  game -> price = price;

  return game;
}

double getBoardGamePrice( BoardGame *b )
{
  return b -> price;
}

char* getBoardGameName( BoardGame *b )
{
  return b -> name;
}

char* getBoardGameBrandName( BoardGame *b )
{
  return b -> brandName;
}

void printBoardGame( void *v )
{
  BoardGame *b = (BoardGame*)v;
  printf("%s\t%f\t%s\n", getBoardGameName(b), getBoardGamePrice(b), getBoardGameBrandName(b) );
}
