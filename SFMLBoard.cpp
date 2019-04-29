#include "SFMLBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
 SFMLBoard::SFMLBoard(int width, int height, int lenght)
 {
 board_width=width;
 board_height=height;
 cel_len=lenght;
 }

void SFMLBoard::draw()
{

sf::RenderWindow window(sf::VideoMode(400, 400), "Minesweeper!");

 sf::Music music;
    music.openFromFile("saper_music.ogg");
     music.play();
sf::Texture texture;
if (!texture.loadFromFile("cosmos.png"))
{
   std::cout << "error";
}
sf::RectangleShape rectangle(sf::Vector2f(board_width,board_height));
sf::Texture field;
if (!field.loadFromFile("field.png"));
{
   std::cout << "zielony nie dziala";
}


sf::Sprite sprite;
sprite.setTexture(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        for(int x=1; x<=10; ++x)
            for (int y=1;y<=10; ++y)
        {
        rectangle.setPosition(x*cel_len,y*cel_len);
        rectangle.setTexture(&field);
        window.draw(rectangle);


        }
    window.display();
    }


}

