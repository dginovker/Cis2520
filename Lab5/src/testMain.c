#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/intListTest.h"
#include "../includes/stackTest.h"

int main()
{
  int intTestsFailed;
  int stackTestsFailed;

  intTestsFailed = intTest();
  stackTestsFailed = stackTest();

  if (stackTestsFailed == 0)
  {
    printf("\nALL STACK TESTS PASSED\n");
  }

  if (intTestsFailed == 0)
  {
    printf("\nALL INT TESTS PASSED\n");
  }

  printf("----------------------\n");
  printf("TOTAL TESTS FAILED: %d\n", intTestsFailed + stackTestsFailed);

  if (intTestsFailed + stackTestsFailed == 0)
  {
    printf("ALL TESTS PASSED.\n");
  }

  return 0;
}
