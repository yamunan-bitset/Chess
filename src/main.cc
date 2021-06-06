#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <vector>
#include <iostream>

#include "chess_piece.hh"  

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000),"Chess");

#include "figures.hh"

  for (int i = 0; i < pieces.size(); i++)
    {
      /*pieces[i].setOrigin(sf::Vector2f(pieces[i].getTexture()->getSize().x/2,
			  pieces[i].getTexture()->getSize().y/2));
      pieces[i].setScale(sf::Vector2f(0.5f, 0.5f));*/
      pieces[i].setPosition(sf::Vector2f(100*(i % 8) + 50, 
 				        (i < 8 ? 50:(i < 16 ? 150:(i < 24 ? 650:750)))));
    }

  bool moving_piece = false;
  sf::Event event;
  while(window.isOpen())
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
