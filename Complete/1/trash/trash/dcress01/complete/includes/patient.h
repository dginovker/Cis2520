/**
 * @file LinkedListAPI.h
 * @author Michael Ellis
 * @date January 2017
 * @brief File containing the function definitions of a doubly linked list
 */


#ifndef PATIENT_H
#define PATIENT_H

#include "../includes/priorityQueueAPI.h"

/**
* Patient structure
* Note that while the patient priority can be stored here, it's also stored in the Node
**/
typedef struct patient{
  char *patientID;
  int priority;
  char *symptomCode;
  int timeFinished;
} Patient;

/**
 *Extracts a patient object from a string
 *@returns a pointer to the patient extracted
 *@param string to extract from
 **/
Patient *getPatient(char *string);

/**
 *Prints all the information about a patient, except the finished time
 *@return void
 *@param patient to be printed
 **/
void printPatient(void *a);

/**
 *Prints all the information about a patient, including the finish time
 *@return void
 *@param patient to be printed
 **/
void printAnswer(void *a);

/**
 *Deletes and frees a patient from a PQ
 *@return void
 *@param patient to be deleted
 **/
void deletePatient(void *a);

/**
 *Asks the user if they want to add more patients
 *Recursively adds more patients to the PQ
 *@return void
 *@param patient list to be appended
 **/
void getMorePatients(PQ *a, int starve, int decreasePriority);

#endif
