/**
 * @file priorityQueueAPI.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the function definitions of a priorityQueue
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../includes/priorityQueue.h"
#include "../includes/LinkedListAPI.h"

/**
 *Dummy head of the list. Contains no actual data on it beyond a pointer to the front and end of the list.
 **/
typedef struct PQHead{
    Node *head;
    Node *tail;
    void (*deleteNode)(void *toBeDeleted);
    int (*compare)(const void *first,const void *second);
    void (*printNode)(void *toBePrinted);
} PQ;

/**Function to point the list head to the appropriate functions. Allocates memory to the struct.
*@return pointer to the list head
*@param printFunction function pointer to print a single node of the priorityQueue
*@param deleteFunction function pointer to delete a single piece of data from the priorityQueue
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
PQ *createPQ(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));


/** Deletes the entire PQ, starting with the nodes, followed by the PQ itself.
*@pre 'PQ' type must exist and be used in order to keep track of the PQ.
*@param PQ pointer to the PQ-type dummy node
**/
void *destroyPQ(PQ *aList);


/** Inserts a node into the list, ordered by the priority
*@pre 'PQ' type must exist and be used in order to keep track of the PQ
*@param list pointer to the PQ dummy node
**/
void insertPQ(PQ *list, void* toBeAdded, int priority);


/** Removes element at the top of the PQ
*@pre 'PQ' type must exist and be used in order to keep track of the PQ.
*@param list pointer to the PQ dummy node
**/
Node *popPQ(PQ *list);


/** Returns the element at the top of the PQ
*@pre 'PQ' type must exist and be used in order to keep track of the PQ.
*@param list pointer to the PQ dummy node
**/
Node *peekPQ(PQ *list);

/** Removes the element with the info of "data" from the PQ, if it exists
*@pre 'PQ' type must exist and be used in order to keep track of the PQ.
*@param list pointer to the PQ dummy node
*@param void pointer to the data to be removed
**/
void removePQ(PQ *list, void* data);

/** Returns true/false depending on whether or not the PQ has any elements
*@pre 'PQ' type must exist and be used in order to keep track of the PQ.
*@param list pointer to the PQ dummy node
*@retrun 1 if the list is empty, 0 otherwise
**/
int isEmptyPQ(PQ *list);

#endif
