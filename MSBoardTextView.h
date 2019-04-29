//
// Created by domin on 15.04.2019.
//

#ifndef MINESWEEPER_MSBOARDTEXTVIEW_H
#define MINESWEEPER_MSBOARDTEXTVIEW_H


class MSBoardTextView
{
    MinesweeperBoard &view;
public:
    MSBoardTextView(MinesweeperBoard &gameboard);
    void game_display();
};



#endif //MINESWEEPER_MSBOARDTEXTVIEW_H
