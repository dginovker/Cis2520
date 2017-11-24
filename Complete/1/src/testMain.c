#include "../includes/Test.h"
#include "../includes/intListTest.h"
#include "../includes/HashTableTest.h"
#include <stdio.h>

int main()
{
  int testInts=0, hashTests=0;

  hashTests = hashTest();

  if (!hashTests)
  {
    printf("ALL HASHMAP TESTS PASSED\n");
  }

  testInts = intTest();

  if (!testInts)
  printf("ALL INT LIST TESTS PASSED\n");


  if (hashTests + testInts == 0)
  {
    printf("ALL TESTS PASSED\n");
  }

  return 0;
}
