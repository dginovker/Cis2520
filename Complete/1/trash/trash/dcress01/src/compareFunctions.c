#include "../includes/compareFunctions.h"

int compareAscending(void* a, void* b)
{
  if(*(int*) a > *(int*) b)
  {
    return 1;
  }
  if(*(int*) a < *(int*) b)
  {
    return -1;
  }
  return 0;
}

int compareAscendingEvensBeforeOdd(void* a, void* b)
{
  if ((*(int*)a%2 == 0 && *(int*)b%2 == 0) || (*(int*)a%2 == 1 && *(int*)b%2 == 1))
  {
    return compareAscending(a, b);
  }
  else if (*(int*)a%2 == 0 && *(int*)b%2 == 1)
  {
    return -1;
  }
  return 1;
}

int compareDescending(void* a, void* b)
{
  return -compareAscending(a, b);
}

void swap (int *a, int *b)
{
  int tempa = *a;
  *a = *b;
  *b = tempa;
}
