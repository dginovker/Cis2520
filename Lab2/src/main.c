// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
// Not Standard Libraries
#include "../includes/Book.h"
#include "../includes/boardgame.h"
#include "../includes/store.h"


int main(int argc, char ** argv)
{
    Book *b1 = createBook( "Harry Potter And The Cursed Child", 19.99);
    Book *b2 = createBook("The cool and amazing parts of C you didn't know existed", 420.69);
    BoardGame *bg1 = createBoardGame("BoardgameName", "BrandNameName", 666);
    BoardGame *bg2 = createBoardGame("Where am I supposed to put the answers to my assignments", "Or are they just for my personal learning", 123.12);
    Store * s = createStore(b1, *printBook);
    displayStore(s);

    rebrandStore(s, b2, *printBook);
    displayStore(s);
    rebrandStore(s, bg1, *printBoardGame);
    displayStore(s);
    rebrandStore(s, bg2, *printBoardGame);
    displayStore(s);

    free(b1);
    free(b2);
    free(bg1);
    free(bg2);
    free(s);

    /*
    * QUESTION ANSWERS ARE IN README FILE
    */
    return 0;
}
