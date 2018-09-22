#include "Grid.h"
#include "GameMode.h"

using namespace std;



//constructors
GameMode() { //default
  mode = 0;
}

GameMode(int mode) {

}

void update(Grid& grid) {
  if (mode == 0) {
    classicUpdate(grid);
  }
  else if (mode == 1) {
    toroidalUpdate(grid);
  }
  else if (mode == 2) {
    mirrorUpdate(grid);
  }
  else {
    //error checking
  }
}
void classicUpdate(Grid& grid) {

}
void toroidalUpdate(Grid& grid) {

}
void mirrorUpdate(Grid& grid) {

}

int countNeighbors(int i, int j) {
  int count = 0;
      if (grid.getCell(i+1,j)) {
        count++;
      }
      else if (grid.getCell(i-1,j)) {
        count++;
      }
      else if (grid.getCell(i,j+1)) {
        count++;
      }
      else if (grid.getCell(i,j-1)) {
        count++;
      }
      else if (grid.getCell(i+1,j+1)) {
        count++;
      }
      else if (grid.getCell(i-1,j+1)) {
        count++;
      }
      else if (grid.getCell(i+1,j+1)) {
        count++;
      }
      else if (grid.getCell(i-1,j-1)) {
        count++;
      }
      return count;
    }
  }
}
