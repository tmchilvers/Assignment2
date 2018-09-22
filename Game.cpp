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

void Game::promptGameMode()
{

}

void Game::promptCells()
{


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
    printGridEnter();
  }

  else if(outputControl == 2)
  {
    mode.printGrid();
  }

  else if(outputControl == 3)
  {
    string fileName;
    cout << "\nWhat would you like to name the file?: " << endl;
    cin >>
    mode.printGridFile(fileName);
  }
}

string Game::promptFileName()
{

}
