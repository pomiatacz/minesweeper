#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "SFMLBoard.h"

using namespace std;

int main()
{
    srand(time(NULL));
    MinesweeperBoard board(10,10,DEBUG);

 //   board.debug_display();
 //   MSBoardTextView view ( board );
  //  MSTextController ctrl(board, view);
   // ctrl.play();
  SFMLBoard a(35,35,32);
    a.draw();
    return 0;
}
