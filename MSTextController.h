//
// Created by dominik on 02.04.19.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H


#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController {
    MinesweeperBoard &board;
    MSBoardTextView &view;

public:
    MSTextController(MinesweeperBoard&board, MSBoardTextView&view);
    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
