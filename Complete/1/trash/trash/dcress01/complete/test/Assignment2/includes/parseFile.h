/**
 * @file parseFile.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the function definitions used in parsing patients out of a file
 */

#ifndef PARSEPRIORITY_H
#define PARSEPRIORITY_H

/**
 *Extracts the priority number from a string
 *@returns the priortiy number extracted
 *@param string to extract from
 **/
int priorityNumber(char *string);

/**
 *Extracts the client ID from a string
 *@returns the client ID number extracted
 *@param string to extract from
 **/
char *clientID(char *string);

/**
 *Extracts the symptom code from a string
 *@returns the symptom code extracted
 *@param string to extract from
 **/
char *clientSymptomCode(char *string);

/**
 *Finds if a char passed in is a number
 *@returns 1 if yes, 0 otherwise
 *@param char to test
 **/
int aNumber(char a);

#endif
