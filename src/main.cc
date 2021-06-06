#include <SFML/Graphics.hpp>
#include <string>
#include <array>
#include <vector>

#include "chess_piece.hh"  

int main(int argc, char** argv)
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000),"Chess");

  sf::Texture bg_t;
  bg_t.loadFromFile("Assets/board.png");
  sf::Sprite bg(bg_t);
  bg.setScale(1.25f, 1.25f);

#include "figures.hh"

  for (int i = 0; i < pieces.size(); i++)
    {
      pieces[i].setScale(sf::Vector2f(1.0f, 1.0f));
      pieces[i].setPosition(sf::Vector2f(125*(i % 8), 
 				        (i < 8 ? 0:(i < 16 ? 100:(i < 24 ? 750:850)))));
    }

  bool restart      = false;
  bool moving_piece = false;
  sf::Event event;
  while(window.isOpen())
    {
      if (restart)
	{
#include "reinit_pieces.hh"
	  for (int i = 0; i < pieces.size(); i++)
	    {
	      pieces[i].setScale(sf::Vector2f(1.0f, 1.0f));
	      pieces[i].setPosition(sf::Vector2f(125*(i % 8), 
						 (i < 8 ? 0:(i < 16 ? 100:(i < 24 ? 750:850)))));
	    }
	  restart  = false;
	}
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	    restart = true;
	}
      for (unsigned int i = 0; i < pieces.size(); i++)
	pieces[i].move(moving_piece);

      window.clear();

      window.draw(bg);
      
      if (!restart)
	for (unsigned int i = 0; i < pieces.size(); i++)
	  {
	    if (!pieces[i].delete_sprite)
	      window.draw(pieces[i]);
	  }
	        
      window.display();
    }
}
