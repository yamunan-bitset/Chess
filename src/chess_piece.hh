#ifndef __CHESS__PIECE__HH__
#define __CHESS__PIECE__HH__

#include <Graphics.hpp>
#include <Audio.hpp>
#include <string>

#include "turn.hh"

class ChessPiece : public sf::Drawable, public sf::Transformable
{
public:
  ChessPiece (sf::RenderWindow&, const std::string&);
  ChessPiece (ChessPiece&&);
  ChessPiece (const ChessPiece&);
  ~ChessPiece();
  
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void move(bool&);

  inline       sf::Sprite   getSprite () const { return this->sprite;              }
  inline const sf::Texture* getTexture() const { return this->sprite.getTexture(); }
  inline                int getsize_x () const { return this->size_x;              }
  inline                int getsize_y () const { return this->size_y;              }
  inline        std::string getPosNote() const { return this->pos_note;            }
  
  bool delete_sprite = false, play_sound = false, sound_played = false, just_played = false;
  
  sf::SoundBuffer move_sfx;
  
  Turn turn;
 
private:
  sf::RenderWindow& window;
  sf::Vector2f old_pos, new_pos;
  std::string pos_note;
  sf::Texture texture;
  sf::Sprite sprite;
  bool moving;
  int size_x = 125, size_y = 125;
};

#endif
