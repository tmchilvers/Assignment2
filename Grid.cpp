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

Grid::~Grid() {
  for(int i = 0; i < width; i++) {
    delete gameGrid[i];
  }
  delete gameGrid;
  cout << "Grid deleted." << endl;
}


//mutator methods

void Grid::genGrid(ifstream& mapFile) {
  string widthStr;
  string heightStr;
  getline(mapFile,heightStr);
  getline(mapFile,widthStr);
  int width = stoi(widthStr);
  int height = stoi(heightStr);
  gameGrid = new int*[width];
  for(int i = 0; i < width; i++) {
    gameGrid[i] = new int[height];
  }
}
void Grid::genGrid(int height, int width) {
  //generates grid with 2 given parameters: height and width
  gameGrid = new int*[width];
  for(int i = 0; i < width; i++) {
    gameGrid[i] = new int[height];
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
        gameGrid[j][i] = 0;
      }

      else if(line[j] == 'X' || line[j] == 'x')
      {
        gameGrid[j][i] = 1;
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
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      int num = rand() % 2;

      if(num == 0)
      {
        gameGrid[j][i] = 0;
      }

      else if(num == 1)
      {
        gameGrid[j][i] = 1;
      }
    }
  }
}







//note: may need copy constrcutor for shadow thing
