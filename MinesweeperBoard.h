//
// Created by dominik on 05.03.19.
//

#ifndef INC_249316_MINESWEEPERBOARD_H
#define INC_249316_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };



struct Field {
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


    int getBoardWidth() const;

    int getBoardHeight() const;

    int getMineCount() const;
void koniec_gry();
    bool sprawdz_czy_wygrana();
    bool sprawdz_czy_min();

    int countMines(int x, int y) ;

    bool hasFlag(int x, int y) const;

    void toggleFlag(int x, int y);

    void revealField(int x, int y);

    bool isRevealed(int x, int y) const;

    GameState getGameState(GameState arg);

    char getFieldInfo(int x, int y) const;
    };


#endif //INC_249316_MINESWEEPERBOARD_H
