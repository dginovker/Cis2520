#include <stdio.h>
#include <stdlib.h>
#include "../includes/Stack.h"
#include "../includes/intStackFunctions.h"

int main()
{
  printf("Welcome to the squash program. Enter one number at a time, and we'll squash with them!\n");
  int input;
  Stack *s;

  s = createStack(*intPrint, NULL, *intCompare);

  while(input >= 0)
  {
    if (count(s) == 0)
    {
      printf("\nEnter a new number: ");
      scanf("%d", &input);

      if (input < 0)
      {
        break;
      }
      push (s, initVoid(input));
    }
    printf("\nEnter a new number: ");
    scanf("%d", &input);

    if (input < 0)
    {
      break;
    }

    int *temp = malloc(sizeof(int));
    *temp = input; //Fix memory leak in compare
    while (s -> list -> compare( (void*)temp, top(s) ) > 0)
    {
      printf("%d squashed %d\n", input, *(int*)top(s));
      pop(s);
      if (top(s) == NULL)
      {
        break;
      }
    }
    free(temp);

    push(s, initVoid(input));
  }

  printf("Remaining: ");
  printForward(s -> list);

  printf("\n");

  return 0;
}
