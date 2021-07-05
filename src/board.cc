#include "board.hh"

extern void Position(sf::RectangleShape*); // position.cc

Board::Board()
{
  for (unsigned int i = 0; i < 64; i++)
    {
      this->squares[i]->setSize(sf::Vector2f(110, 100));
      this->squares[i]->setPosition(100, 100);
      this->squares[i]->setFillColor(sf::Color::White);
      Position(this->squares[i]);
    }
}

Board::~Board() 
{
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{ for (unsigned int i = 0; i < 64; i++) target.draw(&this->squares[i], state);
}
