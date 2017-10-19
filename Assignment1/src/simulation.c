#include <stdio.h>
#include <stdlib.h>
#include "../includes/simulation.h"
#include "../includes/LinkedListAPI.h"
#include "../includes/car.h"

int carsInList(List *north, List *east, List *south, List *west)
{
  if (north -> head || east -> head || south -> head || west -> head)
  {
    return 1;
  }
  return 0;
}

TrafficDirection updateTrafficDir(double clock)
{
  int halfSeconds = (int)(clock*2);
  TrafficDirection dir;
  switch (((halfSeconds - 2)%(28*4))/28)
  {
    case 0:
      dir = NORTH;
    break;
    case 1:
      dir = EAST;
    break;
    case 2:
      dir = SOUTH;
    break;
    case 3:
      dir = WEST;
    break;
  }
  return dir;
}

TrafficLight updateTrafficLight(double clock)
{
  TrafficLight light;
  int halfSeconds = (int)(clock*2);
  if ((halfSeconds - 2)%28 < 20)
  {
    light = GREEN;
  }
  else if ((halfSeconds - 2)%28 < 26)
  {
    light = YELLOW;
  }
  else
  {
    light = RED;
  }

  return light;
}

void runSimulation(List *north, List *east, List *south, List *west)
{
  double clock = 1;
  TrafficLight light;
  TrafficDirection dir;
  TrafficDirection oldDir;
  List *list = NULL;
  char symb;
  int action;
  int leftTurnOnYellow = 0;

  printf("Initial Vehicle Information\tIntersection Arrival Time\tCompleted Time\n");

  while (1)
  {
    action = 0;
    if (!carsInList(north, east, south, west))
    {
      break;
    }
    oldDir = dir;
    dir = updateTrafficDir(clock);
    if (oldDir != dir)
    {
      leftTurnOnYellow = 0;//Used to make sure two cars don't turn left on yellow
    }
    light = updateTrafficLight(clock);
    switch (dir)
    {
      //Finding which direction letter to print for output
      case NORTH:
        list = north;
        symb = 'N';
      break;
      case EAST:
        list = east;
        symb = 'E';
      break;
      case SOUTH:
        list = south;
        symb = 'S';
      break;
      case WEST:
        list = west;
        symb = 'W';
      break;
    }

    //If there's cars in this list
    if (list -> head != NULL)
    {
      //If the car is at the Intersection
      if (((Car*)(list -> head -> data)) -> TTI - clock <= 0)
      {
        //If the car is going straight and has a green light
        if (((Car*)(list -> head -> data)) -> dir == 'F' && light == GREEN)
        {
          clock += 2;
          printf("%c F %0.1lf   \t\t\t%0.1lf\t\t\t\t%0.1lf\n",symb,((Car*)(list -> head -> data)) -> TTI,((Car*)(list -> head -> data)) -> TTI, clock);
          deleteNodeFromList(list, list -> head -> data);
          action = 1;
        }
        //If the car is turning left and has either a yellow or green light, and was first in line if it turned yellow
        else if (((Car*)(list -> head -> data)) -> dir == 'L' && light != RED && leftTurnOnYellow == 0)
        {
          leftTurnOnYellow = 1;
          clock += 2.5;
          printf("%c L %0.1lf   \t\t\t%0.1lf\t\t\t\t%0.1lf\n", symb, ((Car*)(list -> head -> data)) -> TTI, ((Car*)(list -> head -> data)) -> TTI, clock);
          deleteNodeFromList(list, list -> head -> data);
          action = 1;
        }
        //If the car is turning right and has a green light
        else if (((Car*)(list -> head -> data)) -> dir == 'R' && light == GREEN)
        {
          clock += 1;
          printf("%c R %0.1lf   \t\t\t%0.1lf\t\t\t\t%0.1lf\n", symb, ((Car*)(list -> head -> data))  -> TTI, ((Car*)(list -> head -> data)) -> TTI, clock);
          deleteNodeFromList(list, list -> head -> data);
          action = 1;
        }
      }
    }

    //If nothing happened, increment the timer
    if (!action)
    {
      clock += 0.5;
    }
  }
}
