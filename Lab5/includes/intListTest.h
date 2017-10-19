/**
 * @file intListTest.h
 * @author Daniel Ginovker
 * @date September 2017
 * @brief File containing the function definitions of my integer test c file
 */

#ifndef INTLISTTEST_H
#define INTLISTTEST_H

/**
 *Tests several integers and every function in the API
 *@return 0 on success
 *@return the number of failed tests otherwise
 **/
int intTest();

/**
 *Compares two pointers to integers, is a function pointer used in the declaration of linked list
 *@param first pointer to data to be compared with second.
 *@param second pointer to data to be compared with first.
 *@return for sorting purposes,
 *<0 The element pointed by 'first' goes before the element pointed by 'second'
 *0  The element pointed by 'first' is equivalent to the element pointed by 'second'
 *>0 The element pointed by 'first' goes after the element pointed by 'second'
 **/
int compareInt(const void* a, const void* b);

/**
 *Deletes any additioal information required on integers
 *Used to be passed into Linked List declaration as function pointer
 *@param integer to be cleaned
 **/
void deleteInt(void *a);

/**
 *Initialize an integer pointer
 *@param value to set new pointer to
 *@return malloced space for integer pointer with the value of param b
 **/
int *initInt(int b);

#endif
