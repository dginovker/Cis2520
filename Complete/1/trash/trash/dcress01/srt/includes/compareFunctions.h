#ifndef COMPAREFUNCTIONS_H
#define COMPAREFUNCTIONS_H

#include "../includes/compareFunctions.h"

/**
 * Create a typedef for a  Compare Function
 */
typedef int (*CompareFunc)(void* a, void* b);

int compareAscending(void* a, void* b);

int compareAscendingEvensBeforeOdd(void* a, void* b);

int compareDescending(void* a, void* b);

void swap (int *a, int *b);

#endif
