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
    GameMode *mode; //gamemode class for updating grid each generation
    Grid *grid; //grid class to contain grid
    int returnMode; //whether game is returned with usleep, by pressing enter, or to a file
    string outputFileName; //path to output file

  public:
    //Constructors
    Game();
    //Destructor
    ~Game();

    //Mutator Functions
    void promptGameMode();//asks the user what gamemode they want and creates mode object
    void promptCells();//asks the user how they'd like to populate the grid
    void promptOutput();//asks the user how the game should be returned
    string promptFileName();//prompts for a file name and returns it as a string

    void gameLoop();//runs game

};

#endif
