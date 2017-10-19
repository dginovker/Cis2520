/**
 * @file BookListTest.h
 * @author Daniel Ginovker
 * @date September 2017
 * @brief File containing the function definitions for useful testing functions
 */

#ifndef INTSTACKFUNCTIONS_H
#define INTSTACKFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/** Function to print integer from void pointer
*@return void
*@param void container holding the integer
**/
void intPrint(void* data);

/**
 *Compares two pointers to integers, is a function pointer used in the declaration of linked list
 *@param first pointer to data to be compared with second.
 *@param second pointer to data to be compared with first.
 *@return for sorting purposes,
 *<0 The element pointed by 'first' goes before the element pointed by 'second'
 *0  The element pointed by 'first' is equivalent to the element pointed by 'second'
 *>0 The element pointed by 'first' goes after the element pointed by 'second'
 **/
int intCompare(const void* a, const void* b);

/**Function takes an integer, and returns a void container containing it
*@param integer to be converted
*@return void container containing integer
**/
void *initVoid(int a);

#endif
