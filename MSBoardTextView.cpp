//
// Created by dominik on 26.03.19.
//

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include <iostream>

using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &gameboard) : view (gameboard)


{

}



void MSBoardTextView::game_display() {

    int board_height=view.getBoardHeight();
    int board_width=view.getBoardWidth();
    for (int y = 0; y<board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            cout<<"["<<view.getFieldInfo(x,y)<<"]";
        }
        cout<<endl;
    }
}
