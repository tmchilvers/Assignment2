#include "Grid.h"
#include "GameMode.h"

using namespace std;



//constructors
GameMode::GameMode() { //default
  mode = 0;
}

GameMode::GameMode(int m) {
  mode = m;
}

void GameMode::update(Grid& grid) {
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
void GameMode::classicUpdate(Grid& grid) {
  Grid cloneGrid(grid);
  for(int i = 0; i < grid.getHeight(); i++) {
    for(int j = 0; j < grid.getWidth(); j++) {
      int count = countClassic(cloneGrid,i,j);
      if(count < 2) {
        grid.setCell(i,j,false);
      }
      else if(count == 3) {
        grid.setCell(i,j,true);
      }
      else if(count > 3) {
        grid.setCell(i,j,false);
      }
    }
  }
}
void GameMode::toroidalUpdate(Grid& grid) {
  Grid cloneGrid(grid);
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
    }
  }
}
void GameMode::mirrorUpdate(Grid& grid) {
  Grid cloneGrid(grid);
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
    }
  }
}

int GameMode::countClassic(Grid& grid, int i, int j) {
  int count = 0;
  if(i==0 ||
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
