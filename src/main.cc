#include <iostream>
#include <Graphics.hpp>

#include "chess.hh"
#include "board.hh"

int main(int argc, char* argv[])
{
  Chess chess(sf::Color::White, sf::Color::Black);
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess");
  while (window.isOpen())
  {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{std::cout << "Mouse pressed" << std::endl;
				}
			}
		}
		window.draw(chess);
		window.display();
  }
	return 0;
}
