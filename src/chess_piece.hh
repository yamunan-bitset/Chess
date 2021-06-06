#ifndef __CHESS__PIECE__HH__
#define __CHESS__PIECE__HH__

#include <Graphics.hpp>

class ChessPiece : public sf::Drawable, public sf::Transformable
{
public:
  ChessPiece(sf::RenderWindow&, const std::string&);
  ChessPiece(ChessPiece&&);
  ChessPiece(const ChessPiece&);
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void move(bool&);

  inline       sf::Sprite   getSprite () const { return this->sprite;              }
  inline const sf::Texture* getTexture() const { return this->sprite.getTexture(); }
  
private:
  sf::RenderWindow& window;
  sf::Texture texture;
  sf::Sprite sprite;
  bool moving;
};

#endif
