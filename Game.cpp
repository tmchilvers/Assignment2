#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <unistd.h>
#include <string>
#include "Grid.h"
#include "GameMode.h"

//Constructors
Game::Game()
{
  promptGameMode();
  promptCells();
  promptOutput();
  gameLoop();

}

Game::~Game()
{

}


//Main Loop
void Game::gameLoop() {
  while(true) {
    grid->printGrid();
    mode->update(grid);
    usleep(100000);
  }
}



void Game::promptGameMode()
{
  int gameModeControl;
  cout << "What mode would you like to play in: " << endl;
  cout << "1. classic" << endl;
  cout << "2. donut" << endl;
  cout << "3. mirror" << endl;
  cin >> gameModeControl;
  if(gameModeControl == 1) {
    mode = new GameMode;
  }
  else if(gameModeControl == 2) {
    mode = new GameMode(1);
  }
  else if(gameModeControl == 3) {
    mode = new GameMode(2);
  }
  else {
    //catch errors
  }
}

void Game::promptCells()
{
  int inputControl;
  cout << "Would you like to read a map file ('1') or provide dimensions\nand density for a random grid of cells ('2')?" << endl;
  cout << "1. Read map file." << endl;
  cout << "2. Provide dimensions and density." << endl;
  cin >> inputControl;

  if(inputControl == 1) {
    cout << "Height:\n";
    int height;
    cin >> height;
    cout << "Width:\n";
    int width;
    cin >> width;
    cout << "Population Density:\n";
    double density;
    cin >> density;
    grid = new Grid(height,width,density);
  }
  else if (inputControl == 2) {
    grid = new Grid(promptFileName());
  }
}

void Game::promptOutput()
{
  int outputControl;
  cout << "How do you want this game outputted for you?" << endl;
  cout << "If you want to have a brief pause between each generation, enter '1': " << endl;
  cout << "If you want to press the enter key for each generation to appear, enter '2': " << endl;
  cout << "If you want to output everything to a file, enter '3': " << endl;
  cin >> outputControl;

  if(outputControl == 1)
  {
    returnMode = 1;
  }

  else if(outputControl == 2)
  {
    returnMode = 2;
  }

  else if(outputControl == 3)
  {
    returnMode = 3;
    outputFileName = promptFileName();
  }
}

string Game::promptFileName()
{
  string fileName;
  cout << "\nWhat is the name of the file?: " << endl;
  cin >> fileName;
  return fileName;
}
