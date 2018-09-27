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
Game::Game() //default constructor
{
  promptGameMode(); //constructor calls all methods for gameplay
  promptCells();
  promptOutput();
  gameLoop();

}

Game::~Game()
{
  delete grid;
  delete mode;
}


//Main Loop
void Game::gameLoop() {
  if(returnMode == 1) { //Game will loop on its own until termination
    int count = 0;
    bool loop = true;

    while(loop) {
      cout << "Generation " << count << endl;
      grid->printGrid();
      loop = mode->update(*grid);
      count++;
      usleep(100000);
    }
  }
  else if(returnMode == 2) {
    //Enter to update generations
    int count = 0;
    bool loop = true;
    while(loop) { //Game will loop when enter is pressed until termination
      cout << "Generation " << count << endl;
      grid->printGrid();
      cout << "Press Enter to Continue." << endl;
      cin.ignore();
      loop = mode->update(*grid);
      count++;
    }

  }
  else if(returnMode == 3) {
    //output game to file prompted for earlier
  }
  else {
    cout << "An error has occured. Execution terminated." << endl;
  }
}



void Game::promptGameMode() //prompts user for gamemode
{
  while(true){
    string gameModeControl;
    cout << "What mode would you like to play in: " << endl;
    cout << "1. classic" << endl;
    cout << "2. donut" << endl;
    cout << "3. mirror" << endl;
    getline(cin,gameModeControl);
    if(gameModeControl == "1") {
      mode = new GameMode;
      cout << "Classic mode selected!" << endl;
      break;
    }
    else if(gameModeControl == "2") {
      mode = new GameMode(1);
      cout << "Donut mode selected!" << endl;
      break;
    }
    else if(gameModeControl == "3") {
      mode = new GameMode(2);
      cout << "Classic mode selected!" << endl;
      break;
    }
    else {
      //catch errors
      cout << "Invalid input." << endl;

    }
  }
}

void Game::promptCells() //prompts user for map file or dimensions
{
  string inputControl;
  cout << "Would you like to read a map file ('1') or provide dimensions\nand density for a random grid of cells ('2')?" << endl;
  cout << "1. Read map file." << endl;
  cout << "2. Provide dimensions and density." << endl;
  getline(cin,inputControl);
  if(inputControl == "2") {

    cout << "Height:\n";
    //prompt for height as str and convert to int
    int height;
    cin >> height;

    if (cin.fail())
    {
      cerr << "ERROR Invalid input. Exit Program." << endl;
      exit(EXIT_FAILURE);
    }

    //prompt for width as str and convert to int
    cout << "Width:\n";
    int width;
    cin >> width;

    if (cin.fail())
    {
      cerr << "ERROR Invalid input. Exit Program." << endl;
      exit(EXIT_FAILURE);
    }

    //prompt for density as str and convert to int
    cout << "Population Density:\n";
    double density;
    cin >> density;

    if (cin.fail())
    {
      cerr << "ERROR Invalid input. Exit Program." << endl;
      exit(EXIT_FAILURE);
    }

    grid = new Grid(height,width,density);
  }
  else if (inputControl == "1") {
    grid = new Grid(promptFileName());
  }
  else
  {
    cerr << "ERROR Invalid input. Exit Program." << endl;
    exit(EXIT_FAILURE);
  }
}

void Game::promptOutput() //Prompts how the user would like game outputted
{
  int outputControl;
  cout << "How do you want this game outputted for you?" << endl;
  cout << "If you want to have a brief pause between each generation, enter '1': " << endl;
  cout << "If you want to press the enter key for each generation to appear, enter '2': " << endl;
  cout << "If you want to output everything to a file, enter '3': " << endl;

  cin >> outputControl;
  if (cin.fail())
  {
    cerr << "ERROR Invalid input. Exit Program." << endl;
    exit(EXIT_FAILURE);
  }

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

string Game::promptFileName() //prompts the user for a file path
{
  while(true) {
    string fileName;
    cout << "\nWhat is the name of the file?: " << endl;
    getline(cin,fileName);
    //Check to make sure file exists
    ifstream f;
    f.open(fileName);
    if(f) {
      f.close();
      return fileName;
    }
    else {
      cout << "File not found. Try again." << endl;
    }
  }
}
