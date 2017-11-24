#include <stdio.h>

int TEST(int issues, char test[])
{
  printf("%s:\n", test);
  if (issues == 1)
  {
    printf("\t*****[TEST FAILED]*****\n");
  }
  else
  {
    printf("\t[TEST PASSED]\n");
  }
  return issues;
}
