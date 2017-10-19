/**
 * @file car.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the information on the car struct, as well as functions pertaining to car list
 */


#ifndef CAR_H
#define CAR_H

/**
 * Structure of the car, has all information required
 */
typedef struct car{
  char dir;
  double TTI; //Double representing the time to intersection
} Car;

/**
 *Compares two pointers to cars, is a function pointer used in the declaration of linked list
 *@param first pointer to data to be compared with second.
 *@param second pointer to data to be compared with first.
 *@return for sorting purposes,
 *<0 The element pointed by 'first' goes before the element pointed by 'second'
 *0  The element pointed by 'first' is equivalent to the element pointed by 'second'
 *>0 The element pointed by 'first' goes after the element pointed by 'second'
 **/
int compareCar(const void* a, const void* b);

/**
  *Prints information in the car struct
  *@param pointer to car to be printed
  *@return void
 **/
void printCar(void* a);

/**
 *Deletes any additioal information required in the car (there is none)
 *Used to be passed into Linked List declaration as function pointer
 *@param car to be cleaned
 **/
void deleteCar(void *a);

/**
 *Initialize an car pointer
 *@param value to set new pointer to
 *@return malloced space for integer pointer with the value of param b
 **/
Car *initCar(int TTI, char dir);

#endif
