#include <Graphics.hpp>
#include <Audio.hpp>
#include <string>
#include <array>
#include <vector>

#include "chess_piece.hh"
#include "board.hh"
#include "turn.hh"

extern void Position(ChessPiece&);  // position.cc
extern void Move(ChessPiece);       // coordinate.cc

#include <iostream>

int main(int argc, char** argv)
{
  Turn turn;
  turn.turn_number = 1;
  sf::RenderWindow window(sf::VideoMode(1000, 1000),"Chess");

  sf::SoundBuffer start; // This is the starting sound
  start.loadFromFile("data/sfx/start.wav");
  sf::SoundBuffer move_sfx;
  move_sfx.loadFromFile("data/sfx/move.wav");
  sf::SoundBuffer capture_sfx;
  capture_sfx.loadFromFile("data/sfx/capture.wav");
  
  sf::Sound sound;
  sound.setBuffer(start);
  sound.play();
  
  Board bg;
  
#include "figures.hh"

  for (unsigned int i = 0; i < pieces.size(); i++)
    {
      pieces[i].setScale(sf::Vector2f(1.0f, 1.0f));
      pieces[i].setPosition(sf::Vector2f(125 * (i % 8), 
					 (i < 8 ? 0 : (i < 16 ? 100 : (i < 24 ? 750 : 850)))));
      Position(pieces[i]);
    }

  sound.setBuffer(pieces[0].move_sfx);
  sound.play();
  
  bool restart      = false;
  bool moving_piece = false;
  sf::Event event;
  while(window.isOpen())
    {
      if (restart)
	{
	  turn.turn_number = 1;
	  sound.setBuffer(start);
	  sound.play();
	  pieces.clear();

	  for (unsigned int i = 0; i < b_sprites.size(); i++)
	    pieces.push_back(ChessPiece(window, b_sprites[i]));
	  for (unsigned int i = 0; i < w_sprites.size(); i++)
	    pieces.push_back(ChessPiece(window, w_sprites[i]));

	  for (int i = 0; i < pieces.size(); i++)
	    {
	      pieces[i].setScale(sf::Vector2f(1.0f, 1.0f));
	      pieces[i].setPosition(sf::Vector2f(125*(i % 8), 
						 (i < 8 ? 0:(i < 16 ? 100:(i < 24 ? 750:850)))));
	      Position(pieces[i]);
	    }
	  restart = false;
	}
      while (window.pollEvent(event))
	{
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	    restart = true;
	}
      for (unsigned int i = 0; i < pieces.size(); i++)
	{
	  pieces[i].move(moving_piece);
	  Move(pieces[i]);
	  if (pieces[i].play_sound && !pieces[i].sound_played)
	    {
	      sound.setBuffer(move_sfx);
	      sound.play();
	      pieces[i].sound_played = true;
	    }
	  else continue;
	}

      if (turn == "white") std::cout << "white" << std::endl;
      else if (turn == "black") std::cout << "black" << std::endl;
      
      window.clear();
      window.draw(bg);

      if (!restart)
	for (unsigned int i = 0; i < pieces.size(); i++)
	  {
	    if (pieces[i].delete_sprite && !pieces[i].capture_played)
	      {
		sound.setBuffer(capture_sfx);
		sound.play();
		pieces[i].capture_played = true;
	      }
	    else if (!pieces[i].delete_sprite)
	      window.draw(pieces[i]);
	  }

      window.display();
    }
}
