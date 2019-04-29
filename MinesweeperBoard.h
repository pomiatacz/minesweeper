//
// Created by domin on 15.04.2019.
//

#ifndef MINESWEEPER_MINESWEEPERBOARD_H
#define MINESWEEPER_MINESWEEPERBOARD_H


enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };



struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
    int around;
};


class MinesweeperBoard
{
    Field board[100][100];
    int board_width;
    int board_height;
    GameMode mode;
    GameState state;
    int Minecount=0;
    void set_board();

public:
    MinesweeperBoard();
    MinesweeperBoard(int height, int width, GameMode mode);
    void debug_display();
    int countMines(int x, int y) const;
    void toggleFlag(int x, int y);
    bool hasFlag(int x, int y) const;
    void revealField(int x, int y);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool isRevealed(int x, int y) const;
    GameState getGameState();
    char getFieldInfo(int x, int y) const;
    void choice_gamemode();
    void check_gamestate();
};


#endif //MINESWEEPER_MINESWEEPERBOARD_H//
