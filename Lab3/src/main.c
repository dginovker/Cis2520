#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/Book.h"

int dummyCompare(const void* first, const void* second)
{
  return 0;
}

void deleteListNode(void *toBeDeleted)
{

}

int intCompare(const void* first, const void* second)
{
  if ((int*)first < (int*)second)
  {
    return -1;
  }
  else if ((int*)first > (int*)second)
  {
    return 1;
  }
  return 0;
}

void prInt(void* anInt)
{
  printf("%d\n", *(int*)anInt);
}

int main()
{
  List *aBookList = initializeList(*printBook, *deleteListNode, *dummyCompare);
  List *anIntList = initializeList(*prInt, *deleteListNode, *intCompare);
  Book *b1 = createBook("Here's a book", 19.99);
  Book *b2 = createBook("Here's another book", 29.99);
  Book *b3 = createBook("Let's gooooooooooooo", 39.99);

  int *ints[3], i;
  for (i = 0; i < 3; i++)
  {
    ints[i] = malloc(sizeof(int));
    *ints[i] = 2*i+4;
  }

  anIntList -> head = initializeNode((void*)ints[0]);
  anIntList -> tail = anIntList -> head;

  insertSorted(anIntList, ints[1]);
  insertSorted(anIntList, ints[2]);

  aBookList -> head = initializeNode((void*)b1);
  aBookList -> tail = aBookList -> head;

  insertFront(aBookList, (void*)b2);
  insertBack(aBookList, (void*)b3);

  printf("printForward BookList:\n");
  printForward(aBookList);

  printf("printForward intList:\n");
  printForward(anIntList);
  printf("printBackwards intList:\n");
  printBackwards(anIntList);

  deleteList(aBookList);

  return 0;
}
