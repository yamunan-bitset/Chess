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
	  // TODO: mouse event
	}
      window.clear();
      for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	  {
	    switch (board[i][j])
	      {
		// White Figures
	      case 1:
		window.draw(w_rook);
		break;
	      case 2:
		window.draw(w_knight);
		break;
	      case 3:
		window.draw(w_bishop);
		break;
	      case 4:
		window.draw(w_queen);
		break;
	      case 5:
		window.draw(w_king);
		break;
	      case 6:
		window.draw(w_pawn);
		break;
		
		// Black Figures
	      case -1:
		window.draw(b_rook);
		break;
	      case -2:
		window.draw(b_knight);
		break;
	      case -3:
		window.draw(b_bishop);
		break;
	      case -4:
		window.draw(b_queen);
		break;
	      case -5:
		window.draw(b_king);
		break;
	      case -6:
		window.draw(b_pawn);
		break;	      
	      }
	  }

      window.display();
    }
  
  return 0;
}
