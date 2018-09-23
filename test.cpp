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

  //Grid grid1(40,60);
  //grid1.printGrid();
  //cout << "\n";
  Grid grid2("mapFile.txt");
  cout << grid2.getCell(2,7) << endl;
  grid2.printGrid();
  //cout << grid2.getHeight() - 1 << endl;

  GameMode g;

  for(int i = 0; i < 240; i++) {
    //cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    g.update(grid2);
    grid2.printGrid();
    usleep(100000);
  }
  return 0;
}
