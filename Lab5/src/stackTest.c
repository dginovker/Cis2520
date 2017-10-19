#include "../includes/Stack.h"
#include "../includes/Test.h"
#include <stdlib.h>
#include <stdio.h>

int stackTest()
{
  int test;
  int issues = 0;
  Stack *s = NULL;

  //Edgecase [1/3]: Testing the initialization of the stack with all Null pointers handed in
  //Expected: s is created with memory allocated to it (and isn't NULL)
  s = createStack(NULL, NULL, NULL);
  test = 0;
  if (!s)
  {
    test = 1;
  }
  issues += TEST(test, "Testing the initialization of stack with all NULL pointers (EDGECASE)");

  //Testing the freeing of a stack
  //Expected: freeStack returns 0
  test = 0;
  if (freeStack(s) != 0)
  {
    test = 1;
  }
  issues += TEST(test, "Testing the freeing of our stack");

  //Edgecase [2/3]: Reinitialization of stack with some function pointers
  //Expected: s is created with no issues
  s = createStack(*printInt, NULL, NULL);
  test = 0;
  if (!s)
  {
    test = 1;
  }
  issues += TEST(test, "Testing the REinitialization of stack with some valid function pointers (EDGECASE)");

  int *a = malloc(sizeof(int));
  *a = 7;
  //Testing pushing an element onto the stack
  //Expected: Number 7 is now at the top of the stack
  push(s, (void*)a);
  test = 0;
  if (*(int*)top(s) != *a)
  {
    test = 1;
  }
  issues += TEST(test, "Checking if putting the integer 7 on top of the stack works (Push & Top)");

  //Testing if count returns 1
  test = 0;
  if (count(s) != 1)
  {
    test = 1;
  }
  issues += TEST(test, "Checking if the stack count returns 1");

  //Testing the pop of the stack
  //Expected: Count will return a zero
  pop(s);
  test = 0;
  if (count(s) != 0)
  {
    test = 1;
  }
  issues += TEST(test, "Checking if the stack count returns 0");

  //EDGECASE [3/3]: Testing the pop of an empty stack
  //Expected: Count will return zero still and program will not crash
  pop(s);
  test = 0;
  if (count(s) != 0)
  {
    test = 1;
  }
  issues += TEST(test, "Checking if the ADT can handle popping an empty stack (EDGECASE)");

  return issues;
}
