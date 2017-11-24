#include "../includes/modifyDictionary.h"
#include "../includes/HashTableAPI.h"
#include "../includes/userHashFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toLowerCase(char* a)
{
  int i = 0;
  while (a[i] != '\0')
  {
    if (a[i] > 'A' && a[i] < 'Z')
    {
      a[i] -= 'A' - 'a';
    }
    i++;
  }
}

void addWordToDictionary(HTable *hashmap)
{
  char *userInput = malloc(sizeof(char)*80);
  printf("Enter the word you wish to add to the dictionary: ");
  fgets(userInput, 80, stdin);
  if (strlen(userInput) > 1)
  {
    userInput[strlen(userInput) -1] = 0;
    toLowerCase(userInput);
    hashmap -> add (hashmap, userInput);
    printf("%s was successfuly added to the dictionary.\n", userInput);
  }
  else
  {
    printf("No valid word entered.\n");
  }
}

void removeWordFromDictionary(HTable *hashmap)
{
  Node *preSearch = NULL;
  char *userInput = malloc(sizeof(char)*80);
  printf("Enter the word you wish to remove from the dictionary: ");
  fgets(userInput, 80, stdin);
  if (strlen(userInput) > 1)
  {
    userInput[strlen(userInput) -1] = 0;
    toLowerCase(userInput);
    Node *search = lookupData(hashmap, hashmap -> hashFunction(hashmap -> size, (void*)&userInput[0]));

    //If there is a search
    if (search != NULL)
    {
      //If search is the first element in the list
      if (strcmp(search -> data, userInput) == 0)
      {
        hashmap -> table[hashFunction(hashmap -> size, (void*)&userInput[0])] = search -> next;
        free(search);
        printf("Word removed.\n");
        return;
      }
      else
      {
        //If search is an intermediate element in the list
        printf("here\n");
        while (search -> next != NULL)
        {
          preSearch = search;
          search = search -> next;
          //On first iteration, search is pointing at the second element
          if (strcmp(search -> data, userInput) == 0)
          {
            printf("Don't be uere\n");
            //If the second element is a match (1st iteration)
            preSearch -> next = search -> next;
            if (search -> next != NULL)
            {
              search -> next -> previous = preSearch;
              //If search is the last element in the list
            }
            //Destroy the data
            hashmap -> destroyData(search -> data);
            free(search);
            return;
          }
        }
/*        if (strcmp(search -> data, userInput) == 0)
        {
          hashmap -> destroyData(search -> data);
          free(search);
          return;
        }*/
      }
    }
  }
  else
  {
    printf("No valid word entered.\n");
  }
  printf("Error: Word not found.\n");
}
