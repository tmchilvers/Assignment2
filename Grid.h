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
    Grid(int h, int w, double d); //random cells only
    Grid(string filePath); //file input
    Grid(Grid& other);

    //Destructor
    ~Grid();

    //Mutator functions
    void genGrid();
    void setGrid(ifstream& mapFile);
    void setGrid(double density);
    void setGrid();
    void setHeight(int h);
    void setWidth(int w);
    void setCell(int i, int j, bool val);

    //Accessor functions
    int getHeight();
    int getWidth();
    bool getCell(int i, int j);
    void printGrid();
    void printGridFile(string fileName);

  private:
    bool **gameGrid;
    int height;
    int width;
};

#endif
