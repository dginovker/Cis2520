#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
  List *a = NULL;

  a = malloc(sizeof(List));
  a -> head = NULL;
  a -> tail = NULL;
  a -> deleteNode = deleteFunction;
  a -> compare = compareFunction;
  a -> printNode = printFunction;

  return a;
}

Node *initializeNode (void *data)
{
  Node *a = NULL;
  a = malloc(sizeof(Node));
  a -> data = data;
  a -> previous = NULL;
  a -> next = NULL;
  return a;
}

void insertFront(List *list, void *toBeInserted)
{
  Node *a = NULL;
  a = malloc(sizeof(Node));
  a -> data = toBeInserted;
  if (list -> head != NULL)
  {
    a -> next = list -> head;
    list -> head -> previous = a;
    list -> head = a;
  }
  else
  {
    list -> head = a;
    list -> tail = a;
    a -> next = NULL;
    a -> previous = NULL;
  }
}

void insertBack(List *list, void *toBeInserted)
{
  Node *a = NULL;
  a = malloc(sizeof(Node));
  a -> data = toBeInserted;
  if (list -> tail != NULL)
  {
    list -> tail -> next = a;
    a -> previous = list -> tail;
    list -> tail = a;
  }
  else
  {
    list -> head = a;
    list -> tail = a;
    a -> next = NULL;
    a -> previous = NULL;
  }
}

void deleteList(List *list)
{
  Node *temp;
  while (list -> head != NULL)
  {
    temp = list -> head;
    list -> head = list -> head -> next;
    //Delete the info inside the node, then free the node
    list -> deleteNode(temp -> data);
    free(temp);
    //printf("Element Deleted.\n");
  }
  free(list);
  list = NULL;
}

void insertSorted(List *list, void *toBeAdded)
{
  Node *a = NULL;
  Node *current = NULL;
  Node *previous = NULL;
  a = malloc(sizeof(Node));
  a -> data = toBeAdded;

  if (list -> head == NULL)
  {
    a -> next = NULL;
    a -> previous = NULL;
    list -> head = a;
    list -> tail = a;
    return;
  }
  if (list -> compare(list -> head -> data, a -> data) < 0)
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
    if (list -> compare(current -> data, a -> data) < 0)
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

int deleteNodeFromList(List *list, void *toBeDeleted)
{
  Node *current = NULL;
  if (list == NULL)
  {
    return 1;
  }
  current = list -> head;
  if (current == NULL)
  {
    return 1;
  }
  while (current != NULL)
  {
    if (current -> data == toBeDeleted)
    {
      if (current -> previous != NULL)
      {
        current -> previous -> next = current -> next;
      }
      else
      {
        list -> head = current -> next;
      }
      if (current -> next != NULL)
      {
        current -> next -> previous = current -> previous;
      }
      else
      {
        list -> tail = current -> previous;
      }
      if (list -> deleteNode != NULL)
      {
        list -> deleteNode(toBeDeleted);
      }
      free(current);
      return 0;
    }
    current = current -> next;
  }

  printf("g");
  return -1;
}

void *getFromFront(List *list)
{
  if (list -> head == NULL)
  {
    return NULL;
  }
  return list -> head -> data;
}

void *getFromBack(List *list)
{
  if (list -> tail == NULL)
  {
    return NULL;
  }
  return list -> tail -> data;
}

void printForward(List *list)
{
  Node *current = NULL;
  current = list -> head;
  while (current)
  {
    list -> printNode(current -> data);
    current = current -> next;
  }
}

void printBackwards(List *list)
{
  Node *current = NULL;
  current = list -> tail;
  while (current)
  {
    list -> printNode(current -> data);
    current = current -> previous;
  }
}
