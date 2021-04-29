#ifndef __BOARD__HH__
#define __BOARD__HH__

#include <SFML/Graphics.hpp>

class Board : sf::Drawable
{
public:
  Board (sf::Color m_c1, sf::Color m_c2)
    : c1(m_c1), c2(m_c2) { load(c1, c2); } // ctor
  ~Board();                                // dtor
  void load(sf::Color, sf::Color);
private:
  sf::Color c1, c2;
  std::array <sf::RectangleShape, 64> m_boardSquares;
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif
