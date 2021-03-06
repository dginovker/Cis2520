#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/HashTableAPI.h"
#include "../includes/LinkedListAPI.h"
#include "../includes/spellCheck.h"
#include "../includes/userHashFunctions.h"
#include "../includes/displayDictionary.h"
#include "../includes/modifyDictionary.h"

int main(int c, char **argv)
{
  char toCheck[] = "essay.txt";
  //char dic[] = "dictionary.txt"; //Hardcoded dictionary for testing
  int choice;
  char userInput[80];
  char line[80];
  FILE* fp = NULL;

  HTable *hashmap = NULL; //Hashmap to store all the data
  //Length 26, one for each letter of the alphabet. Any non alphabetic character is 0
  hashmap = createTable(26, *hashFunction, *destroyData, *printWord, *addToTable);

  printf("Reading file %s for dictionary words and %s for file to spell check.\n", argv[1], toCheck);

  fp = fopen(argv[1], "r");

  //Load up the hashmap
  while (fgets(line, 80, fp) != NULL)
  {
    while (line[strlen(line) -1] == '\n' || line[strlen(line) -1] == '\r')
    {
      //Remove newline and carrige return (windows systems)
      line[strlen(line)-1] = '\0';
    }
    toLowerCase(line);
    char* addMe2 = malloc(sizeof(char)*(strlen(line) + 1));
    strcpy(addMe2, line);
    hashmap -> add(hashmap, addMe2);
  }
  //close file
  fclose(fp);

  while (1)
  {
    printf("Menu:");
    printf("\n\t1) Add a word to dictionary");
    printf("\n\t2) Remove a word from dictionary");
    printf("\n\t3) Spell check a file");
    printf("\n\t4) Show dictionary words");
    printf("\n\t5) Quit");
    printf("\nAnswer: ");

    fgets(userInput, 80, stdin);
    choice = atoi(userInput);

    switch (choice)
    {
      case 1:
        addWordToDictionary(hashmap);
      break;
      case 2:
        removeWordFromDictionary(hashmap);
      break;
      case 3:
        spellCheck(hashmap);
      break;
      case 4:
        showDictionaryWords(hashmap);
      break;
      default:
        printf("Thanks for using the program! Baii\n");
        destroyTable(hashmap);
        //Free everything
        return 0;
      break;
    }
  }

  return 0;
}
