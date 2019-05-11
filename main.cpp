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
    sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper!");
    srand(time(NULL));
    MinesweeperBoard board(10,10,DEBUG);
    MSSFMLView view(board);


//  board.debug_display();
 // MSBoardTextView view ( board );
 // MSTextController ctrl(board, view);
// ctrl.play();


    while(window.isOpen())
    {


        window.clear();
        view.draw(window,35,35,32);
        window.display();


    }
//  SFMLBoard a(35,35,32);
//  a.draw(window);
    return 0;
}
