#include <stdlib.h>
#include <stdio.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/intListTest.h"
#include "../includes/Test.h"

int compareInt(const void* a, const void* b)
{
  return *(int*)b - *(int*)a;
}

void printInt(void* a)
{
  printf("%d\n",*(int*)a);
}

void deleteInt(void *a)
{
  void *temp = a;
  if (a)
  {
    free (temp);
  }
}

int *initInt(int b)
{
  int *a;
  a = malloc(sizeof(int));
  *a = b;
  return a;
}

int intTest()
{
  int issues = 0;
  List *list = NULL;
  int test;
  int *a, *a1;
  Node *b;
  //Second round of testing, with more edge cases
  a = initInt(7);
  a1 = initInt(70);

  //Testing node was initialized successfully
  b = initializeNode((void*) a);
  test = 0;
  if (*(int*)(b -> data) != 7)
  {
    test = 1;
  }
  issues += TEST(test, "Checking of Node initialized with value 7 is valid");

  //Testing list was initialized successfully
  list = initializeList(&printInt, &deleteInt, &compareInt);
  test = 0;
  if (list -> deleteNode != *deleteInt)
  {
    test = 1;
  }
  issues += TEST(test, "Checking to see if the initializedList works and holds correct values");

  //Testing insertFront function
  insertFront(list, a);
  test = 0;
  if (list -> head -> data != (void*)a || list -> tail -> data != (void*)a)
  {
    test = 1;
    issues += TEST(test, "Checking if insertFront worked (first insert on list!)");
  }


  //Testing insertBack function
  insertBack(list, a1);
  test = 0;
  if (list -> tail -> data != (void*)a1 || list -> head -> data != (void*)a)
  {
    test = 1;
  }
  issues += TEST(test, "Checking if insertBack worked correctly and also did not disturb anything else on list");
  //Testing deleteList function
  list = deleteList(list);
  a = initInt(7);
  a1 = initInt(70);

  test = 0;
  if (list != NULL)
  {
    test = 1;
  }
  issues += TEST(test, "Checking to see if list was properly deleted");

  //Testing reinitialization of list
  list = initializeList(&printInt, &deleteInt, &compareInt);
  test = 0;
  if (list -> deleteNode != *deleteInt)
  {
    test = 1;
  }
  issues += TEST(test, "Checking to see if the reinitialization of the list was successful");

  //Testing insertBack as first command done to list
  insertBack(list, (void*)a);
  test = 0;
  if (list -> tail -> data != (void*)a || list -> head -> data != (void*)a)
  {
    test = 1;
  }
  issues += TEST(test, "Testing insertBack as first operation done to list");

  //Testing insertFront again
  insertFront(list, (void*) a1);
  test = 0;
  if (list -> tail -> data != (void*)a || list -> head -> data != (void*)a1)
  {
    test = 1;
  }
  issues += TEST(test, "Testing insertFront works properly and doesn't disturb anything else with the list");

  deleteList(list);
  list = initializeList(&printInt, &deleteInt, &compareInt);
  a = initInt(7);
  a1 = initInt(70);

  //Testing insertSorted on an empty list
  insertSorted(list, (void*)a);
  test = 0;
  if (list -> head -> data != (void*)a)
  {
    test = 1;
  }
  issues += TEST(test, "insertSorted on an empty list");
  printf("Printing forward list:\n");
printForward(list);
printf("Added an element. Printforwarding again:\n");
  //Testing insertSorted on a non-empty list
  insertSorted(list, (void*)a1);
  test = 0;
  printForward(list);
  if (*(int*)(list -> tail -> data) != 70)
  {
    test = 1;
  }
  issues += TEST(test, "Testing insertSorted with one element in it");
  return issues;
}
