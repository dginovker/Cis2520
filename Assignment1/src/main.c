#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/simulation.h"
#include "../includes/readCars.h"
#include "../includes/car.h"

int main(int argc, char *argv[])
{
  List *north = NULL, *east = NULL, *south = NULL, *west = NULL;
  char line[80];
  FILE *fp = NULL;

  north = initializeList(*printCar, *deleteCar, *compareCar);
  east = initializeList(*printCar, *deleteCar, *compareCar);
  south = initializeList(*printCar, *deleteCar, *compareCar);
  west = initializeList(*printCar, *deleteCar, *compareCar);

  if (argc < 2)
  {
    printf("Error: You must supply a file name as parameter.\n");
    return 0;
  }
  fp = fopen(argv[1], "r");
  if (!fp)
  {
    printf("Invalid file name. Terminating.\n");
    return 0;
  }
  while (fgets(line, 80, fp) != NULL)
  {
    line[strlen(line)] = 0;
    switch (line[0])
    {
      case 'N':
      case 'n':
        addCarToList(north, &line[2]);
      break;
      case 'E':
      case 'e':
        addCarToList(east, &line[2]);
      break;
      case 'S':
      case 's':
        addCarToList(south, &line[2]);
      break;
      case 'W':
      case 'w':
        addCarToList(west, &line[2]);
      break;
    }
  }

  runSimulation(north, east, south, west);

  printf("Bye!\n");
  return 0;
}
