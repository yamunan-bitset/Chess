#include <Graphics.hpp>
#include <string>

std::string ToNote(sf::Vector2f pos)
{
  std::string s = "";
  s += char(pos.x / 100 + 97);
  s += char(7 - pos.y / 100 + 49);
  return s;
}
