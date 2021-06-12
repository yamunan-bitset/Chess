#include "chess_piece.hh"

ChessPiece::ChessPiece(sf::RenderWindow& windowRef, const std::string& file_name) : window(windowRef)
{
  if (!texture.loadFromFile(file_name)) exit(-1);
  this->sprite.setTexture(this->texture);
  this->moving = false;
  this->sprite.setScale(128 / this->sprite.getGlobalBounds().width,
			128 / this->sprite.getGlobalBounds().height);
}

ChessPiece::ChessPiece(ChessPiece&& rval) : window(rval.window)
{
  this->texture = std::move(rval.texture);
  this->sprite.setTexture(this->texture);
  this->sprite.setScale(rval.sprite.getScale());
  this->moving = std::move(rval.moving);
}

ChessPiece::ChessPiece(const ChessPiece& lval): window(lval.window)
{
  this->texture = lval.texture;
  this->sprite.setTexture(this->texture);
  this->sprite.setScale(lval.sprite.getScale());
  this->moving = lval.moving;
}

void ChessPiece::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform *= this->getTransform();
  target.draw(this->sprite,states);
}

void ChessPiece::move(bool& moving_piece)
{
  sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
  if (this->moving)
    {
      this->setPosition(mouse_pos.x - this->sprite.getGlobalBounds().width  / 2,
			mouse_pos.y - this->sprite.getGlobalBounds().height / 2);
      if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{ // Left Button Released
	  this->moving = false;
	  moving_piece = false;
	  sf::Vector2f p = this->getPosition()
	    + sf::Vector2f(this->size_x / 2, this->size_y / 2);
	  sf::Vector2f new_pos = sf::Vector2f(this->size_x * int(p.x / this->size_x),
					      this->size_y * int(p.y / this->size_y));
	  this->setPosition(new_pos);
	}
    }
  else
    {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
	  mouse_pos.x > this->getPosition().x &&
	  mouse_pos.y > this->getPosition().y &&
	  mouse_pos.x < this->getPosition().x + this->sprite.getGlobalBounds().width &&
	  mouse_pos.y < this->getPosition().y + this->sprite.getGlobalBounds().height &&
	  !moving_piece)
	{ // Left Button Pressed
	  this->moving = true;
	  moving_piece = true;
	}
      else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) &&
	       mouse_pos.x > this->getPosition().x &&
	       mouse_pos.y > this->getPosition().y &&
	       mouse_pos.x < this->getPosition().x + this->sprite.getGlobalBounds().width &&
	       mouse_pos.y < this->getPosition().y + this->sprite.getGlobalBounds().height &&
	       !moving_piece) this->delete_sprite = true; // Right Button Pressed, then delete figure
    }
}
