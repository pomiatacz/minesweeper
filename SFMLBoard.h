#ifndef SFMLBOARD_H
#define SFMLBOARD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class SFMLBoard
{

    int board_height;
    int board_width;
    int cel_len;
public:
    SFMLBoard(int width, int height, int length);
    void draw();
};


#endif // SFMLBOARD_H
