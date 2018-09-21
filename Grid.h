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
    Grid(int height, int width); //random cells only
    Grid(ifstream& mapFile); //file input

    //Destructor
    ~Grid();

    //Mutator functions
    void genGrid(ifstream& mapFile);
    void genGrid(int height, int width);
    void setGrid(ifstream& mapFile);
    void setGrid(int height, int width);
    void setHeight(int h) { this->height = h; }
    void setWidth(int w) { this->width = w; }

    //Accessor functions
    int getHeight() { return height; }
    int getWidth() { return width; }

    int **gameGrid;
  private:

    int height;
    int width;
};
