#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Grid
{

  public:
    //constructors
    Grid(); //default
    Grid(int h, int w); //random cells only
    Grid(string filePath); //file input

    //Destructor
    ~Grid();

    //Mutator functions
    void genGrid();
    void setGrid(ifstream& mapFile);
    void setGrid();
    void setHeight(int h);
    void setWidth(int w);

    //Accessor functions
    int getHeight();
    int getWidth();
    bool getCell(int h, int w);
    void printGrid();
    void printGridFile(string fileName);

  private:
    bool **gameGrid;
    int height;
    int width;
};

#endif
