#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <vector>

#include "chess_piece.hh"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000,500),"Window");
  
#include "figures.hh"

  pieces[0].setPosition(400,400);

  bool moving_piece = false;
  sf::Event event;
  while(true)
    {
      while (window.pollEvent(event))
	if (event.type == sf::Event::Closed)
	  window.close();
      for (unsigned int i = 0; i < pieces.size(); i++)
	pieces[i].move(moving_piece);
      window.clear();
      for (unsigned int i = 0; i < pieces.size(); i++)
	window.draw(pieces[i]);
      window.display();
    }
}
