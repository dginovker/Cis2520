#include "../includes/userHashFunctions.h"

int hashFunction(int tableSize, void* key)
{
  char *key2 = (char*)key;
  if (key2[0] > 'a' && key2[0] < 'z')
  {
    return key2[0]-'a';
  }
  if (key2[0] > 'A' && key2[0] < 'Z')
  {
    return key2[0] - 'A';
  }
  return 0;
}

void destroyData(void *data)
{
  void *temp = data;
  if (data)
  {
    free (temp);
  }
}

void printWord(void* toBePrinted)
{
  printf("%s",(char*)toBePrinted);
}

void addToTable(HTable *hashTable, void *data)
{
  int key = hashTable -> hashFunction(hashTable -> size, (char*)data);
  insertData(hashTable, key, data);
}

int equals(Node* a, Node* b)
{
  char* A = (char*)a -> data;
  char *B = (char*)b -> data;
  int index = 0;
  printf("Checking if [%s] == [%s]\n", A, B);
  while (A[index] && B[index])
  {
    if (A[index] != B[index])
    {
      printf("%c != %c\n", A[index], B[index]);
      return 0;
    }
    printf("%c == %c\n", A[index], B[index]);
    index++;
  }
  return 1;
}
