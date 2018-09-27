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
    Grid(Grid& other); // copy constructor

    //Destructor
    ~Grid();

    //Mutator functions
    void genGrid(); //creates array framework
    void setGrid(ifstream& mapFile); //sets array based off of a mapfile
    void setGrid(double density); //sets grid using height width and density
    void setGrid(); //sets grid randomly
    void setHeight(int h);
    void setWidth(int w);
    void setCell(int i, int j, bool val);

    //Accessor functions
    int getHeight();
    int getWidth();
    bool getCell(int i, int j);
    void printGrid(); // prints grid to standard out
    void printGridFile(ifstream& outFile); // attempts to print grid to outFile

  private:
    bool **gameGrid;
    int height;
    int width;
};

#endif
