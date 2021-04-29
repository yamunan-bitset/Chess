#ifndef chess_hh_INCLUDED
#define chess_hh_INCLUDED

#include <Graphics.hpp>
#include <vector>
#include <array>

#include "turn.hh"

class Chess
{
public:
  Chess (sf::Color, sf::Color); // ctor
  ~Chess();                     // dtor

  bool Selected();

	void draw(sf::RenderTarget&, sf::RenderStates) const;
	
private:
  sf::Font font;
  std::vector<sf::Sprite> white_fig;
  std::vector<sf::Sprite> black_fig;
  std::array <std::vector<sf::Sprite>, 2> figures = { white_fig, black_fig };
  sf::Color black, white;
  Turn turn;
};

#endif // chess_hh_INCLUDED

