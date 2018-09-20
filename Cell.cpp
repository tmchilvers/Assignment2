#include "Cell.h"

Cell::Cell() {
  this->alive = false;
}

Cell::ostream & operator << (ostream & out) {
  if (alive) {
    return 'x';
  }
  else {
    return '-';
  }
}
