#include "Grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

Grid::Grid() //default
{
  setHeight(10);
  setWidth(10);
  //generate random cells and dimensions
  genGrid(10,10);
  setGrid(height, width);
}

Grid::Grid(int height, int width)
{
  //generate random cells
  genGrid(height,width);
  setGrid(height, width);
}

Grid::Grid(ifstream& mapFile)
{
  //read in the height and width
  genGrid(mapFile);
  setGrid(mapFile);
}


//mutator methods

void Grid::genGrid(ifstream& mapFile) {
  int width;
  int height;
  getline(mapFile,height);
  getline(mapFile,width);
  gameGrid = new int[width];
  for(int i = 0; i < width; i++) {
    gameGrid[i] = new int[height][1];
    for(int j = 0; j < height; j++) {
      gameGrid[i][j][0] = 0;
    }
  }
}
void Grid::genGrid(int height, int width) {
  //generates grid with 2 given parameters: height and width
  gameGrid = new int[width];
  for(int i = 0; i < width; i++) {
    gameGrid[i] = new int[height][1];
    for(int j = 0; j < height; j++) {
      gameGrid[i][j][0] = 0;
    }
  }
}

void Grid::setGrid(ifstream& mapFile)
{
  //Populate grid from file
  string line;
  for(int i = 0; i < height; i++)
  {
    getline(mapFile, line);

    for(int j = 0; j < width; j++)
    {
      if(line[j] == '-')
      {
        gameGrid[i][j][0] = 0;
      }

      else if(line[j] == 'X' || line[j] == 'x')
      {
        gameGrid[i][j][0] = 1;
      }

      else
      {
        //catch/throw error - end program
      }
    }
  }
}

void Grid::setGrid(int height, int width)
{
  //Populate grid randomly
  srand(time(NULL));
  int num = rand() % 2;

  if(num == 0)
  {
    gameGrid[i][j][0] = 0;
  }

  else if(num == 1)
  {
    gameGrid[i][j][0] = 1;
  }
}







//note: may need copy constrcutor for shadow thing
