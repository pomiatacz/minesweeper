//
// Created by dominik on 05.03.19.
//

#include <iostream>
#include "MinesweeperBoard.h"

using namespace std;

MinesweeperBoard::MinesweeperBoard() {

    mode = EASY;

    set_board();
}

MinesweeperBoard::MinesweeperBoard(int height, int width, GameMode gameMode)
{
   mode=gameMode;
   board_height=height;
   board_width = width;



    if(mode == GameMode::DEBUG)
    {
        for(int y=0; y<height; y++)
            for(int x=0; x<width; x++)
            {
                if(x==y)
                    board[x][y].hasMine=1;
                if(y==0)
                    board[x][y].hasMine=1;
                if(x==0 and y%2 == 0)
                    board[x][y].hasMine=1;

            }
    }

    if (mode == GameMode::EASY)
    {
        for (int x = 1; x < 0.1*(height*width);)
        {
            int iks = (rand() % width) + 0; // losowanie współrzędnych
            int igrek = (rand() % height) + 0;

            if (board[iks][igrek].hasMine == 1)
            {
                continue;
            }
            else
            {
                board[iks][igrek].hasMine = 1;
                x++;
            }
            board[iks][igrek].hasMine = 1;
        }

    }

    if(mode == GameMode::NORMAL)
    {


        for (int x = 1; x <0.2*(height*width);)
        {
            int iks = (rand() % width) + 0; // losowanie współrzędnych
            int igrek = (rand() % height) + 0;
            if (board[iks][igrek].hasMine == 1)
            {
                continue;
            } else
            {
                board[iks][igrek].hasMine = 1;
                x++;
            }
            board[iks][igrek].hasMine = 1;

        }
    }
    if (mode == GameMode::HARD)
    {
        for (int x = 0; x < 0.3*(height*width);)
        {
            int iks = (rand() % width) + 0; // losowanie współrzędnych
            int igrek = (rand() % height) + 0;
            if (board[iks][igrek].hasMine == 1)
            {
                continue;
            } else
            {
                board[iks][igrek].hasMine = 1;
                x++;
            }
            board[iks][igrek].hasMine = 1;

        }
    }

}



void MinesweeperBoard::set_board()
{
    for (int y = 0; y <board_height; y++)
    {
        for (int x = 0; x <board_width; x++)
        {
            board[x][y].hasFlag = 0;
            board[x][y].hasMine = 0;
            board[x][y].isRevealed = 0;

        }
    }
}


void MinesweeperBoard::debug_display()
{
    for (int y = 0;y<board_height;y++)
    {
        for (int x = 0;x<board_width;x++)
        {

            cout << '[';
            if (board[x][y].hasMine == true)
            {
                cout << 'M';
            }
            else
            {
                cout << '.';
            }
            if (board[x][y].
                    isRevealed == true
                    )
            {
                cout << 'o';
            }
            else
            {
                cout << '.';
            }
            if (board[x][y].hasFlag == true
                    )
            {
                cout << 'f';
            }
            else
            {
                cout << '.';
            }
            cout << ']';

        }
        cout <<endl;
    }
}


int MinesweeperBoard::countMines(int x, int y)
{
int Minecount=0;

    if (x<0 or y<0)
        return -1;
    if(x>10 or y>10)
        return -1;

    if (board[x][y + 1].hasMine == true)
        Minecount++;
    if (board[x][y - 1].hasMine == true)
        Minecount++;
    if (board[x + 1][y].hasMine == true)
        Minecount++;
    if (board[x - 1][y].hasMine == true)
        Minecount++;
    if (board[x - 1][y - 1].hasMine == true)
        Minecount++;
    if (board[x + 1][y + 1].hasMine == true)
        Minecount++;
    if (board[x + 1][y - 1].hasMine == true)
        Minecount++;
    if (board[x - 1][y + 1].hasMine == true)
        Minecount++;
    board[x][y].around=Minecount;
    cout << Minecount;

}

int MinesweeperBoard::getBoardWidth() const
{
    return board_width;
}

int MinesweeperBoard::getBoardHeight() const {
    return board_height;
}


int MinesweeperBoard::getMineCount() const {
    int minecount = 0;
    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width; x++) {
            if (board[x][y].hasMine == true) {
                minecount++;
            }
        }
    }
    return minecount;
}


bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(board[x][y].hasFlag==1)
        return true;
    if(board[x][y].hasFlag==0)
        return false;
    if(board[x][y].isRevealed==1)
        return false;
    if (x<0 or y<0)
        return false;
    if(x>10 or y>10)
        return false;
}


void MinesweeperBoard::toggleFlag(int x, int y) {
    if (board[x][y].isRevealed == false)
        board[x][y].hasFlag = true;
}


void MinesweeperBoard::revealField(int x, int y) {
    if (board[x][y].isRevealed == false)
        board[x][y].isRevealed = 1;
    if (board[x][y].isRevealed == true and board[x][y].hasMine == true)
    {
        state=GameState::FINISHED_LOSS;
    }
}
bool MinesweeperBoard::isRevealed (int x, int y) const {
    if (board[x][y].isRevealed == 1)
        return true;

}

GameState MinesweeperBoard::getGameState(GameState RUNNING)
{

for(int y=0; y<board_height; y++)
    for(int x=0;x<board_height;x++)
{
    if (board[x][y].isRevealed == true and board[x][y].hasMine == true)
    {
        state=GameState::FINISHED_LOSS;
    }
  else  if (board[x][y].hasFlag == true and board[x][y].hasMine == true )
    {
        state=GameState::FINISHED_WIN;
    }
   else if (board[x][y].isRevealed == false and board[x][y].hasMine == true )
    {
        state=GameState::FINISHED_WIN;
    }
    else
    {
        state=GameState::RUNNING;
    }
}
}


    char MinesweeperBoard::getFieldInfo(int x, int y) const {


        if (board[x][y].isRevealed == 0 and board[x][y].hasFlag == 1)
            return 'F';
        if (board[x][y].isRevealed == 1 and board[x][y].hasFlag == 0)
            return '.';

    }