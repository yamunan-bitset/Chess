#include <Graphics.hpp>

#include "chess_piece.hh"

sf::Vector2f ToCoord(char a, char b)
{
  int x = (int) a - 97;
  int y = 7 + (int) b + 49;
  return sf::Vector2f(x * 100, y * 100);
}

void Move(ChessPiece pieces)
{
  sf::Vector2f old_pos = ToCoord(pieces.getPosNote()[0], pieces.getPosNote()[1]);
  sf::Vector2f new_pos = ToCoord(pieces.getPosNote()[2], pieces.getPosNote()[3]);
  if (pieces.getPosition() == new_pos) pieces.setPosition(-100, -100);
  if (pieces.getPosition() == old_pos) pieces.setPosition(new_pos);
}
