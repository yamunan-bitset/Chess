#include <Graphics.hpp>
#include <string>

#include "chess_piece.hh"

std::string ToNote(sf::Vector2f pos, ChessPiece piece)
{
  std::string s = "";
  s += (char) (pos.x / piece.getsize_x() + 97);
  s += (char) (7 - pos.y / piece.getsize_y() + 49);
  return s;
}

std::string ToNote(sf::Vector2f pos, ChessPiece* piece)
{
  std::string s = "";
  s += (char) (pos.x / piece->getsize_x() + 97);
  s += (char) (7 - pos.y / piece->getsize_y() + 49);
  return s;
}
