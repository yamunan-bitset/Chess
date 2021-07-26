#include <vector>
#include <string>

#include <iostream>

#include "chess_piece.hh"

void Capture(std::vector<ChessPiece> pieces)
{
  for (unsigned int i = 0; i < 8; i++)
    for (unsigned int j = 0; j < 8; j++)
      {
	if (pieces[i].getSprite().getPosition().x
	       == pieces[j].getSprite().getPosition().x
	       && pieces[i].getSprite().getPosition().y
	       == pieces[j].getSprite().getPosition().y)
	  pieces[i].delete_sprite = true;
      }
  return;
}
