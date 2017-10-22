#include "../includes/patient.h"
#include "../includes/parseFile.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Patient *getPatient(char *string)
{
  Patient *a = NULL;
  a = malloc(sizeof(Patient));

  a -> priority = priorityNumber(string);
  a -> patientID = clientID(string);
  a -> symptomCode = clientSymptomCode(string);

  return a;
}

void printPatient(void *a)
{
  printf("%s", ((Patient*)a) -> patientID);
  printf("\t\t%d", ((Patient*)a) -> priority);
  printf("\t\t\t%s", ((Patient*)a) -> symptomCode);
}

void deletePatient(void *a)
{
  void *temp = a;
  if (a)
  {
    free (((Patient*)temp) -> patientID);
    free (((Patient*)temp) -> symptomCode);
    free (((Patient*)temp));
  }
}

void getMorePatients(PQ *a, int starve, int decreasePriority)
{
  int priorityNumber;
  Patient *b = NULL;
  char line[80];
  char *patientID, *symptomCode;
  b = malloc(sizeof(Patient));

  if (starve%5 == 0)
  {
    decreasePriority--;
  }
  starve++;

  printf("Would you like to enter in any more records? [y/n]");
  fgets(line, 80, stdin);
  if (line[0] == 'y' || line[0] == 'Y')
  {
    printf("Enter the priority number for the patient: ");
    fgets(line, 80, stdin);
    priorityNumber = atoi(line);

    printf("Enter the patient ID: ");
    fgets(line, 80, stdin);
    line[strlen(line)-1] = 0;
    patientID = malloc(sizeof(char) * (strlen(line) + 1 ));
    strcpy(patientID, line);

    printf("Enter the symptom code for the patient: ");
    fgets(line, 80, stdin);
    line[strlen(line)-1] = 0;
    symptomCode = malloc(sizeof(char) * (strlen(line) + 1 ));
    strcpy(symptomCode, line);

    b -> priority = priorityNumber;
    b -> patientID = patientID;
    b -> symptomCode = symptomCode;

    printf("Added the following patient: ");
    a -> printNode(b);
    printf("\n");

    insertPQ(a, b, priorityNumber - decreasePriority);
    getMorePatients(a, starve, decreasePriority);
  }
}
