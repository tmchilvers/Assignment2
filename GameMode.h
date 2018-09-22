#include "Grid.h"

using namespace std;

class GameMode {
public:
  //constructors
  GameMode(); //default
  GameMode(int mode);

  void update(Grid& grid);
  void classicUpdate(Grid& grid);
  void toroidalUpdate(Grid& grid);
  void mirrorUpdate(Grid& grid);

  int countNeighbors(const Grid& grid);

private:
  int mode;
};
