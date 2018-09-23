#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "Grid.h"
#include "GameMode.h"
#include <fstream>


using namespace std;

class Game
{
  private:
    //instance variables
    GameMode *mode; //maybe pointer?
    Grid *grid; //maybe pointer?
    int returnMode;
    string outputFileName;

  public:
    //Constructors
    Game();
    //Destructor
    ~Game();

    //Mutator Functions
    void promptGameMode();
    void promptCells();
    void promptOutput();
    string promptFileName();

    void printGen();
    void printGridEnter();
    void gameLoop();

};

#endif
