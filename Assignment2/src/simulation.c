#include "../includes/simulation.h"
#include "../includes/priorityQueueAPI.h"
#include "../includes/patient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getTimeReq(char *string)
{
  if (!strcmp(string, "CV"))
  {
    return 5+1;
  }
  if (!strcmp(string, "HN"))
  {
    return 3+1;
  }
  if (!strcmp(string, "EV"))
  {
    return 10+1;
  }
  if (!strcmp(string, "GI"))
  {
    return 2+1;
  }
  if (!strcmp(string, "MH"))
  {
    return 5+1;
  }
  if (!strcmp(string, "NC"))
  {
    return 5+1;
  }
  if (!strcmp(string, "EC"))
  {
    return 1+1;
  }
  if (!strcmp(string, "RC"))
  {
    return 1+1;
  }
  if (!strcmp(string, "SK"))
  {
    return 2+1;
  }
  if (!strcmp(string, "SA"))
  {
    return 7+1;
  }
  if (!strcmp(string, "TR"))
  {
    return 4+1;
  }

  return 0;
}

void runSimulation(PQ* patientList)
{
  int clock = 0;

  printf("\n---- BEGIN SIMULATION ----\n");
  printf("Patient ID\tPriority\tSymptom Code\tTime Finished\n");

  while (1)
  {
    if (peekPQ(patientList) == NULL)
    {
      return;
    }
    else
    {
      patientList -> printNode(peekPQ(patientList) -> data);
      //hospitalPQ -> printNode ((void*)getPatient(line));
      clock += getTimeReq( ((Patient*)(peekPQ(patientList) -> data)) -> symptomCode);
      popPQ(patientList);
      printf("\t%d\n", clock);
    }
  }
}
