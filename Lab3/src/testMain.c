#include <stdio.h>
#include <stdlib.h>
#include "../includes/LinkedListAPI.h"
#include "../includes/Book.h"
#include "../includes/BookListTest.h"
#include "../includes/intListTest.h"

int main()
{
  int intTestsFailed;
  int bookTestsFailed;

  intTestsFailed = intTest();
  bookTestsFailed = bookTest();

  if (intTestsFailed == 0)
  {
    printf("\nALL INT TESTS PASSED\n");
  }
  if (bookTestsFailed == 0)
  {
    printf("\nALL BOOK TESTS PASSED\n");
  }

  printf("----------------------\n");
  printf("TOTAL TESTS FAILED: %d\n", intTestsFailed + bookTestsFailed);

  if (intTestsFailed + bookTestsFailed == 0)
  {
    printf("ALL TESTS PASSED.\n");
  }

  return 0;
}
