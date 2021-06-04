#include <Graphics.hpp>
#include <array>

int board[8][8] =
  {
#include "board.inc"
  };

int main(int argc, char* argv[])
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");
  
#include "figures.hh"
  
  // MainLoop
  sf::Event event;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed) window.close();
	}
      window.clear();
      for (sf::Sprite i: b_sprites) window.draw(i);
      for (sf::Sprite i: w_sprites) window.draw(i);
      window.display();
    }
  
  return 0;
}
