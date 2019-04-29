//
// Created by domin on 15.04.2019.
//
#include <iostream>
#include "MinesweeperBoard.h"
using namespace std;


MinesweeperBoard::MinesweeperBoard()
{
    board_height=10;
    board_width=10;
    mode = DEBUG;
    state=RUNNING;
    choice_gamemode();


}

MinesweeperBoard::MinesweeperBoard(int height, int width, GameMode gameMode)
{

    board_height=height;
    board_width = width;
    mode=gameMode;
    state=RUNNING;
    choice_gamemode();



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

void MinesweeperBoard::choice_gamemode()
{
    if(mode == GameMode::DEBUG)
    {
        for(int y=0; y<board_height; y++)
            for(int x=0; x<board_width; x++)
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
        for (int x = 1; x < 0.1*(board_height*board_width);)
        {
            int idx = (rand() % board_width) + 0; // losowanie wspó³rzêdnych
            int idy = (rand() % board_height) + 0;

            if (board[idx][idy].hasMine == 1)
            {
                continue;
            }
            else
            {
                board[idx][idy].hasMine = 1;
                x++;
            }
            board[idx][idy].hasMine = 1;
        }

    }

    if(mode == GameMode::NORMAL)
    {


        for (int x = 1; x <0.2*(board_width*board_height);)
        {
            int idx = (rand() % board_width) + 0; // losowanie wspó³rzêdnych
            int idy = (rand() % board_height) + 0;
            if (board[idx][idy].hasMine == 1) continue;
            else
            {
                board[idx][idy].hasMine = 1;
                x++;
            }
            board[idx][idy].hasMine = 1;

        }
    }
    if (mode == GameMode::HARD)
    {
        for (int x = 0; x < 0.3*(board_height*board_height);)
        {
            int idx = (rand() % board_width) + 0; // losowanie wspó³rzêdnych
            int idy = (rand() % board_height) + 0;
            if (board[idx][idy].hasMine == 1) continue;
            else
            {
                board[idx][idy].hasMine = 1;
                x++;
            }
            board[idx][idy].hasMine = 1;

        }
    }
}

int MinesweeperBoard::countMines(int x, int y) const
{
    int count_x_start, count_x_end,count_y_start, count_y_end;
    if(x==0){count_x_start=x;count_x_end=x+2;}
    else if(x==board_width-1){count_x_start=x-1; count_x_end=x;}
    else {count_x_start=x-1; count_x_end=x+2;}
    if(y==0){count_y_start=y; count_y_end=y+2;}
    else if(y==board_height-1){count_y_start=y-1; count_y_end=y;}
    else {count_y_start=y-1; count_y_end=y+2;}
    int mines_count = 0;
    for (int cy = count_y_start; cy < count_y_end; cy++) {
        for (int cx = count_x_start; cx < count_x_end; cx++) {
            if (board[cx][cy].hasMine == true) { mines_count++; }
        }
    }
    if (board[x][y].hasMine == true) { mines_count = mines_count - 1; }
    return mines_count;
}

//int MinesweeperBoard::countMines(int x, int y)
//{
//    int Minecount=0;
//
//    if (x<0 or y<0)
//        return -1;
//    if(x>10 or y>10)
//        return -1;
//
//    if (board[x][y + 1].hasMine == true)
//        Minecount++;
//    if (board[x][y - 1].hasMine == true)
//        Minecount++;
//    if (board[x + 1][y].hasMine == true)
//        Minecount++;
//    if (board[x - 1][y].hasMine == true)
//        Minecount++;
//    if (board[x - 1][y - 1].hasMine == true)
//        Minecount++;
//    if (board[x + 1][y + 1].hasMine == true)
//        Minecount++;
//    if (board[x + 1][y - 1].hasMine == true)
//        Minecount++;
//    if (board[x - 1][y + 1].hasMine == true)
//        Minecount++;
//    board[x][y].around=Minecount;
//    cout << Minecount;
//
//}

int MinesweeperBoard::getBoardWidth() const
{
    return board_width;
}

int MinesweeperBoard::getBoardHeight() const
{
    return board_height;
}


int MinesweeperBoard::getMineCount() const
{
    int minecount = 0;
    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (board[x][y].hasMine == true) minecount++;
        }
    }
    return minecount;
}

bool MinesweeperBoard::isRevealed (int x, int y) const
{
    if (board[x][y].isRevealed == 1)
        return true;

}


void MinesweeperBoard::toggleFlag(int x, int y)
{
    if (board[x][y].isRevealed == false)
        board[x][y].hasFlag = true;
}


void MinesweeperBoard::revealField(int x, int y)
{

    if (board[x][y].isRevealed == true)
    { cout << "Pole jest juz odkryte! Wybierz inne" << endl; }
     if (x < 0 || y > board_width || x < 0 || y > board_height)
     {
        cout << "Pole jest poza plansza!" << endl;
    }
     else if (state == FINISHED_WIN || state == FINISHED_LOSS)
     { cout << "Gra jest zakonczona" << endl; }
    else if (board[x][y].hasFlag == true)
    { cout << "Na tym polu jest juz postawiona flaga" << endl; }
    else if (board[x][y].isRevealed == false && board[x][y].hasMine == false)
    {
        board[x][y].isRevealed = true;
    }
    else if (board[x][y].isRevealed == false && board[x][y].hasMine == true)
    {
        board[x][y].isRevealed = true;
        state == FINISHED_LOSS;
    }
}

bool MinesweeperBoard::hasFlag(int x, int y) const
{
    if(board[x][y].hasFlag==true)
        return true;
    if(board[x][y].hasFlag==false)
        return false;
    if(board[x][y].isRevealed==false)
        return false;
    if (x<0 or y<0)
        return false;
    if(x>board_width or y>board_height)
        return false;
}





void MinesweeperBoard::check_gamestate() {
    for(int x=0;x<board_width;x++)
    {
        for(int y=0;y<board_height;y++)
        {
            if(board[x][y].hasMine==true&&board[x][y].isRevealed==true){state=FINISHED_LOSS;}
            else if(board[x][y].hasMine==true&&board[x][y].hasFlag==true){state=FINISHED_WIN;}
        }
    }
}


GameState MinesweeperBoard::getGameState()
{
    return state;
}


char MinesweeperBoard::getFieldInfo(int x, int y) const {
    int idx_x, idx_y;
    idx_x = x;
    idx_y = y;
    if (idx_x < 0 && idx_x > board_width && idx_y < 0 && idx_y < board_height) { return '#'; }
    else if (board[idx_x][idx_y].isRevealed == false && board[idx_x][idx_y].hasFlag== true) { return 'F'; }
    else if (board[idx_x][idx_y].isRevealed == false && board[idx_x][idx_y].hasMine == false) { return '_'; }
    else if (board[idx_x][idx_y].isRevealed == false && board[idx_x][idx_y].hasMine == true) {return '_';}
    else if (board[idx_x][idx_y].isRevealed == true && board[idx_x][idx_y].hasMine == true) { return 'x'; }
    else if (board[idx_x][idx_y].isRevealed == true) {
        int count_mines = countMines(idx_x, idx_y);
        if (count_mines == 0) { return ' '; }
        else if (count_mines == 1) { return '1'; }
        else if (count_mines == 2) { return '2'; }
        else if (count_mines == 3) { return '3'; }
        else if (count_mines == 4) { return '4'; }
        else if (count_mines == 5) { return '5'; }
        else if (count_mines == 6) { return '6'; }
        else if (count_mines == 7) { return '7'; }
        else if (count_mines == 8) { return '8'; }

}
    }
