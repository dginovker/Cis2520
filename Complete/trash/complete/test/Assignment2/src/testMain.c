#include "../includes/Test.h"
#include "../includes/intListTest.h"
#include "../includes/testParseInput.h"
#include "../includes/priorityQueueTest.h"
#include <stdio.h>

int main()
{
  int testInts, parseInputTests, priority;

  testInts = intTest();
  parseInputTests = testParseInput();
  priority = testPriority();

  if (!testInts)
  printf("ALL INT LIST TESTS PASSED\n");

  if (!parseInputTests)
  printf("ALL PARSEINPUT TESTS PASSED\n");

  if (!priority)
  printf("ALL PRIORTYQUEUE TESTS PASSED\n");

  if (priority + parseInputTests + testInts == 0)
  {
    printf("ALL TESTS PASSED\n");
  }

  return 0;
}
