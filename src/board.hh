#include <Graphics.hpp>

class Board : public sf::Drawable
{
public:
  Board (); // ctor
  ~Board(); // dtor

  inline int getsize_x () const { return this->size_x; }
  inline int getsize_y () const { return this->size_y; }
  
private:
  virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

  int size_x = 125, size_y = 125;

  sf::CircleShape* squares[64];
};
