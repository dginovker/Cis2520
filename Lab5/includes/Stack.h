/**
 * @file Stack.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the function definitions of a stack
 */

#ifndef _STACK_API_
#define _STACK_API_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListAPI.h"

typedef struct stack{
    int count;
    List * list;
} Stack;

/**Function to create the stack
*@return pointer to the stack
*@param printFunction function pointer to print a single node of the list
*@param deleteFunction function pointer to delete a single piece of data from the list
*@param compareFunction function pointer to compare two nodes of the list in order to test for equality or order
**/
Stack *createStack(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second));

/**Function to push an element onto the stack
*@return void
*@param Stack to push data onto
*@param void pointer to data to be put on stack
**/
void push(Stack *s, void *data);

/**Function to pop an item off the top of the stack
*@return void
*@param Stack to pop data off of
**/
void pop(Stack *s);

/**Function to return the top item of the stack
*@return void data that was popped off stack
*@param Stack to retrieve the top of
**/
void *top(Stack *s);

/**Function to retrieve the count from the stack
*@return integer that represents the number of elements in the stack
*@param stack to retrieve the integer count from
**/
int count (Stack *s);

/**Function that frees the list inside the stack, then the stack itself and all of the elements
*@return 0 on success, crash on failure
*@param stack to be freed
**/
int freeStack(Stack *s);

#endif
