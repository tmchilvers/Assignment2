

class Cell {
public:
  //Constructors
  Cell(); //default
  ~Cell(); //destructor

  bool alive;

  ostream & operator << (ostream & out);

  //
};
