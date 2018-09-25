#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "Grid.h"

using namespace std;

class GameMode {
public:
  //ructors
  GameMode(); //default
  GameMode(int m);

  bool update(Grid& grid);
  bool classicUpdate(Grid& grid);
  bool toroidalUpdate(Grid& grid);
  bool mirrorUpdate(Grid& grid);
  bool compareUpdate(Grid& grid, Grid& otherGrid, int i, int j);

  int countClassic(Grid& grid, int i, int j);
  int countToroidal(Grid& grid, int i, int j);
  int countMirror(Grid& grid, int i, int j);

private:
  int mode;
};

#endif
