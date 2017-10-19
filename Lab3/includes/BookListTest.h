/**
 * @file BookListTest.h
 * @author Daniel Ginovker
 * @date September 2017
 * @brief File containing the function definitions for book linked list tests
 */
#ifndef BOOKLISTTEST_H
#define BOOKLISTTEST_H

/**
 *Compares two pointers to books, is a function pointer used in the declaration of linked list
 *@param first pointer to data to be compared with second.
 *@param second pointer to data to be compared with first.
 *@return for sorting purposes,
 *<0 The element pointed by 'first' goes before the element pointed by 'second'
 *0  The element pointed by 'first' is equivalent to the element pointed by 'second'
 *>0 The element pointed by 'first' goes after the element pointed by 'second'
 **/
int compareBook(const void* first, const void* second);

/**
 *Clears all required information about books before they are freed
 *@param book to be cleared
 **/
void deleteBookNode(void *toBeDeleted);

/**
 *Tests several books and every function in the API
 *@return 0 on success
 *@return the number of failed tests otherwise
 **/
int bookTest();

#endif
