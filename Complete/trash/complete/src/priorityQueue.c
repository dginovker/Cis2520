#include <stdio.h>
#include <stdlib.h>
#include "../includes/priorityQueue.h"
#include "../includes/LinkedListAPI.h"

PQ *createPQ(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
  PQ *a = NULL;

  a = malloc(sizeof(List));
  a -> head = NULL;
  a -> tail = NULL;
  a -> deleteNode = deleteFunction;
  a -> compare = compareFunction;
  a -> printNode = printFunction;

  return a;
}

void *destroyPQ(PQ *aList)
{
  return deleteList(aList);
}

void insertPQ(PQ *list, void* toBeAdded, int priority)
{
  Node *a = NULL;
  Node *current = NULL;
  Node *previous = NULL;
  a = malloc(sizeof(Node));
  a -> data = toBeAdded;
  a -> priorityValue = priority;

  if (list -> head == NULL)
  {
    a -> next = NULL;
    a -> previous = NULL;
    list -> head = a;
    list -> tail = a;
    return;
  }
  if (list -> head -> priorityValue < a -> priorityValue)
  {
    a -> next = list -> head;
    a -> previous = NULL;
    list -> head -> previous = a;
    list -> head = a;
    return;
  }
  previous = list -> head;
  while (previous -> next != NULL)
  {
    current = previous -> next;
    if (current -> priorityValue < a -> priorityValue)
    {
      previous -> next = a;
      a -> previous = previous;
      a -> next = current;
      current -> previous = a;
      break;
    }
    previous = current;
  }
  if (previous -> next == NULL)
  {
    previous -> next = a;
    a -> previous = previous;
    a -> next = NULL;
    list -> tail = a;
  }
}

void *popPQ(PQ *list)
{
  void* data = malloc(sizeof(Node));
  data = getFromFront(list);
  removePQ(list, data);
  return data;
}

void *peekPQ(PQ *list)
{
  void* data = malloc(sizeof(Node));
  data = getFromFront(list);
  return data;
}

void removePQ(PQ *list, void* data)
{
  deleteNodeFromList(list, data);
}

int isEmptyPQ(PQ *list)
{
  void *data = peekPQ(list);
  if (data == NULL)
  {
    return 1;
  }
  return 0;
}
