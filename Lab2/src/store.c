#include <stdlib.h>
#include "../includes/store.h"

void displayStore(Store* s)
{
  s -> printFunc(s -> container);
}

Store *createStore(void *container, void (*functionPointer)(void *container))
{
  Store *s = NULL;
  s = malloc(sizeof(Store));
  s -> container = container;
  s -> printFunc = functionPointer;
  return s;
}

void rebrandStore(Store *s, void *container, void (*functionPointer)(void *container))
{
  s -> container = container;
  s -> printFunc = functionPointer;
}
