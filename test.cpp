#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <unistd.h>
#include <string>
#include "Grid.h"

using namespace std;

int main() {
/*for(int k = 0; k < 100; k++) {
  cout << string( 100, '\n' );
  cout << "Generation " << k+1 << endl;
  for(int i = 0; i < 30; i++){
    for(int j = 0; j < 20; j++){
      if (i==7 && j==4 && k%2==0) {
        cout << "x ";
        continue;
      }
      if (i==18 && j==13 && k%3==0) {
        cout << "x ";
        continue;
      }
      if (i==24 && j==9 && k%5==0) {
        cout << "x ";
        continue;
      }
      cout << "- ";

    }
    cout << "\n";

  }
  sleep(1);
}*/
  Grid grid1(40,60);
  grid1.printGrid();
  cout << "\n";
  Grid grid2("mapFile.txt");
  cout << grid2.getCell(2,7) << endl;
  grid2.printGrid();
  return 0;
}
