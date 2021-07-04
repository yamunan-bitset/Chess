// This is an indirect copy of
// https://github.com/yadavalu/Chess/blob/master/board.cc

#include "board.hh"

extern void Position(sf::CircleShape*); // position.cc

Board::Board()
{
  for (unsigned int i = 0; i < 64; i++)
    {
      this->squares[i] = new sf::CircleShape(110, 4);
      //      this->squares[i]->setPosition((i % 8) * 100 + 50, ((int) i / 8) * 100 - 50);
      this->squares[i]->setPosition(sf::Vector2f(125 * (i % 8), 
					 (i < 8 ? 0 : (i < 16 ? 100 : (i < 24 ? 750 : 850)))));
      Position(squares[i]);
      this->squares[i]->setRotation(45);
      if (i % 2 == ((int) i / 8) % 2) this->squares[i]->setFillColor(sf::Color(250, 205, 170));
      else this->squares[i]->setFillColor(sf::Color(170, 128, 96));
    }
}

Board::~Board() 
{
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates state) const
{ for (unsigned int i = 0; i < 64; i++) target.draw(*this->squares[i], state);
}
