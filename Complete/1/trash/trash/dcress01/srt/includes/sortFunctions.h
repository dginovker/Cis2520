#ifndef SORTFUNCTIONS_H
#define SORTFUNCTIONS_H

#include "compareFunctions.h"

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

void insertionSortFunction (int* container, int length, CompareFunc cf);

void bubbleSortFunction(int* container, int length, CompareFunc cf);

void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare);

void printArray( int* arr, int length );

#endif
