#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/car.h"
#include "../includes/LinkedListAPI.h"
#include "../includes/readCars.h"

void addCarToList(List *list, char line[])
{
  Car *aCar = NULL;
  aCar = initCar(atof(&line[2]), line[0]);
  insertSorted(list, aCar);
}
