#include "board.hh"

void Board::load(sf::Color col1, sf::Color col2)
{
	for (unsigned i = 0; i < 8; i++)
	{

        	for(unsigned j = 0; j < 8; j++)
		{
	            squares[j + (i * 8)].setPosition(sf::Vector2f(j * 125.0f, i * 125.0f));
        	    squares[j + (i * 8)].setSize(sf::Vector2f(125.0f, 125.0f));
	            squares[j + (i * 8)].setFillColor((((i + j) % 2) == 0) ? col1 : col2);    
	       	}
    	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{ for (unsigned i = 0; i < 64; i++) target.draw(squares[i]);
}
