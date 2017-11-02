#include "../includes/Test.h"
#include "../includes/parseFile.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int testParseInput()
{
  int issues = 0;
  int test;

  char testInput[] = "ted23 5 TR";

  test = 0;
  if (strcmp("ted23", clientID(testInput)))
  {
    printf("ted23 != %s\n", clientID(testInput));
    test = 1;
  }
  issues += TEST(test, "Testing clientID retrieves correct data..\n");

  test = 0;
  if (strcmp("TR", clientSymptomCode(testInput)))
  {
    printf("TR != %s\n", clientSymptomCode(testInput));
    test = 1;
  }
  issues += TEST(test, "Checking that clientDescription retrieves the correct data..");

  test = 0;
  if (priorityNumber(testInput) != 5)
  {
    printf("5 != %d\n", priorityNumber(testInput));
    test = 1;
  }
  issues += TEST(test, "Checking that the priorityNumber is equal to 5...");

  test = 0;
  if (aNumber('5') != 1)
  {
    printf("5 isn't a number you fucking retard? LOL\n");
    test = 1;
  }
  issues += TEST(test, "Checking that '5' is considered a number..");

  test = 0;
  if (aNumber('$') != 0)
  {
    printf("You think $ is a number?\n");
    test = 1;
  }
  issues += TEST(test, "Checking that '$' isn't considered a number..");

  return issues;
}
