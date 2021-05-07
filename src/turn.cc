#include "turn.hh"

bool operator == (Turn& turn, char* colour)
{
  if (turn.turn == colour) return true;
}

bool operator != (Turn& turn, char* colour)
{
  return !operator == (turn, colour);
}

bool operator == (Turn& turn, int number)
{
  if (turn.turn_number == number) return true;
}

bool operator != (Turn& turn, int number)
{
  return !operator == (turn, number);
}

