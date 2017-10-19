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
  int testVar;
  int *t1, *t2, *t3;
  List *aList, *aList2;
  Node *aNode = NULL;

  //Edgecase [1/2]
  t1 = initInt(-2147483648);
  t2 = initInt(7);
  t3 = initInt(3);

  aList = initializeList(*printInt, *deleteInt, *compareInt);
  //Test: Creation of aList worked
  //Expected: aList != NULL
  testVar = 0;
  if (aList == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Intializing book list");


  aNode = initializeNode((void*) t1);
  //Test: Initializing node worked
  //Expected: aNode != NULL
  testVar = 0;
  if (aNode == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Initializing node");


  insertFront(aList, t1);
  //Test: insertFront worked
  //Expected: aList -> head != NULL
  testVar = 0;
  if (aList -> head == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertFront");


  insertBack(aList, t2);
  //Test: insertBack worked
  //Expected: aList -> tail != NULL
  testVar = 0;
  if (aList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertBack");

  //Edgecase [2/2]: Multiple insertBacks using same object
  insertBack(aList, t2);
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
  issues += TEST(testVar, "Deleted list. printForward prints \"List is empty.\": ");
  printForward(aList);


  aList2 = initializeList(*printInt, *deleteInt, *compareInt);
  //Test: Reinitialization of list worked
  //Expected: aList != NULL
  testVar = 0;
  if (aList2 == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Reinitialization of aList");


  insertFront(aList2, t3);
  insertBack(aList2, t2);
  insertSorted(aList2, (void*)t1);
  //Test: insertSorted worked
  //Expected: aList -> tail != NULL
  testVar = 0;
  if (aList2 -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertSorted");


  //Test: insertSorted worked
  //Expected: ((Book*)(aList -> head -> data)) -> price == t1 -> price
  testVar = 0;
  if ( *(int*)(aList -> head -> data) != *t1 )
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing InsertSorted has the correct information");


  //EDGECASE TEST: insertSorted the same object multiple times
  insertSorted(aList, t1);
  //Expected: *(int*)(aList -> head -> data) != *(int*)(aList -> head -> next -> data)
  testVar = 0;
  if ( *(int*)(aList -> head -> data) != *(int*)(aList -> head -> next -> data) )
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking a second insertSorted of the same object worked and they have the same info");

  insertSorted(aList, (void*)t3);
  insertSorted(aList, (void*)t2);


  //Test: getFromFront worked
  //Expected: getFromFront will retrieve 3
  testVar = 0;
  if (*(int*)getFromFront(aList) != -2147483648)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if the getFromFront retrieves the correct object");


  //Test: getFromBack worked
  //Expected: getFromBack will retrieve 7
  testVar = 0;
  if (*(int*)getFromBack(aList) != 7)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if getFromBack retrieves the correct object");


  testVar = 0;
  if (aList -> compare(getFromFront(aList), getFromBack(aList)) >= 0)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking to see if the compare function works by comparing the first and last element in a sorted list");


  deleteNodeFromList(aList, aList -> head -> next -> data);
  //Test: deleteNodeFromList worked
  //Expected: first element will be deleted. Since the first two elements were the same, they shouldn't be the same anymore.
  testVar = 0;
  if (*(int*)getFromFront(aList) == *(int*)(aList -> head -> next -> data))
  {
    //This works because there were initially two "3"s at the start of the list. We killed one.
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if deleteNodeFromList works");


  printf("Finishing off by quickly printing the list both forwards, backwards then deleteing the list -- program should not crash\n");
  //Test: printForward works
  //Expected: prints the list forwards without any errors
  printf("Print fowards:\n");
  printForward(aList);
  //Test: printBackwards works
  //Expected: prints the list backwards without any errors
  printf("Print backwards:\n");
  printBackwards(aList);
  //Test: deleteList (and deleteListNode and deleteNodeFromList works)
  //Expected: aList is deleted, no errors generated and the next printForwards prints "List is Empty"
  deleteList(aList);
  printf("Should print \"List is empty\": ");
  printForward(aList);

  return issues;
}
