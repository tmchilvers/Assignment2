#include <iostream>
#include <fstream>

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
    void setGrid(ifstream& mapFile);
    void randSetGrid(int height, int width);

  private:
    int *gameGrid;
}
