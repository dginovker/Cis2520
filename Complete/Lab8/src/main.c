#include<stdio.h>

/**
 * Create a typedef for a  Compare Function
 */
typedef int (*CompareFunc)(void* a, void* b);

/**
 * Create a typedef for a Sort Algorithm of an array
 */
typedef void (*SortAlgorithm) (int* container, int length,  CompareFunc cf);

void swap (int *a, int *b)
{
  int tempa = *a;
  *a = *b;
  *b = tempa;
}

void insertionSortFunction (int* container, int length, CompareFunc cf)
{
  int lowstValue = 0;
  int smallestNum = container[0];
  for (minIndex = 0; minIndex < length; minIndex ++)
  {
    for (int i = minIndex; i < length; i++)
    {
      if (cf(smallestNum, container[i]))
      {
        smallestNum = container[i];
      }
    }
    swap(container[lowestValue], container[i])
  }
}

void bubbleSortFunction(int* container, int length, CompareFunc cf)
{
  for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ( cf(container[i], container[j]) )
			{
				swap(container[i],container[j])
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
 * NOTE: You will implement this function, it will be used to call all sorting algorithms.
 *      It will also output the all the information required by the output section of the lab.
 *
 * menuSelection is the text for the menu option that was selected.
 * sorter -> is the sorting function
 * array -> is the input array given by the user
 * length-> is the length of the array
 * compare -> is a comparison function pointer.
 */
void sort( char* menuSelection, SortAlgorithm sorter, int* array, int length, CompareFunc compare)


int main(int argc, char ** argv )
{
	return 0;
}
