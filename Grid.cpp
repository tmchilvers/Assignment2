#include "Grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//Constructors

Grid::Grid() //default
{
  width = 10;
  height = 10;
  //generate random cells and dimensions
  genGrid();
  setGrid();
}

Grid::Grid(int h, int w)
{
  width = w;
  height = h;
  //generate random cells
  genGrid();
  setGrid();
}

Grid::Grid(ifstream& mapFile)
{
  //read in the height and width
  genGrid();
  setGrid(mapFile);
}

Grid::~Grid() { //destructor initially deleted inner arrays then finally main array
  for(int i = 0; i < height; i++) {
    delete gameGrid[i];
  }
  delete gameGrid;
  cout << "Grid deleted." << endl;
}


//mutator methods

void Grid::genGrid() {
  //generates empty grid array with previously set height and width
  gameGrid = new bool*[height];
  for(int i = 0; i < height; i++) {
    gameGrid[i] = new bool[width];
    for(int j = 0; j < width; j++) {
      gameGrid[i][j] = false;
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
        gameGrid[i][j] = false;
      }

      else if(line[j] == 'X' || line[j] == 'x')
      {
        gameGrid[i][j] = true;
      }

      else
      {
        //catch/throw error - end program
      }
    }
  }
}

void Grid::setGrid()
{
  //Populate grid randomly
  srand(time(NULL));
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      int num = rand() % 2;

      if(num == 0)
      {
        gameGrid[i][j] = false;
      }

      else if(num == 1)
      {
        gameGrid[i][j] = true;
      }
    }
  }
}

//Accessors
void Grid::printGrid() {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(gameGrid[j][i]) {
        cout << 'x';
      }
      else if(!gameGrid[i][j]) {
        cout << '-';
      }
    }
    cout << endl;
  }
}


//note: may need copy constrcutor for shadow thing
