#include "../includes/Stack.h"
#include <stdlib.h>

Stack *createStack(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second))
{
  Stack *a = NULL;
  a = malloc(sizeof(Stack));
  a -> count = 0;

  a -> list = initializeList(*printFunction, *deleteFunction, *compareFunction);

  return a;
}

void push(Stack *s, void *data)
{
  Node *a = NULL;
  if (!s)
  {
    return;
  }
  a = malloc(sizeof(Node));

  a -> data = data;
  insertBack(s -> list, data);
  s -> count ++;
}

void pop(Stack *s)
{
  int result = 0;
  if (!s)
  {
    return;
  }
  if (count(s) == 0)
  {
    return;
  }
  void *data = top(s);
  List *a = s -> list;
  deleteNodeFromList(a, data);
  if (result == 0)
  {
    s -> count --;
  }
}

void *top(Stack *s)
{
  return getFromBack(s -> list);
}

int count (Stack *s)
{
  return s -> count;
}

int freeStack (Stack *s)
{
  deleteList(s -> list);
  free(s);
  return 0;
}
