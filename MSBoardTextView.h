//
// Created by dominik on 26.03.19.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

class MSBoardTextView {
    MinesweeperBoard &view;

public:
    MSBoardTextView(MinesweeperBoard&gameboard);

    void game_display();
};

#endif //SAPER_MSBOARDTEXTVIEW_H
