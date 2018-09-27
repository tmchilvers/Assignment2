#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "Grid.h"

using namespace std;

class GameMode {
public:
  //ructors
  GameMode(); //default
  GameMode(int m);//overloaded with mode parameter

  bool update(Grid& grid);//selects correct update mode based off of private int mode
  bool classicUpdate(Grid& grid);//updates in classic mode
  bool toroidalUpdate(Grid& grid);//updates in toroidal mode(donut mode)
  bool mirrorUpdate(Grid& grid);//updates in mirror mode
  bool compareUpdate(Grid& grid, Grid& otherGrid, int i, int j);//compares 2 cells for haromny

  int countClassic(Grid& grid, int i, int j);//counts neighbors in classic mode
  int countToroidal(Grid& grid, int i, int j);//counts neighbors in donut mode
  int countMirror(Grid& grid, int i, int j);//counts neighbors in mirror

private:
  int mode;
};

#endif
