#include <stdio.h>
#include <stdlib.h>
#include "../includes/parseFile.h"

#define bool int
#define false 0
#define true 1

bool aNumber(char a)
{
  if (a - 48 >= 0 && a - 48 <= 10)
  {
    return true;
  }
  return false;
}

int priorityNumber(char *string)
{
  int placement = 1;
  int value = 0;
  int index = 0;

  while (string[index] != '\0' && string[index] != ' ')
  {
    index++;
  }
  index++;
  while (string[index] != 0 && string[index] != ' ')
  {
    if (aNumber(string[index]))
    {
      value += (string[index]-48)*placement;
      index++;
      placement *= 10;
    }

  }
  //printf("Parsed the number %d from string %s.\n", value, string);
  return value;
}

char *clientID(char *string)
{
  char *value = malloc(sizeof(char)*11);//Max clientID is going to be 10 characters
  int index = 0;

  while (string[index] != ' ' && string[index] != '0' && index < 10)
  {
    value[index] = string[index];
    index++;
  }
  value[index] = '\0';

  //printf("Returning clientID %s.\n", value);
  return value;
}

char *clientSymptomCode(char *string)
{
  char *value = NULL;
  int index = 0;
  int descStart;

  value = malloc(sizeof(char)*101);

  while (string[index] != ' ' && string[index] != '\0')
  {
    index++;
  }
  index++;
  while (string[index] != ' ' && string[index] != '\0')
  {
    index++;
  }
  index++;

  descStart = index;
  while (string[index] != '\0' && string[index] != '\n' && string[index] != '\r' && string[index] != ' ')
  {
    value[index-descStart] = string[index];
    index++;
  }
  value[index] = '\0';

  //printf("Returning [%s] as description\n", value);
  return value;
}
