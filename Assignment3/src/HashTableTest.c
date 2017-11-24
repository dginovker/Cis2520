#include "../includes/HashTableAPI.h"
#include "../includes/Test.h"
#include <stdio.h>
#include <stdlib.h>

int testHashFunction(int tableSize, void* key)
{
  int key2 = *(int*)key;
  //printf("value passed in: %d. Tablesize: %d. %d%%%d = %d\n", key, tableSize, key,tableSize, key%tableSize);
  return key2%tableSize;
}

void testDestroyData(void *data)
{
  void *temp = data;
  if (data)
  {
    free (temp);
  }
}

void printInteger(void* toBePrinted)
{
  printf("%d\n",*(int*)toBePrinted);
}

void testAddToTable(HTable *hashTable, void *data)
{
  int key = hashTable -> hashFunction(hashTable -> size, data);
  //printf("Key is %d\n", key);
  insertData(hashTable, key, data);
}

void* makeInt(int a)
{
  int* b = malloc(sizeof(int));
  *b = a;
  return (void*)b;
}

int hashTest()
{
  int issues = 0;
  int test;

  //Testing the creation of the hashmap
  //Expected: hashmap is created successfully and not NULL
  test = 0;
  HTable *hashmap = createTable(1, *testHashFunction, *testDestroyData, *printInteger, *testAddToTable);
  if (hashmap == NULL)
  {
    test = 1;
  }
  issues += TEST(test, "Testing creation of Hashmap. Hashmap should not crash or return NULL.");

  test = 0;
  hashmap -> add(hashmap, makeInt(5));
  if (hashmap -> table[0] -> data == NULL)
  {
    test = 1;
  }
  issues += TEST(test, "Testing the insertData of Hashmap API. '5' should be added to hashmap at key 0:");

  test = 0;
  if (*(int*)(hashmap -> table[0] -> data) != 5)
  {
    printf("%d != %d", *(int*)(hashmap -> table[0] -> data), 5);
    test = 1;
  }
  issues += TEST(test, "Checking the validity of data in the hashmap");

  test = 0;
  if ( *(int*)(((Node*)lookupData(hashmap, 0)) -> data) != 5)
  {
    test = 1;
  }
  issues += TEST(test, "Testing lookupData function..");

  test = 0;
  hashmap -> add(hashmap, makeInt(7));
  if (*(int*)(hashmap -> table[0] ->  next -> data) != 7)
  {
    test = 1;
  }
  issues += TEST(test, "EDGECASE [1/*]: Checking collision handling by adding '7' to key 0 in hashmap");

  test = 0;
  int frees = destroyTable(hashmap);
  printf("Total frees succeeded: %d\n", frees);
  issues += TEST(test, "Testing destroyTable and removeData. Program should not crash (LARGE TEST)");

  test = 0;
  hashmap = createTable(2, *testHashFunction, *testDestroyData, *printInteger, *testAddToTable);
  if (hashmap == NULL)
  {
    test = 1;
  }
  issues += TEST(test, "EDGECASE [2/*]: Recreating the hashmap to the same variable. Hashmap is now of size 2 instead of one. Hashmap should not be NULL");

  test = 0;
  for (int i = 0; i < 1000; i++ )
  {
    hashmap -> add(hashmap, makeInt(((i*2-7)%3)*4 + i + i));
  }
  issues += TEST(test, "EDGECASE [3/*]: Adding <<A LOT>> of data to the Hashmap to check collisions and to make sure the hashmap works.");

  test = 0;
  frees = destroyTable(hashmap);
  printf("Total frees succeeded: %d\n", frees);
  issues += TEST(test, "Destorying the massive hashmap. Total frees reported above (LARGE TEST). Program should not crash");

  return issues;
}
