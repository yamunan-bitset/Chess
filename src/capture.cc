#include <vector>
#include <string>

#include <iostream>

#include "chess_piece.hh"

void Capture(std::vector<ChessPiece> pieces)
{
  for (unsigned int i = 0; i < 8; i++)
    for (unsigned int j = 0; j < 8; j++)
      {
	/*Making sure pieces[i] != pieces[j]*/
	auto pieces_ptr_i = &pieces[i];
	auto pieces_ptr_j = &pieces[j];
	if (pieces_ptr_i == pieces_ptr_j) continue;
	else
	  { std::cout << pieces_ptr_i << ", " << pieces_ptr_j << std::endl;
	    if(pieces[i].getSprite().getPosition().x
	       == pieces[j].getSprite().getPosition().x
	       && pieces[i].getSprite().getPosition().y
	       == pieces[j].getSprite().getPosition().y)
	      {
		pieces[i].delete_sprite = true;
		std::cout << "deleting piece" << std::endl;
	      } else std::cout << pieces[i].getSprite().getPosition().x
			       << ", " << pieces[j].getSprite().getPosition().x
			       << "; " << pieces[i].getSprite().getPosition().y
			       << ", " << pieces[j].getSprite().getPosition().y
			       << std::endl;
	  }
      }
  return;
}
