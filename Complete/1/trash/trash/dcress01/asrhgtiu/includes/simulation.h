/**
 * @file similation.h
 * @author Daniel Ginovker
 * @date October 2017
 * @brief File containing the function definitions used in the simulation
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include "../includes/priorityQueueAPI.h"

/*
 * Main loop of the program
 * Runs the simulation loop and prints out the time everyone leaves the hospital
 * @param patientList: The list with all the patients
*/
void runSimulation(PQ* patientList, List *orderList);

#endif
