// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Not Standard Libraries
#include "../includes/Book.h"
#include "../includes/boardgame.h"
#include "../includes/store.h"


int main(int argc, char ** argv)
{
    int testFailed = 0;
    Book *b1 = createBook( "bookName", 1);
    BoardGame *bg1 = createBoardGame("boardName", "brandName", 2);
    Store * s = createStore(b1, *printBook);

    printf("Boardgame price should be 2. Boardgame price: %lf\n", getBoardGamePrice(bg1));
    if (getBoardGamePrice(bg1) == 2)
    {
      printf("\n[TEST PASSED]");
    }
    else
    {
      printf("\n[TEST FAILED]");
      testFailed = 1;
    }

    printf("Boardgame name should be \"boardName\": %s\n", getBoardGameName(bg1));
    if (strcmp(getBoardGameName(bg1), "boardName") == 0)
    {
      printf("\n[TEST PASSED]");
    }
    else
    {
      printf("\n[TEST FAILED]");
      testFailed = 1;
    }

    printf("Book price should be 1. Book price: %lf\n", getPrice(b1));
    if (getPrice(b1) == 1)
    {
      printf("\n[TEST PASSED]");
    }
    else
    {
      printf("\n[TEST FAILED]");
      testFailed = 1;
    }

    printf("Book name should be \"bookName\": %s\n", getName(b1));
    if (strcmp(getName(b1), "bookName") == 0)
    {
      printf("\n[TEST PASSED]");
    }
    else
    {
      printf("\n[TEST FAILED]");
      testFailed = 1;
    }

    if (testFailed == 0)
    {
      printf("\n---------------\nALL TESTS PASSED\n");
    }
    else
    {
      printf("\nWARNING: SOME TESTS FAILED");
    }

    free(b1);
    free(bg1);
    free(s);
    return 0;
}
