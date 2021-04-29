#include "turn.hh"

bool operator == (Turn& turn, char* colour)
{
  if (turn.turn == colour) return true;
}

bool operator != (Turn& turn, char* colour)
{
  return !operator == (turn, colour);
}

