#include <stdio.h>
#include <stdlib.h>
#include "../includes/priorityQueueAPI.h"
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
  return deleteList((List*)aList);
}

void insertPQ(PQ *list, void* toBeAdded, int priority)
{
  Node *a = NULL;
  Node *current = NULL;
  Node *previous = NULL;
  a = malloc(sizeof(Node));
  a -> data = toBeAdded;
  a -> priorityValue = priority;

  if (list -> head == NULL)//The queue is empty
  {
    a -> next = NULL;
    a -> previous = NULL;
    list -> head = a;
    list -> tail = a;
    return;
  }
  if (a -> priorityValue < list -> head -> priorityValue)//When the new priority value is less than the head's priority
  {
    a -> next = list -> head;
    a -> previous = NULL;
    list -> head -> previous = a;
    list -> head = a;
    return;
  }
  previous = list -> head;//Previous = list head
  while (previous -> next != NULL)//Previous -> next != Null (list head's -> next != null)
  {
    current = previous -> next;
    if (a -> priorityValue < current -> priorityValue)
    {
      previous -> next = a;
      a -> previous = previous;
      a -> next = current;
      current -> previous = a;
      break;
    }
    previous = current;
  }
  if (previous -> next == NULL) //If the previous next == NULL: We reached the end, therefore add to end
  {
    previous -> next = a;
    a -> previous = previous;
    a -> next = NULL;
    list -> tail = a;
  }
}

Node *popPQ(PQ *list)
{
  Node* data = malloc(sizeof(Node));
  data = list -> head;
  list -> head = list -> head -> next;
  removePQ(list, data);
  return data;
}

Node *peekPQ(PQ *list)
{
  return list -> head;
}

void removePQ(PQ *list, void* data)
{
  deleteNodeFromList((List*)list, data);
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
