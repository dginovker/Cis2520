#ifndef SPELLCHECK_H
#define SPELLCHECK_H

#include "HashTableAPI.h"

/* Function to prompt user for a file to run a spellcheck on
* @param hashmap: dictionary of words to compare file against
*/
void spellCheck(HTable *hashmap);

/* Function used in a linked list for testing to print a string
* @param a: string to print
*/
void printStr(void* a);

/* Function used in a linked list for freeing a string
* @param a: string to free
*/
void deleteStr(void* a);

#endif
