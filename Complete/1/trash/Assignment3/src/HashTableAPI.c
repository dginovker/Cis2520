#include "../includes/HashTableAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HTable *createTable(int size, int (*hashFunction)(int tableSize, void* key), void (*destroyData)(void *data), void (*printNode)(void *toBePrinted), void (*add)(struct HTable *hashTable, void *data))
{
  HTable *hashmap = NULL;
  hashmap = malloc(sizeof(HTable));
  hashmap -> table = malloc(sizeof(Node*)*size);
  for (int i = 0; i < size; i++)
  {
    hashmap -> table[i] = NULL;
  }
  hashmap -> destroyData = destroyData;
  hashmap -> hashFunction = hashFunction;
  hashmap -> printNode = printNode;
  hashmap -> add = add;
  hashmap -> size = size;

  return hashmap;
}

Node *createNode(int key, void *data)
{
  Node *node = NULL;
  node = malloc(sizeof(Node));

  node -> data = data;
  node -> next = NULL;
  node -> previous = NULL;
  node -> key = key;

  return node;
}

int destroyTable(HTable *hashTable)
{
  int freeCount = 0;
  removeData(hashTable, 22);
/*
  for (int i = 0; i < hashTable -> size; i++)
  {
    freeCount += removeData(hashTable, i);
  }*/
  free(hashTable -> table);
  free(hashTable);

  return freeCount + 2;
}

int removeData(HTable *hashTable, int key)
{
  int freeCount = 0;
  Node *iterator = NULL;
  iterator = hashTable -> table[key];
  if (iterator == NULL)
  {
    return 0;
  }
  while (iterator -> next != NULL)
  {
    iterator = iterator -> next;
  }
  //Now iterator is at the end of the list
  while (iterator -> previous != NULL)
  {
    hashTable -> destroyData(iterator -> data);
    iterator = iterator -> previous;
    free(iterator -> next);
    freeCount++;
  }
  hashTable -> destroyData(iterator -> data);
  free(iterator);
  freeCount++;
  return freeCount;
}

void insertData(HTable *hashTable, int key, void *data)
{
  Node *iterator = NULL;
  iterator = hashTable -> table[key];
  if (iterator == NULL)
  {
    //Create the first node
    hashTable -> table[key] = createNode(key, data);
    hashTable -> table[key] -> previous = NULL;
    return;
  }
  //Add to the node list
  while (iterator -> next != NULL)
  {
    iterator = iterator -> next;
  }
  iterator -> next = createNode(key, data);
  iterator -> next -> previous = iterator;
}

void *lookupData(HTable *hashTable, int key)
{
  return hashTable -> table[key];
}

int destroyNode(HTable *hashmap, Node *node, int (*equals)(Node* a, Node* b))
{
  int key = hashmap -> hashFunction(hashmap -> size, node -> data);
  Node *iterator = NULL;
  iterator = malloc(sizeof(Node));

  iterator = hashmap -> table[key];
  if (iterator != NULL)
  {
    if (equals(iterator, node))
    {
      hashmap -> table[key] = iterator -> next;
      return 1;
    }
    else
    {
    }
  }
  while (iterator -> next != NULL)
  {
    iterator = iterator -> next;
    if (equals(iterator, node))
    {
      iterator -> previous -> next = iterator -> next;
      return 1;
    }
  }
  return 0;
}
