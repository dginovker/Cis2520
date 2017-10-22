#include "../includes/Test.h"
#include "../includes/priorityQueueTest.h"
#include "../includes/priorityQueueAPI.h"
#include <stdio.h>
#include <stdlib.h>

int compareInts(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void deleteNodeDummy (void *toBeDeleted)
{
  //DummyFunction
}

int testPriority()
{
  int issues = 0;
  int test;
  int a = 5, b = 9;

  PQ *queue = NULL;
  queue = createPQ(NULL, *deleteNodeDummy, *compareInts);
  insertPQ(queue, &a, a);
  test = 0;
  if ( *(int*)(((Node*)(peekPQ(queue))) -> data) != 5)
  {
    test = 1;
  }
  issues += TEST(test, "Testing the creation and insertion of an element into the priority queue");
  insertPQ(queue, &b, 30);
  test = 0;
  if ( ((Node*)(peekPQ(queue))) -> priorityValue != 5)
  {
    test = 1;
  }
  issues += TEST(test, "Testing that the priority queue can handle multiple ordered insertions, and testing peekPQ");

  popPQ(queue);
  test = 0;
  if ( ((Node*)(peekPQ(queue))) -> priorityValue == 5)
  {
    test = 1;
  }
  issues += TEST(test, "Testing popPQ and removePQ");

  test = 0;
  if (isEmptyPQ(queue))
  {
    test = 1;
  }
  issues += TEST(test, "Testing isEmptyPQ");

  test = 0;
  if (isEmptyPQ(queue))
  {
    test = 1;
  }
  issues += TEST(test, "Testing isEmptyPQ [2]");

  queue = destroyPQ(queue);
  test = 0;
  if (queue != NULL)
  {
    test = 1;
  }
  issues += TEST(test, "Testing destroyPQ");

  return issues;
}
