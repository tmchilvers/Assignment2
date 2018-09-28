#include "Grid.h"
#include "GameMode.h"

using namespace std;

//Constructors==================================================================
GameMode::GameMode() { //default
  mode = 0;
}

GameMode::GameMode(int m) {//Creates gamemode with m as the mode(0 = classic, 1 = donut, 2 = mirror)
  mode = m;
}


//Auxiliary methods=============================================================
bool GameMode::compareUpdate(Grid& grid, Grid& otherGrid, int i, int j)
{ //Takes 2 grids and coords as input and returns true if compared sells are both alive or both dead
  return grid.getCell(i,j) == otherGrid.getCell(i,j);
}

bool GameMode::update(Grid& grid) {//selects appropriate update func based off mode var
  if (mode == 0) { //returns true
    return classicUpdate(grid);
  }
  else if (mode == 1) {
    return toroidalUpdate(grid);
  }
  else if (mode == 2) {
    return mirrorUpdate(grid);
  }
  else {
    //error checking
  }
}

bool GameMode::classicUpdate(Grid& grid) {//updates a grid in classic mode
  Grid cloneGrid(grid);
  bool ifEquals = true;
  int countFalse = 0;

  for(int i = 0; i < grid.getHeight(); i++) {
    for(int j = 0; j < grid.getWidth(); j++) {
      int count = countClassic(cloneGrid,i,j);//checks cells in cloned grid
      if(count < 2) {
        grid.setCell(i,j,false);//updates cells on original grid
      }
      else if(count == 3) {
        grid.setCell(i,j,true);
      }
      else if(count > 3) {
        grid.setCell(i,j,false);
      }
      ifEquals = compareUpdate(grid, cloneGrid, i, j);
//ifEquals remains true if cell remains unchanged
      if(ifEquals == false)//if at any point ifEquals becomes false, the grids are different and another update will be needed
      {
        countFalse++;
      }
    }
  }
  if(countFalse > 0)
  {
    return true; //true means run again
  }

  else
  {
    return false; //if false, do not run again
  }
}

bool GameMode::toroidalUpdate(Grid& grid) { //works identical to classicUpdate but in donut mode
  Grid cloneGrid(grid);
  bool ifEquals = true;
  int countFalse = 0;

  for(int i = 0; i < grid.getHeight(); i++) {
    for(int j = 0; j < grid.getWidth(); j++) {
      int count = countToroidal(cloneGrid,i,j);
      if(count < 2) {
        grid.setCell(i,j,false);
      }
      else if(count == 3) {
        grid.setCell(i,j,true);
      }
      else if(count > 3) {
        grid.setCell(i,j,false);
      }

      ifEquals = compareUpdate(grid, cloneGrid, i, j);

      if(ifEquals == false)
      {
        countFalse++;
      }
    }
  }
  if(countFalse > 0)
  {
    return true; //true means run again
  }

  else
  {
    return false; //if false, do not run again
  }
}

bool GameMode::mirrorUpdate(Grid& grid) { //works identical to classicUpdate but in mirror mode
  Grid cloneGrid(grid);
  bool ifEquals = true;
  int countFalse = 0;

  for(int i = 0; i < grid.getHeight(); i++) {
    for(int j = 0; j < grid.getWidth(); j++) {
      int count = countMirror(cloneGrid,i,j);
      if(count < 2) {
        grid.setCell(i,j,false);
      }
      else if(count == 3) {
        grid.setCell(i,j,true);
      }
      else if(count > 3) {
        grid.setCell(i,j,false);
      }

      ifEquals = compareUpdate(grid, cloneGrid, i, j);

      if(ifEquals == false)
      {
        countFalse++;
      }
    }
  }
  if(countFalse > 0)
  {
    return true; //true means run again
  }

  else
  {
    return false; //if false, do not run again
  }
}

int GameMode::countClassic(Grid& grid, int i, int j) {
  //If cell is an edge or corner, it is handled specifically based off of location
  //If cell is not an edge or corner, the 8 surroudning are counted
  int count = 0;
  if(i==0 || //checks if current cell is a corner or edge cell
     i==grid.getHeight()-1 ||
     j==0 ||
     j==grid.getWidth()-1) {
    //top left corner
    if(i==0 && j==0) {
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      return count;
    }
    //top right corner
    if(i==0 && j==grid.getWidth()-1) {
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //Top row
    else if(i==0) {
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //bottom left corner
    if(i==grid.getHeight()-1 && j==0) {
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      return count;
    }
    //left column
    else if(j==0) {
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      return count;
    }
    //bottom right corner
    if(i==grid.getHeight()-1 && j==grid.getWidth()-1) {
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      return count;
    }
    //right column
    else if(j==grid.getWidth()-1) {
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //bottom row
    else if(i==grid.getHeight()-1) {
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      return count;
    }
  }
  //non-edges
  else {
    if (grid.getCell(i+1,j)) {
      count++;
    }
    if (grid.getCell(i-1,j)) {
      count++;
    }
    if (grid.getCell(i,j+1)) {
      count++;
    }
    if (grid.getCell(i,j-1)) {
      count++;
    }
    if (grid.getCell(i+1,j+1)) {
      count++;
    }
    if (grid.getCell(i-1,j+1)) {
      count++;
    }
    if (grid.getCell(i+1,j-1)) {
      count++;
    }
    if (grid.getCell(i-1,j-1)) {
      count++;
    }
    return count;
  }
}

int GameMode::countToroidal(Grid& grid, int i, int j) {
  //array wrap around created using modulus
  //Aside from that, surrounding 8 cells are counted normally
  //% in c++ acts as a remainder instead of traditional modulus
  //that is handled through if/else if/else
  int count = 0;
  if (i == 0 && j == 0) {
    if (grid.getCell(((i+1)%grid.getHeight()),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + (i-1)%grid.getHeight(),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + ((i-1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + ((i-1)%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
  }

  else if(i == 0) {
    if (grid.getCell(((i+1)%grid.getHeight()),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + (i-1)%grid.getHeight(),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + ((i-1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(grid.getHeight() + ((i-1)%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
  }

  else if(j == 0) {
    if (grid.getCell(((i+1)%grid.getHeight()),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i-1)%grid.getHeight(),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i-1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i-1)%grid.getHeight()),(grid.getWidth() + (j-1)%grid.getWidth()))) {

      count++;
    }
  }

  else {
    if (grid.getCell(((i+1)%grid.getHeight()),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i-1)%grid.getHeight(),(j%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell((i%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i-1)%grid.getHeight()),((j+1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i+1)%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
    if (grid.getCell(((i-1)%grid.getHeight()),((j-1)%grid.getWidth()))) {

      count++;
    }
  }
  return count;
}

int GameMode::countMirror(Grid& grid, int i, int j) {
  //If cell is an edge or corner, it is handled specifically based off of location
  //If cell is not an edge or corner, the 8 surroudning are counted
  int count = 0;
  if(i==0 ||
     i==grid.getHeight()-1 ||
     j==0 ||
     j==grid.getWidth()-1) {
    //top left corner
    if(i==0 && j==0) {
      if(grid.getCell(i,j)) {
        count += 3;
      }
      if(grid.getCell(i,j+1)) {
        count+=2;
      }
      if(grid.getCell(i+1,j)) {
        count+=2;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      return count;
    }
    //top right corner
    if(i==0 && j==grid.getWidth()-1) {
      if(grid.getCell(i,j)) {
        count+=3;
      }
      if(grid.getCell(i,j-1)) {
        count+=2;
      }
      if(grid.getCell(i+1,j)) {
        count+=2;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //Top row
    else if(i==0) {
      if(grid.getCell(i,j+1)) {
        count+=2;
      }
      if(grid.getCell(i,j-1)) {
        count+=2;
      }
      if(grid.getCell(i,j)) {
        count++;
      }
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //bottom left corner
    if(i==grid.getHeight()-1 && j==0) {
      if(grid.getCell(i,j)) {
        count+=3;
      }
      if(grid.getCell(i-1,j)) {
        count+=2;
      }
      if(grid.getCell(i,j+1)) {
        count+=2;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      return count;
    }
    //left column
    else if(j==0) {
      if(grid.getCell(i+1,j)) {
        count+=2;
      }
      if(grid.getCell(i-1,j)) {
        count+=2;
      }
      if(grid.getCell(i,j)) {
        count++;
      }
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      if(grid.getCell(i+1,j+1)) {
        count++;
      }
      return count;
    }
    //bottom right corner
    if(i==grid.getHeight()-1 && j==grid.getWidth()-1) {
      if(grid.getCell(i,j)) {
        count+=3;
      }
      if(grid.getCell(i-1,j)) {
        count+=2;
      }
      if(grid.getCell(i,j-1)) {
        count+=2;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      return count;
    }
    //right column
    else if(j==grid.getWidth()-1) {
      if(grid.getCell(i+1,j)) {
        count+=2;
      }
      if(grid.getCell(i-1,j)) {
        count+=2;
      }
      if(grid.getCell(i,j)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      if(grid.getCell(i+1,j-1)) {
        count++;
      }
      return count;
    }
    //bottom row
    else if(i==grid.getHeight()-1) {
      if(grid.getCell(i,j+1)) {
        count+=2;
      }
      if(grid.getCell(i,j-1)) {
        count+=2;
      }
      if(grid.getCell(i,j)) {
        count++;
      }
      if(grid.getCell(i-1,j+1)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
      return count;
    }
  }
  //non-edges
  else {
    if (grid.getCell(i+1,j)) {
      count++;
    }
    if (grid.getCell(i-1,j)) {
      count++;
    }
    if (grid.getCell(i,j+1)) {
      count++;
    }
    if (grid.getCell(i,j-1)) {
      count++;
    }
    if (grid.getCell(i+1,j+1)) {
      count++;
    }
    if (grid.getCell(i-1,j+1)) {
      count++;
    }
    if (grid.getCell(i+1,j-1)) {
      count++;
    }
    if (grid.getCell(i-1,j-1)) {
      count++;
    }
  return count;
  }
}
