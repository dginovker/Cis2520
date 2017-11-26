#include <stdio.h>
#include <stdlib.h>
#include "../includes/HashTableAPI.h"

void showDictionaryWords(HTable *hashmap)
{
  char *word;
  int index;
  for (char letter = 'a'; letter < 'z' +1; letter++)
  {
    int key = letter - 'a';
    index = 0;
    Node *iterator = NULL;
    iterator = hashmap -> table[key];
    if (iterator != NULL)
    {
      //print iterator
      word = (char*)iterator -> data;
      printf("<%d>:<%d>:<%s>\n", index, key, word);

      while (iterator -> next != NULL)
      {
        index++;
        iterator = iterator -> next;
        word = (char*)iterator -> data;
        printf("<%d>:<%d>:<%s>\n", index, key, word);
      }
    }
  }
}
