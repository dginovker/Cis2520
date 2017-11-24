#ifndef HASHTABLETEST_H
#define HASHTABLETEST_H

#include "../includes/HashTableAPI.h"

/* hashFunction: function that hashes a variable and returns a key
* @param tableSize: size of the hashmap
* @param key: key to hash
* @return hash value
*/
int hashFunction(size_t tableSize, int key);

/* Function to destroy all data correlating to a hash
* @param data: void pointer to data to hash and destroy
* @return void
*/
void destroyData(void *data);

/* Function to print an integer (used in the creation of a hashmap)
* @param toBePrinted: void pointer to an integer to be printed
*/
void printInteger(void* toBePrinted);

/* Function addToTable: uses encapsulation to add data to a table
* @param hashTable: table to add the data to
* @param data: void pointer to the data to be hashed and added to table
* @return void
*/
void addToTable(HTable *hashTable, void *data);

/* Function to create and allocate room for an integer pointer
* @param integer to create
* @return void
*/
void* makeInt(int a);

/* Function to test all hash functions in HashTableAPI.c
* @return number of failed tests of the API
*/
int hashTest();

#endif
