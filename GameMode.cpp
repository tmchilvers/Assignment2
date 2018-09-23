#include "Grid.h"
#include "GameMode.h"
#include <functional>

using namespace std;



//constructors
GameMode::GameMode() { //default
  mode = 0;
}

GameMode::GameMode(int mode) {

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

}
void GameMode::toroidalUpdate(Grid& grid) {

}
void GameMode::mirrorUpdate(Grid& grid) {

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
    }
    //Top row
    else if(i==0) {
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
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
    }
    //left column
    else if(j==0) {
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
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
    }
    //right column
    else if(j==grid.getWidth()-1) {
      if(grid.getCell(i+1,j)) {
        count++;
      }
      if(grid.getCell(i-1,j)) {
        count++;
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
    }
    //bottom row
    else if(i==grid.getHeight()-1) {
      if(grid.getCell(i,j+1)) {
        count++;
      }
      if(grid.getCell(i,j-1)) {
        count++;
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
  }
  return count;
}

int GameMode::countToroidal(Grid& grid, int i, int j) {
  int count = 0;
  if (grid.getCell(((i+1)%grid.getHeight()),(j%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell(std::modulus<int>(i-1,grid.getHeight()),(j%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell((i%grid.getHeight()),((j+1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell((i%grid.getHeight()),((j-1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell(((i+1)%grid.getHeight()),((j+1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell(((i-1)%grid.getHeight()),((j+1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell(((i+1)%grid.getHeight()),((j-1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
  }
  if (grid.getCell(((i-1)%grid.getHeight()),((j-1)%grid.getWidth()))) {
    cout << "hi\n";
    count++;
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
  }
  return count;
}
