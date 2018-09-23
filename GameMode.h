#include "Grid.h"

using namespace std;

class GameMode {
public:
  //ructors
  GameMode(); //default
  GameMode(int mode);

  void update(Grid& grid);
  void classicUpdate(Grid& grid);
  void toroidalUpdate(Grid& grid);
  void mirrorUpdate(Grid& grid);

  int countClassic(Grid& grid, int i, int j);
  int countToroidal(Grid& grid, int i, int j);
  int countMirror(Grid& grid, int i, int j);

private:
  int mode;
};
