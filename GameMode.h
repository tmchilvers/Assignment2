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

  int countClassic(const Grid& grid, int i, int j);
  int countToroidal(const Grid& grid, int i, int j);
  int countMirror(const Grid& grid, int i, int j);

private:
  int mode;
};
