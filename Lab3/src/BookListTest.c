#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/Book.h"
#include "../includes/BookListTest.h"
#include "../includes/Test.h"

void deleteBookNode(void *toBeDeleted)
{
  void *temp = NULL;
  temp = toBeDeleted;
  if (temp)
  {
    free(temp);
  }
}

int compareBook(const void* first, const void* second)
{

  if (((Book*)first) -> price < ((Book*)second) -> price)
  {
    return -1;
  }
  else if (((Book*)first) -> price > ((Book*)second) -> price)
  {
    return 1;
  }
  return 0;
}

int bookTest()
{
  int issues = 0;
  int testVar;
  List *aBookList = initializeList(*printBook, *deleteBookNode, *compareBook);
  Book *b1 = createBook("BookNook", 19.99);
  //Edgecases in name declaration [1/3]
  Book *b2 = createBook("a very very very very very very very very very very very very very very very very very very very very long book name", 1.00);
  Book *b3 = createBook("a\nquestionable\t BookName", -0.00);
  Node *aNode = NULL;

  //Test: Creation of aBookList worked
  //Expected: aBookList != NULL
  testVar = 0;
  if (aBookList == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Intializing book list");


  aNode = initializeNode((void*) b1);
  //Test: Initializing node worked
  //Expected: aNode != NULL
  testVar = 0;
  if (aNode == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Initializing node");


  insertFront(aBookList, b1);
  //Test: insertFront worked
  //Expected: aBookList -> head != NULL
  testVar = 0;
  if (aBookList -> head == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertFront");


  insertBack(aBookList, b2);
  //Test: insertBack worked
  //Expected: aBookList -> tail != NULL
  testVar = 0;
  if (aBookList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertBack");


  deleteList(aBookList);
  //Test: deleteList
  //Expected: printForward prints "List is empty"
  testVar = 0;
  //It does
  issues += TEST(testVar, "Deleted list. printForward prints \"List is empty.\": ");
  printForward(aBookList);


  //Edgecase [2/3]: Reinitialization to same bookList pointer
  aBookList = initializeList(*printBook, *deleteBookNode, *compareBook);
  //Test: Reinitialization of list worked
  //Expected: aBookList != NULL
  testVar = 0;
  if (aBookList == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Reinitialization of aBookList");


  insertSorted(aBookList, b1);
  //Test: insertSorted worked
  //Expected: aBookList -> tail != NULL
  testVar = 0;
  if (aBookList -> tail == NULL)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing insertSorted inserted a node");


  //Test: insertSorted worked
  //Expected: ((Book*)(aBookList -> head -> data)) -> price == b1 -> price
  testVar = 0;
  if ( ((Book*)(aBookList -> head -> data)) -> price != b1 -> price )
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Testing InsertSorted has the correct information");


  //Edgecase [3/3]: insertSorted the same object multiple times
  insertSorted(aBookList, b1);
  //Test: insertSorted the same object multiple times
  //Expected: ((Book*)(aBookList -> head -> data)) -> name equals ((Book*)(aBookList -> head -> next -> data)) -> name
  testVar = 0;
  if ( fabs( ((Book*)(aBookList -> head -> data)) -> price - ((Book*)(aBookList -> head -> next -> data)) -> price ) > 0.001 )
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking a second insertSorted of the same object worked and they have the same info");

  //Adding more elements to play with
  insertSorted(aBookList, b3);
  insertSorted(aBookList, b2);

  //Test: getFromFront worked
  //Expected: getFromFront -> price == 0 since it's ordered by price from down going up
  testVar = 0;
  if (((Book*)getFromFront(aBookList)) -> price != 0.0)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if the getFromFront retrieves the correct object");


  //Test: getFromBack worked
  //Expected: getFromBack -> price == 19.99
  testVar = 0;
  if (((Book*)getFromBack(aBookList)) -> price != 19.99)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if getFromBack retrieves the correct object");


  testVar = 0;
  if (aBookList -> compare(getFromFront(aBookList), getFromBack(aBookList)) >= 0)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking to see if the compare function works by comparing the first and last element in a sorted list");


  deleteNodeFromList(aBookList, aBookList -> head -> data);
  //Test: deleteNodeFromList worked
  //Expected: First element will be deleted. Since the first element had a price of -0.00, it shouldn't have that anymore.
  testVar = 0;
  if (((Book*)getFromFront(aBookList)) -> price == 0.0)
  {
    testVar = 1;
  }
  issues += TEST(testVar, "Checking if deleteNodeFromList works");


  printf("Finishing off by quickly printing the list both forwards, backwards then deleteing the list -- program should not crash\n");
  //Test: printForward works
  //Expected: prints the list forwards without any errors
  printf("Print fowards:\n");
  printForward(aBookList);
  //Test: printBackwards works
  //Expected: prints the list backwards without any errors
  printf("Print backwards:\n");
  printBackwards(aBookList);

  //Test: deleteList (and deleteListNode)
  //Expected: aBookList is deleted, no errors generated and the next printForwards prints "List is Empty"
  printf("Delete list");
  deleteList(aBookList);
  printf("Should print \"List is empty\"..");
  printForward(aBookList);
  issues += TEST(testVar, "Testing deleteList (second time)");

  return issues;
}
