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
  int modifiedA = *(int*)a;
  int modifiedB = *(int*)b;

  if (modifiedA%2 == 0)
  {
    modifiedA -= 1000000;
  }
  if (modifiedB%2 == 0)
  {
    modifiedB -=1000000;
  }
  if(modifiedA > modifiedB)
  {
    return 1;
  }
  if(modifiedA < modifiedB)
  {
    return -1;
  }
  return 0;

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
