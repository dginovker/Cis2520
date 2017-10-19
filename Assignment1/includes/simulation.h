/**
 * @file simulation.h
 * @author Dainel Ginovker
 * @date October 2017
 * @brief File containing the functions directly used in the game loop of the program
 */
#ifndef SIMULATION_H
#define SUMULATION_H

#include "LinkedListAPI.h"

/**
 *Trafficlight and TrafficDirection enumerations. Keep code tidy.
**/
typedef enum {GREEN, YELLOW, RED} TrafficLight;
typedef enum {NORTH, EAST, SOUTH, WEST} TrafficDirection;


/**Function to run the main simulation of the program
*@return void
*@param lists north, east, south and west which contain the car data information
**/
void runSimulation(List *north, List *east, List *south, List *west);


/**Function to calculate if there's any cars left for the simulation to process
*@return returns 0 if there's no more cars, 1 otherwise
*@param lists north, east, south and west which contain the car data information
**/
int carsInList(List *north, List *east, List *south, List *west);

/**Function updateTrafficLight finds out what color the light should be for that sim loop
*@return returns GREEN, YELLOW or RED based on a simple algorithm
*@param double simulation timer clock
**/
TrafficLight updateTrafficLight(double clock);

/**Function TraficDirection finds out what direction the traffic is flowing through the intersection at the time
*@return returns NORTH, EAST, SOUTH or WEST based on a simple algorithm that finds the direction based on a simple algorithm
*@param double simulation timer clock
**/
TrafficDirection updateTrafficDir(double clock);

#endif
