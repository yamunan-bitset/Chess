#include "board.hh"

void Board::load(sf::Color colour1, sf::Color colour2)
{
  for (int i = 0; i < 8; i++)
  {
    bool tmp_colour = ((i % 2) == 0) ? true : false;
    for (int j = 0; j < 8; j++)
    {
      m_boardSquares[j + (i * 8)].setPosition(sf::Vector2f(j * 64.f, i * 64.f));
      m_boardSquares[j + (i * 8)].setSize(sf::Vector2f(64.f, 64.f));
      m_boardSquares[j + (i * 8)].setFillColor(tmp_colour ? colour1 : colour2);
      tmp_colour = !tmp_colour;
    }
  }  
  return;
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 64; i++)
		target.draw(m_boardSquares[i]);
	return;
}

