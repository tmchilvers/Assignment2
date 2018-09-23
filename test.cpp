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
  cout << g.countToroidal(grid2,39,54) << endl;
=======
  cout << g.countClassic(grid2,39,0) << endl;
>>>>>>> 67ab13470342dc268954d9a5238903ac7bc6e4be
  return 0;
}
