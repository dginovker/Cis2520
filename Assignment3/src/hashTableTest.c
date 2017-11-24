#include <HashTableAPI.h>
#include <stdio.h>
#include <stdlib.h>

void hashFunction(size_t size, int key)
{
  
}


int HashTableTest()
{
  int errors = 0;

  HTable hashmap = createTable(1, *hashFunction, *destroyData, *printInteger, *addToTable);



  return errors;
}
