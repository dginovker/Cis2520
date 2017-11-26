#ifndef USERHASHFUNCTIONS_H
#define USERHASHFUNCTIONS_H

#include "HashTableAPI.h"

/* hashFunction: function that hashes a variable and returns a key
* @param tableSize: size of the hashmap
* @param key: key to hash
* @return hash value
*/
int hashFunction(int tableSize, void* key);

/* Function to destroy all data correlating to a hash
* @param data: void pointer to data to hash and destroy
* @return void
*/
void destroyData(void *data);

/* Function to print a word (used in the creation of a hashmap)
* @param toBePrinted: void pointer to a word to be printed
*/
void printWord(void* toBePrinted);

/* Function addToTable: uses encapsulation to add data to a table
* @param hashTable: table to add the data to
* @param data: void pointer to the data to be hashed and added to table
* @return void
*/
void addToTable(HTable *hashTable, void *data);

/* Test function to check if two nodes hold the same data.
* @param a: node holding string a
* @param b: node holding string b
* @return: 1 if string a == stirng b, 0 otherwise
*/
int equals(Node* a, Node* b);

#endif
