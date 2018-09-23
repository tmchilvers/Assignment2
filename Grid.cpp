#include "Grid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

//Constructors =======================================================

Grid::Grid() //default
{
  width = 10;
  height = 10;
  genGrid(); //Empty grid is generated with given dimensions
  setGrid();
}

Grid::Grid(int h, int w)
{
  width = w;
  height = h;
  genGrid(); //Empty grid is generated with given dimensions
  setGrid();
}

Grid::Grid(string filePath)
{
  ifstream mapFile;
  mapFile.open(filePath); //open input stream from file path
  //read in the height and width
  string heightStr; //Arbitrary strings because getline requires an std::string for second arg
  string widthStr;
  getline(mapFile,heightStr);
  getline(mapFile,widthStr);
  height = stoi(heightStr); //convert string variables to ints
  width = stoi(widthStr);

  genGrid(); //Empty grid is generated with given dimensions
  setGrid(mapFile);
  mapFile.close();
}

Grid::~Grid() { //destructor initially deleted inner arrays then finally main array
  for(int i = 0; i < height; i++) {
    delete gameGrid[i];
  }
  delete gameGrid;
  cout << "Grid deleted." << endl;
}


//mutator methods ====================================================

void Grid::genGrid() {
  //generates empty grid array with previously set height and width
  gameGrid = new bool*[height]; //array of length height of boolean pointers
  for(int i = 0; i < height; i++) {
    gameGrid[i] = new bool[width]; //2nd dimension of boolean array
    for(int j = 0; j < width; j++) {
      gameGrid[i][j] = false; //set default values to false (dead)
    }
  }
}

void Grid::setGrid(ifstream& mapFile) //overloaded setGrid function
{
  //Populate grid from file
  string line;
  for(int i = 0; i < height; i++)
  {
    getline(mapFile, line); //reads in a line from file

    for(int j = 0; j < width; j++)
    {
      if(line[j] == '-')
      {
        gameGrid[i][j] = false; //if a dash is found in the file, cell set to false
      }

      else if(line[j] == 'X' || line[j] == 'x')
      {
        gameGrid[i][j] = true; //if an x is found, cell set to true
      }

      else
      {
        //catch/throw error - end program
      }
    }
  }
}

void Grid::setGrid() //default setGrid populates the grid with random true and false
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

//Accessors ==========================================================
void Grid::printGrid() { //prints grid through std::cout formatted to appear visually accurate
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(gameGrid[i][j]) {
        cout << "x ";
      }
      else if(!gameGrid[i][j]) {
        cout << "- ";
      }
    }
    cout << endl;
  }
}

void Grid::printGridFile(string fileName) { //prints grid through std::cout formatted to appear visually accurate
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(gameGrid[i][j]) {
        cout << "x ";
      }
      else if(!gameGrid[i][j]) {
        cout << "- ";
      }
    }
    cout << endl;
  }
}


//note: may need copy constrcutor for shadow thing
