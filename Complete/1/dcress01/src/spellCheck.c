#include "../includes/spellCheck.h"
#include "../includes/HashTableAPI.h"
#include "../includes/LinkedListAPI.h"
#include "../includes/modifyDictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printStr(void* a)
{
  printf("%s\n",(char*)a);
}
void deleteStr(void* a)
{
  char* b = (char*)a;
  free(b);//Freebies!
}

void spellCheck(HTable *hashmap)
{
  int good = 0, bad = 0, totalGood = 0;
  FILE *fp = NULL;
  List *list = NULL;
  char line[80];
  char fileName[80];

  list = initializeList(&printStr, &deleteStr, NULL);

  printf("Enter the name of the file to be spellchecked: ");
  fgets(fileName, 80, stdin);

  fileName[strlen(fileName) - 1] = '\0';

  fp = fopen(fileName, "r");
  //Go through all the words in the file, add them to a list
  while (fgets(line, 80, fp) != NULL)
  {
    while (line[strlen(line) -1] == '\n' || line[strlen(line) -1] == '\r')
    {
      line[strlen(line)-1] = '\0';
    }
    toLowerCase(line);
    char* addMe = malloc(sizeof(char)*(strlen(line) + 1));
    strcpy(addMe, line);
    insertBack(list, addMe);
  }
  fclose(fp);

  //printForward(wordsToCheck);

  printf("File processed by Spell Check: %s\n", fileName);
  while (list -> head != NULL)
  {
    Node *node = lookupData(hashmap, hashmap -> hashFunction(hashmap -> size, getFromFront(list)));
    if (node == NULL)
    {
      //If there's nothing at the key, it's obviously not found
      printf("%s was not found in the dictionary\n", (char*)getFromFront(list));
      bad++;
    }
    else
    {
      //If there's a list at the key
      good = 0;
      while (node -> next != NULL)
      {
        if (strcmp(node -> data, (char*)getFromFront(list)) == 0)
        {
          good = 1;
          break;
        }
        node = node -> next;
      }
      if (strcmp(node -> data, (char*)getFromFront(list)) == 0)
      {
        good = 1;
      }
      if (good == 0)
      {
        bad++;
        printf("%s was not found in the dictionary\n", (char*)getFromFront(list));
      }
      else
      {
        totalGood++;
      }
    }
    //Pop the word off the list
    deleteNodeFromList(list, getFromFront(list));
  }
  //Print results
  printf("Summary:\nCorrectly spelt words: %d\nIncorrectly spelt words: %d\n", totalGood, bad);
  //Free additional memory
  deleteList(list);
}
