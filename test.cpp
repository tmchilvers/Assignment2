#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <unistd.h>
#include <string>
#include "Grid.h"
#include "GameMode.h"

using namespace std;

int main() {

  Grid grid1(40,60);
  grid1.printGrid();
  cout << "\n";
  Grid grid2("mapFile.txt");
  cout << grid2.getCell(2,7) << endl;
  grid2.printGrid();
  //cout << grid2.getHeight() - 1 << endl;

  GameMode g;
<<<<<<< HEAD
  cout << g.countClassic(grid2,39,0) << endl;
=======
  cout << g.countToroidal(grid2,0,0) << endl;
  cout << g.countClassic(grid2,0,0) << endl;
  cout << g.countMirror(grid2,0,0) << endl;
>>>>>>> b448343f95460e4fb4f9f86630d929a56c3bd552
  return 0;
}
