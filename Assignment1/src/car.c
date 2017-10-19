#include <stdio.h>
#include <stdlib.h>
#include "../includes/car.h"

int compareCar(const void* a, const void* b)
{
  if (((Car*)a) -> TTI < ((Car*)b) -> TTI)
  {
    return 1;
  }
  if (((Car*)a) -> TTI == ((Car*)b) -> TTI)
  {
    return 0;
  }
  return -1;
}

void printCar(void* a)
{
  printf("Car direction: %c -- Time to arrive at intersection: %lf\n", ((Car*)a) -> dir, ((Car*)a) -> TTI);
}

void deleteCar(void *a)
{
  //Nothing to free
}

Car *initCar(int TTI, char dir)
{
  Car *a = NULL;
  a = malloc(sizeof(Car));
  a -> TTI = TTI;
  a -> dir = dir;
  return a;
}
