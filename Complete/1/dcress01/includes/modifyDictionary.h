#ifndef MODIFYDICTIONARY_H
#define MODIFYDICTIONARY_H

#include "../includes/HashTableAPI.h"

/* Function to prompt user to add a word to the hashmap
* @param hashmap to add to
*/
void addWordToDictionary(HTable *hashmap);

/* Function to prompt user to remove a word from the hashmap
* @param hashmap to add to
*/
void removeWordFromDictionary(HTable *hashmap);

/* Function that converts a word to lowercase
* @param a: string to convert to lowercase
*/
void toLowerCase(char* a);

#endif
