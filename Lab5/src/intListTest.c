#include <stdlib.h>
#include <stdio.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/intListTest.h"
#include "../includes/Test.h"

int compareInt(const void* a, const void* b)
{
  if (*(int*)a > *(int*)b)
  {
    return 1;
  }
  if (*(int*)a == *(int*)b)
  {
    return 0;
  }
  return -1;
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
  int testVar;
  int *t1, *t2;
  List *aList;
  Node *aNode = NULL;

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
  deleteList(list);
  a = initInt(7);
  a1 = initInt(70);

  test = 0;
//FAILED; SEE DELETELIST IN LINKEDLISTAPI.C. CHANGE LIST -> HEAD TO LIST
  if (list -> head != NULL)
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

  //Testing insertSorted on a non-empty list
  *a1 = 70;
  insertSorted(list, (void*)a1);
  if (*(int*)(list -> head -> data) != 70)
  {
    test = 1;
    printForward(list);
    printf("%d != 70\n", *(int*)(list -> head -> data));
  }
  issues += TEST(test, "Testing insertSorted with one element in it");
//Test insertSorted with a2 and a3 just to be sure it 100% works.

  deleteNodeFromList(list, (void*)a1);
  test = 0;
  if (*(int*)(list -> tail -> data) == 70)
  {
    test = 1;
  }
  issues += TEST(test, "Testing deleteNodeFromList on last element");

  test = 0;
  if (*(int*)getFromFront(list) != 7)
  {
    test = 1;
  }
  issues += TEST(test, "Testing getFromFront");

  test = 0;
  if (*(int*)getFromBack(list) != 7)
  {
    test = 1;
  }
  issues += TEST(test, "Testing getFromBack");

  printf("Testing printForward and printBackward:\n");
  printForward(list);
  printBackwards(list);

  deleteList(list);

  printf("\nREGRESSION AND EDGE CASE TESTS\n");

  //Edgecase [1/2]
  t1 = initInt(-2000000000);
  t2 = initInt(7);

  aList = initializeList(*printInt, *deleteInt, *compareInt);
  //Test: Creation of aList worked
  //Expected: aList != NULL
  testVar = 0;
  if (aList == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Intializing int list");


  aNode = initializeNode((void*) t1);
  //Test: Initializing node worked
  //Expected: aNode != NULL
  testVar = 0;
  if (aNode == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Initializing node");


  insertFront(aList, (void*)t1);
  //Test: insertFront worked
  //Expected: aList -> head != NULL
  testVar = 0;
  if (aList -> head == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertFront");


  insertBack(aList, (void*)t2);
  //Test: insertBack worked
  //Expected: aList -> tail != NULL
  testVar = 0;
  if (aList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertBack");

  //Edgecase [2/2]: Multiple insertBacks using same object
  insertBack(aList, (void*)t2);
  //Test: reinsertion of back works
  //Expected: aList -> tail != NULL
  testVar = 0;
  if (aList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing reinsertion of same variable into insertBack");


  deleteList(aList);
  //Test: deleteList
  //Expected: printForward prints "List is empty"
  testVar = 0;
  //It does
  issues += TEST(testVar, "Deleted list. printForward should not print anything: ");
  printForward(aList);


  aList = initializeList(*printInt, *deleteInt, *compareInt);
  //Test: Reinitialization of list worked
  //Expected: aList != NULL
  testVar = 0;
  if (aList == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Reinitialization of aList");

  t1 = initInt(-2000000000);
  insertSorted(aList, (void*)t1);
  //Test: insertSorted worked
  //Expected: aList -> tail != NULL
  testVar = 0;
  if (aList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertSorted");


  //Test: insertSorted worked
  //Expected: *(int*)(aList -> head -> data) == *t1
  testVar = 0;
  if ( *(int*)(aList -> head -> data) != *t1 )
  {
    printf("%d != %d", *(int*)(aList -> head -> data), *t1);
    testVar = 1;
  }
  issues += TEST(testVar, "Testing InsertSorted has the correct information");


  //EDGECASE TEST: insertSorted the same object multiple times
  insertSorted(aList, (void*)t1);
  //Expected: *(int*)(aList -> head -> data) == *(int*)(aList -> head -> next -> data)
  testVar = 0;
  if ( *(int*)(aList -> head -> data) != *(int*)(aList -> head -> next -> data) )
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking a second insertSorted of the same object worked and they have the same info");

  deleteList(aList);

  return issues;
}
