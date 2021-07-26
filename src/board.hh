#ifndef _BOARD_H
#define _BOARD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

class Board : public sf::Drawable
{
public:

    Board(sf::Color col1 = sf::Color::White, sf::Color col2 = sf::Color::Black) { load(col1, col2); }
    void load(sf::Color col1 = sf::Color::White, sf::Color col2 = sf::Color::Black);

private:
    std::array<sf::RectangleShape, 64> squares;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
