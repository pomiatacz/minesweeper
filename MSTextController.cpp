//
// Created by domin on 15.04.2019.
//
#include <iostream>
#include "MSTextController.h"
using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view) : board (board), view (view){}

void MSTextController::play()
{
    int x, y;

    cout << "**************** Witaj w grze Saper ****************\n";
    do
    {
        cout << "**************** Podaj wspolrzedna x ***************\n";
        cin >> x;
        cout << "**************** Podaj wspolrzedna y ***************\n";
        cin >> y;
        cout << "****************  Co chcesz zrobic ******************\n";
        cout << "****************  1.Odkryj pole na planszy **********\n";
        cout << "****************  2.Postaw flage*********************\n";
        view.game_display();
        int action;
        cout << "****************Podaj numer polecenia 1 lub 2 ********\n";
        cin >> action;
        switch (action)
        {
            case 1:
                board.revealField(x,y);
                view.game_display();

                break;
            case 2:
                board.toggleFlag(x,y);
                view.game_display();
                break;
            default:
                cout << "Twoj ruch jest nie poprawny!";
        }
        board.check_gamestate();
    }while(board.getGameState()==RUNNING);

}
