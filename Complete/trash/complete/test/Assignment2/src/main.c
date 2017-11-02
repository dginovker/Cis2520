#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/parseFile.h"
#include "../includes/priorityQueueAPI.h"
#include "../includes/patient.h"
#include "../includes/simulation.h"

int main(int argc, char **argv)
{
  char line[80];
  PQ *hospitalPQ = NULL;
  List *inputList = NULL;
  FILE *fp = NULL;
  int starve = 0;
  int decreasePriority=5;

  hospitalPQ = createPQ(*printPatient, *deletePatient, NULL);
  inputList = initializeList(*printAnswer, *deletePatient, NULL);

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

  printf("The following patients have been read in:\n");

  while (fgets(line, 80, fp) != NULL)
  {
    if (starve%5 == 0)
    {
      decreasePriority--;
    }
    starve++;
    insertBack(inputList, (void*)getPatient(line));
    insertPQ(hospitalPQ, getFromBack(inputList), priorityNumber(line) - decreasePriority);

    hospitalPQ -> printNode ((void*)getPatient(line));
  }

  printf("Note: to prevent starvation, an aging algorithm has been implemented and patients added at the end have a chance of being pushed slightly higher in the list.\n");

  getMorePatients(hospitalPQ, starve, decreasePriority);


  runSimulation(hospitalPQ, inputList);

  hospitalPQ = destroyPQ(hospitalPQ);
  inputList = deleteList(inputList);

  printf("Bye!\n");
  return 0;
}
