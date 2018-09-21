#include "Grid.h"
#include <string>

using namespace std;

Grid::Grid() //default
{
  //generate random cells and dimensions
  gameGrid = new int[height][width][2];
  randSetGrid(height, width);
}

Grid::Grid(int height, int width)
{
  //generate random cells
  gameGrid = new int[height][width][2];
  randSetGrid(height, width);
}

Grid::Grid(ifstream& mapFile)
{
  //read in the height and width
  gameGrid = new int[height][width][2];
  setGrid(mapFile);
}


//mutator methods
void Grid::setGrid(ifstream& mapFile)
{
  string line;
  for(int i = 0; i < height; i++)
  {
    getline(mapFile, line);

    for(int j = 0; j < width, j++)
    {
      if(line[j] == '-')
      {
        cell gridboardarray[i][j].dead();
      }

      else if(line[j] == 'X' || line[j] == 'x')
      {
        cell gridboardarray[i][j].alive();
      }

      else
      {
        //catch/throw error - end program
      }
    }
  }
}

void Grid::randSetGrid(int height, int width)
{
  int num = rand() % 2;

  if(num == 0)
  {
    gridboardarray[i][j].dead();
  }

  else if(num == 1)
  {
    gridboardarray[i][j].alive();
  }
}





//note: may need copy constrcutor for shadow thing
