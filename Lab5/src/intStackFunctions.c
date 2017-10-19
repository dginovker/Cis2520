#include "../includes/intStackFunctions.h"

void intPrint(void* data)
{
  printf("%d ", *(int*)data);
}

int intCompare(const void* a, const void* b)
{
  return *(int*)a - *(int*)b;
}

void *initVoid(int a)
{
  int *b = NULL;
  b = malloc(sizeof(int));
  *b = a;

  return (void*)b;
}
