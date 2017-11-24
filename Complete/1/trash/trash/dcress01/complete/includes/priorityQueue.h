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


PQ *createPQ(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

void *destroyPQ(PQ *aList);

void insertPQ(PQ *list, void* toBeAdded, int priority);

void *popPQ(PQ *list);

void *peekPQ(PQ *list);

void removePQ(PQ *list, void* data);

int isEmptyPQ(PQ *list);

#endif
