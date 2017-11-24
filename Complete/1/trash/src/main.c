#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/compareFunctions.h"
#include "../includes/sortFunctions.h"

int main(int argc, char ** argv)
{
  int max = 20;
  char userInput[5000];
  int userChoice = 0;
	int array[max];
  CompareFunc comparer;
  SortAlgorithm sorter;

  printf("Please input the number of integers in the array: ");
  fgets(userInput, 5000, stdin);
  max = atoi(userInput);

  printf("Please input %d integers, each seperated by a newline:\n", max);
  for (int i = 0; i < max; i++)
  {
    printf("Integer %d: ", i+1);
    fgets(userInput, 5000, stdin);
    array[i] = atoi(userInput);
  }

  while (userChoice != 7)
  {
    printf("Sorting Menu System:\n");
    printf("\n\t1) Bubble Sort (increasing order)");
    printf("\n\t2) Bubble Sort (decreasing order)");
    printf("\n\t3) Bubble Sort (increasing order - even numbers before odd numbers)");
    printf("\n\t4) Insertion Sort (increasing order)");
    printf("\n\t5) Insertion Sort (decreasing order)");
    printf("\n\t6) Insertion Sort (increasing order - even numbers before odd numbers)");
    printf("\n\t7) Quit");

    printf("\n\n\tSelection: ");

    fgets(userInput, 5000, stdin);

    if (userInput[0] == '\n')
    {
      //They didn't enter anything and it's going to seg fault
      printf("No valid input recieved, assuming user wishes to quit.\n");
      return 0;
    }
    userChoice = atoi(userInput);

    switch (userInput[0])
    {
      case '1':
        comparer = *compareAscending;
        sorter = *bubbleSortFunction;
        break;
      case '2':
        comparer = *compareDescending;
        sorter = *bubbleSortFunction;
        break;
      case '3':
        comparer = *compareAscendingEvensBeforeOdd;
        sorter = *bubbleSortFunction;
        break;
      case '4':
        comparer = *compareAscending;
        sorter = *insertionSortFunction;
        break;
      case '5':
        comparer = *compareDescending;
        sorter = *insertionSortFunction;
        break;
      case '6':
        comparer = *compareAscendingEvensBeforeOdd;
        sorter = *insertionSortFunction;
        break;
      default:
        printf("You didn't enter a valid option!\n");
    }

    sort(userInput, sorter, array, max, comparer);
  }


	return 0;
}
