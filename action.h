//action.h
#include <iostream>
#include <string>
#include "structures.h"

#ifndef ACTION_H
#define ACTION_H
void buy(Cell Board[40], Player player);
void payrent(Cell Board[40], Player playerstep, Player playerown);
void buildproperty(Cell Board[40], Player playerstep);
#endif