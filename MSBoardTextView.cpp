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
    for (int idx_y = 0; idx_y<board_height; idx_y++) {
        for (int idx_x = 0; idx_x < board_width; idx_x++) {
            char fieldInfo = view.getFieldInfo(idx_x, idx_y);
            cout<<"["<<view.getFieldInfo(idx_x,idx_y)<<"]";
        }
        cout<<endl;
    }
}
