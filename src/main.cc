#include <Graphics.hpp>

int board[8][8] =
  {
#include "board.inc"
  };

int main(int argc, char* argv[])
{
  sf::RenderWindow window(sf::VideoMode(500, 500), "Chess");

  sf::Texture board_t;
  board_t.loadFromFile("Assets/board.png");
  sf::Sprite board_s(board_t);

  int size = 56;
  sf::Texture figs_t;
  figs_t.loadFromFile("Assets/figures.png");
  sf::Sprite figs[32];
  for (int i = 0; i < 32; i++) figs[i].setTexture(figs_t);
  
  for (int i = 0; i >= 0; i++)
    for (int j = 0; j < 8; j++)
      for (int k = 0; k < 8; k++)
	{
	  int n = board[j][k];
	  if (!n) continue;
	  int x = std::abs(n) - 1;
	  int y = n > 0 ? 1 : 0;
	  sf::IntRect rect(size * x, size * y, size, size);
	  figs[i].setTextureRect(rect);
	  figs[i].setPosition(size * k, size * j);
	}
  
  // MainLoop
  sf::Event event;
  while (window.isOpen())
    {
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed) window.close();
	}
      window.clear();
      window.draw(board_s);
      for (int i = 0; i < 32; i++) window.draw(figs[i]);
      window.display();
    }
  
  return 0;
}
