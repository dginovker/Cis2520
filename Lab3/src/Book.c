// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/Book.h"

Book* createBook( char * title, double price )
{
    Book* b = malloc(sizeof(Book));
    b->price  = price;
    b->name = title;
    return b;
}

double getPrice( Book * b )
{
    return b->price;
}

char* getName( Book *b )
{
	return b->name;
}

void printBook( void * v )
{
  Book *b = (Book*)v;
  printf("%s : %f\n", getName(b), getPrice(b) );
}
