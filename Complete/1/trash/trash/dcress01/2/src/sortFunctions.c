#include "../includes/sortFunctions.h"
#include <stdio.h>

void insertionSortFunction (int* container, int length, CompareFunc cf)
{
  int d;
  for (int i = 1 ; i < length; i++) {
    d = i;

    while ( d > 0 && cf ((void*)&container[d], (void*)&container[d-1]) < 0 )
    {
      swap((void*)&container[d], (void*)&container[d-1]);
      d--;
    }
  }
}

void bubbleSortFunction(int* container, int length, CompareFunc cf)
{
  for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
      if ( cf( (void*)&container[j], (void*)&container[j+1]) > 0)
			{
        swap((void*)&container[j], (void*)&container[j+1]);
      }
		}
	}
}

/**
 * Print an array of integers with a specific length.
 */
void printArray( int* arr, int length )
{
	for(int i= 0 ; i < length; i++ )
		printf("%d ", arr[i]);
	printf("\n");
}

/***
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)
{
  printf("Menu selection: %s\n", menuSelection);

  sorter(array, length, compare);

  printArray(array, length);
}
