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
  cout << g.countClassic(grid2,39,0) << endl;
  return 0;
}
