#include <stdio.h>
#include "../includes/HeapAPI.h"

/**
 * Internal functions to search for the max element between the data stored at index i
 * and the left child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxLeft(Heap *heap,size_t i);

/**
 * Internal functions to search for the max element between the data stored at index current
 * and the right child. This function will use compares data using the function pointer and return the index of the maximum item.
 */
size_t findMaxRight(Heap *heap,size_t curr, size_t i);

/**************************************************************************************************************************/

Heap *createHeap(size_t initialSize, void (*destroyDataFP)(void *data),int (*compareFP)(const void *first, const void *second)){
    Heap *heap;
    if(!(heap = malloc(sizeof(Heap)))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    if(!(heap->heapArray = malloc(sizeof(Node)*initialSize))){
        fprintf(stderr,"Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    heap->type = MIN_HEAP;
    heap->currentSize = 0;
    heap->maxSize = initialSize;
    heap->destroyData = destroyDataFP;
    heap->compare = compareFP;
    return heap;
}

Node *createHeapNode(void *data){
    Node *node;
    node = malloc(sizeof(Node));
    node->data = data;
    return node;
}

void swapNodeData(Node* a, Node* b)
{
  void* temp = NULL;
  temp = a -> data;
  a -> data = b -> data;
  b -> data = temp;
}

void insertHeapNode(Heap *heap, void *data){
  Node *node = createHeapNode(data);
  heap -> heapArray[heap -> currentSize] = node;
  int i = heap -> currentSize;
  heap -> currentSize++;
  //printf("\t\tInserting %d\n", *(int*)(heap -> heapArray[i] -> data));

  while (i > 0 && heap -> compare(heap -> heapArray[getParentIndex(i)] -> data, heap -> heapArray[i] -> data) < 0)
  {
    //printf("\t\tBumping %d up over %d\n", *(int*)(heap -> heapArray[i] -> data), *(int*)(heap -> heapArray[getParentIndex(i)] -> data));
    swapNodeData(heap -> heapArray[getParentIndex(i)], heap -> heapArray[i]);
    i = getParentIndex(i);
  }
}

void deleteRoot(Heap *heap) {
    Node *temp;
    if(heap->currentSize>0) {
        temp = heap->heapArray[0];
        (heap->currentSize)--;
        heap->heapArray[0] = heap->heapArray[heap->currentSize];
        heap->destroyData(temp);
        heapify(heap, 0) ;
    } else {
        fprintf(stderr,"Heap is empty.\n") ;
	}
}

void deleteHeap(Heap *heap){
    size_t i;
    i = heap->currentSize;
    while(i>0){
        deleteRoot(heap);
        i--;
    }
    free(heap->heapArray);
    free(heap);
}

void* getRoot(Heap *heap){
    return heap->heapArray[0]->data;
}

void heapify(Heap *heap, size_t i){
  //If the left child index is in the domain
  if (getLeftChildIndex( i) < heap -> currentSize)
  {
    //If the left index is greater than the parent index
    if (heap -> compare (heap -> heapArray[i] -> data, heap -> heapArray[getLeftChildIndex(i)] -> data) < 0)
    {
//      printf("Child index %d is greater than parent %d. Swapping.\n", *(int*)(heap -> heapArray[getLeftChildIndex(i)] -> data), *(int*)(heap -> heapArray[i]) -> data);
      swapNodeData(heap -> heapArray[i], heap -> heapArray[getLeftChildIndex(i)]);
      //Swap them, and run heapify on the new left index
      heapify(heap, getLeftChildIndex( i));
    }
  }

  //If the right child index is in the domain
  if (getRightChildIndex(i) < heap -> currentSize)
  {
    if (heap -> compare (heap -> heapArray[i] -> data, heap -> heapArray[getRightChildIndex(i)] -> data) < 0)
    {
//      printf("Child index %d is greater than parent %d. Swapping.\n", *(int*)(heap -> heapArray[getRightChildIndex(i)] -> data), *(int*)(heap -> heapArray[i]) -> data);
      swapNodeData(heap -> heapArray[i], heap -> heapArray[getRightChildIndex(i)]);
      //Swap them and run heapify on the new right index
      heapify(heap, getRightChildIndex(i));
    }
  }
}


size_t findMaxLeft(Heap *heap,size_t i){
    size_t  leftIdx = getLeftChildIndex( i );
    if( leftIdx < heap->currentSize && heap->compare(heap->heapArray[leftIdx]->data,heap->heapArray[i]->data) > 0){
        return leftIdx;
    }
    return i;
}

size_t findMaxRight(Heap *heap,size_t curr, size_t i){
    size_t rightIdx = getRightChildIndex( curr );
    if( rightIdx < heap->currentSize && heap->compare(heap->heapArray[rightIdx]->data,heap->heapArray[i]->data) > 0){
      return rightIdx;
    }
    return i;
}


size_t getLeftChildIndex(size_t index)
{
	return 2*index+1;
}

size_t getRightChildIndex(size_t index)
{
	return 2*(index+1);
}

size_t getParentIndex(size_t index)
{
	return (index-1)/2;
}

size_t currentSize(Heap* heap)
{
    return heap->currentSize;
}

void* search(Heap* heap, void* data)
{
    for(size_t i =0; i < currentSize(heap);i++)
    {
        if( heap->compare(data,heap->heapArray[i]->data) == 0)
            return heap->heapArray[i]->data;
    }
    return NULL;
}


void printHeap(Heap* heap, void (*printFunc)(void*) )
{
  for (int i = 0; i < heap -> currentSize; i++)
  {
    printFunc(heap -> heapArray[i] -> data);
  }
}
