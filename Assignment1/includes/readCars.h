/**
 * @file readCars.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the functions used in readCars.c
 */

#ifndef READCARS_H
#define READCARS_H

/**
 *Function addCarToList parses the string "line" for info and adds it to a car struct, which adds it to the list
 *@param List to add the car to
 *@param String with all the info required in it
 *@return void
 **/
void addCarToList(List *list, char line[]);

#endif
