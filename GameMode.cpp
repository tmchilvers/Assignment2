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

int countClassic(const Grid& grid, int i, int j) {
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

int countToroidal(const Grid& grid, int i, int j) {

}

int countMirror()const Grid& grid, int i, int j {
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
    //right column
    else if(j==grid.getWidth()-1) {
      if(grid.getCell(i+1,j)) {
        count+=2;
      }
      if(grid.getCell(i-1,j)) {
        count+2;
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
      if(grid.getCell(i-1)) {
        count++;
      }
      if(grid.getCell(i-1,j-1)) {
        count++;
      }
    }
    //bottom right corner
    if(i==grid.getHeight()-1 && j==grid.getWidth()-1) {
      if(grid.getCell(i,j)) {
        count+=3;
      }
      if(grid.getCell(i-1)) {
        count+=2;
      }
      if(grid.getCell(j-1)) {
        count+=2;
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
  }
  return count;
}
